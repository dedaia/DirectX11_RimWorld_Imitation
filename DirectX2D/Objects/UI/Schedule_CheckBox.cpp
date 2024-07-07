#include "Framework.h"

Schedule_CheckBox::Schedule_CheckBox(Vector2 pos)
{
	btn_checkbox.push_back(new Button(L"Textures/clear.png")); // 0
	btn_checkbox.push_back(new Button(L"Textures/clear.png")); // 1
	btn_checkbox.push_back(new Button(L"Textures/clear.png")); // 2
	btn_checkbox.push_back(new Button(L"Textures/clear.png")); // 3
	btn_checkbox.push_back(new Button(L"Textures/clear.png")); // 4
	btn_checkbox.push_back(new Button(L"Textures/clear.png")); // 5
	btn_checkbox.push_back(new Button(L"Textures/clear.png")); // 6

	float scale = 0.25f;
	btn_checkbox[0]->Scale() = { scale,scale };
	btn_checkbox[1]->Scale() = { scale,scale };
	btn_checkbox[2]->Scale() = { scale,scale };
	btn_checkbox[3]->Scale() = { scale,scale };
	btn_checkbox[4]->Scale() = { scale,scale };
	btn_checkbox[5]->Scale() = { scale,scale };
	btn_checkbox[6]->Scale() = { scale,scale };

	btn_checkbox[0]->Pos() = pos;
	btn_checkbox[1]->Pos() = pos + Vector2(50, 0);
	btn_checkbox[2]->Pos() = pos + Vector2(100, 0);
	btn_checkbox[3]->Pos() = pos + Vector2(150, 0);
	btn_checkbox[4]->Pos() = pos + Vector2(200, 0);
	btn_checkbox[5]->Pos() = pos + Vector2(250, 0);
	btn_checkbox[6]->Pos() = pos + Vector2(300, 0);

	btn_checkbox[0]->SetDown001(true);
	btn_checkbox[1]->SetDown001(true);
	btn_checkbox[2]->SetDown001(true);
	btn_checkbox[3]->SetDown001(true);
	btn_checkbox[4]->SetDown001(true);
	btn_checkbox[5]->SetDown001(true);
	btn_checkbox[6]->SetDown001(true);
}
Schedule_CheckBox::~Schedule_CheckBox()
{
	for (Button* btn : btn_checkbox)
		delete btn;
}

void Schedule_CheckBox::Update()
{
	for (Button* btn : btn_checkbox)
		btn->Update();
}
void Schedule_CheckBox::Render()
{
	for (Button* btn : btn_checkbox)
		btn->Render();
}

void Schedule_CheckBox::Setpa(Transform* aaa)
{
	for (Button* btn : btn_checkbox)
		btn->SetParent(aaa);
}

void Schedule_CheckBox::SetBOOL(class RimCharacter* rim)
{
	rim->scheDule = btn_checkbox;
}