#include "Framework.h"

Button::Button(wstring textureFile)
    : Quad(textureFile)
{
    collider = new RectCollider(size);
    collider->SetParent(this);
}

Button::Button(Vector2 size)
    : Quad(size)
{
    collider = new RectCollider(size);
    collider->SetParent(this);
}

Button::~Button()
{
    delete collider;
}

void Button::Update()
{

    if (!isActive) return;

    if (collider->IsPointCollision(MOUSE))
    {
        if (KEY_DOWN(VK_LBUTTON))
        {
            isDownCheck = true;
            if (!isDownCheck001)
            {
                isDownCheck001 = true;
            }
            else if (isDownCheck001 = false)
            {
                isDownCheck001 = false;
            }
            
        }

        if (KEY_PRESS(VK_LBUTTON))
            state = DOWN;
        else
            state = OVER;

        if (isDownCheck && KEY_UP(VK_LBUTTON))
        {
            if (event != nullptr)
                event();

            if (paramEvent != nullptr)
                paramEvent(object);

            isDownCheck = false;
        }
    }
    else
    {
        state = NONE;

        if (KEY_UP(VK_LBUTTON))
            isDownCheck = false;
    }

    if (isDownCheck001)
    {
        state = OVERING;
    }

    switch (state)
    {
    case Button::NONE:
        colorBuffer->Get() = NONE_COLOR;
        break;
    case Button::DOWN:
        colorBuffer->Get() = DOWN_COLOR;
        break;
    case Button::OVER:
        colorBuffer->Get() = OVER_COLOR;
        break;
    case Button::OVERING:
        colorBuffer->Get() = OVERRING_COLOR;
        break;    
    }

    UpdateWorld();
    collider->UpdateWorld();
}

void Button::Render()
{
    if (!isActive) return;

    Quad::Render();
    //collider->Render();
}
