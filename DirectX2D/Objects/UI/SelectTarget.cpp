#include "Framework.h"

SelectTarget::SelectTarget()
{
	rectsize = new RectCollider({1,1});
	rectsize->Pos() = MOUSE + Vector2(10000, 10000);

	//attsize = new RectCollider({ 1,1 });

	ttt = new Quad(L"Textures/UI_IMAGE/UI_Image_Select.png");
}
SelectTarget::~SelectTarget()
{
	delete rectsize;
	delete ttt;
	//delete attsize;
}

void SelectTarget::Update()
{
	SelecteTargetmouseDrag();
	//attsize->UpdateWorld();
	
	rectsize->UpdateWorld();
	//ttt->UpdateWorld();

	rectsize->Pos() = MOUSE;
}
void SelectTarget::Render()
{
	rectsize->Render();
	//attsize->Render();
	//ttt->Render();
}

void SelectTarget::PostRender()
{
	//ttt->RenderUI();
}
void SelectTarget::select()
{
	if (KEY_DOWN(VK_LBUTTON))
	{
		ttt->Pos() = MOUSE;
	}
	
	if (KEY_PRESS(VK_LBUTTON))
	{
		if (!firstValue)
		{
			first = mousePos;
			firstValue = true;
		}
	
		ttt->Scale() = (mousePos / first);
	}

	if (KEY_UP(VK_LBUTTON))
	{
		firstValue = false;
	}
}

void SelectTarget::SelecteTargetmouseDrag()
{
	
}