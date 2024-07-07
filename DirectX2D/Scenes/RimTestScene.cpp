#include "Framework.h"
#include "RimTestScene.h"

RimTestScene::RimTestScene()
{
	srand(GetTickCount64());
	gameTileMap = new QTileEditMap(31, 31); // 타일 씬에서 만든 결과 맵 쓰기

	float ats = 35.0f;

	CM->Jobduqn();
	this->rim1 = CM->rim1;
	this->rim2 = CM->rim2;
	this->rim3 = CM->rim3;
	this->rim4 = CM->rim4;

	SELETCtile = new Quad(L"Textures/UI_IMAGE/TileSelect.png");
	SELETCtile->SetActive(false);

	for (int i = 0; i < gameTileMap->bgTiles.size(); ++i)
	{
		pair<int, string> dlatl;

		if (gameTileMap->bgTiles[i]->savetype == QTile::FOOD)
		{
			dlatl.first = i;
			dlatl.second = "FOOD";
			CM->Builddatas.push_back(dlatl);
		}
		else if (gameTileMap->bgTiles[i]->savetype == QTile::WOOD)
		{
			dlatl.first = i;
			dlatl.second = "WOOD";
			CM->Builddatas.push_back(dlatl);
		}
	}
	CM->TileDataSet();

	int rim1pos = Random(0, 900);
	for (int i = 0; i < CM->Builddatas.size(); ++i)
	{
		if (rim1pos == CM->Builddatas[i].first)
			rim1pos = Random(0, 900);
	}

	int rim2pos = Random(0, 900);
	for (int i = 0; i < CM->Builddatas.size(); ++i)
	{
		if (rim2pos == CM->Builddatas[i].first)
			rim2pos = Random(0, 900);
	}

	int rim3pos = Random(0, 900);
	for (int i = 0; i < CM->Builddatas.size(); ++i)
	{
		if (rim3pos == CM->Builddatas[i].first)
			rim3pos = Random(0, 900);
	}

	int rim4pos = Random(0, 900);
	for (int i = 0; i < CM->Builddatas.size(); ++i)
	{
		if (rim4pos == CM->Builddatas[i].first)
			rim4pos = Random(0, 900);
	}

	rim1->Pos() = gameTileMap->bgTiles[rim1pos]->Pos();
	rim2->Pos() = gameTileMap->bgTiles[rim2pos]->Pos();
	rim3->Pos() = gameTileMap->bgTiles[rim3pos]->Pos();
	rim4->Pos() = gameTileMap->bgTiles[rim4pos]->Pos();

	rim1->Mytile = rim1pos;
	rim2->Mytile = rim2pos;
	rim3->Mytile = rim3pos;
	rim4->Mytile = rim4pos;

	selecttarget = new SelectTarget();
	selecttarget->Update();

	UIS->SetCollider(selecttarget->rectsize);

	BackGorund = new Quad(L"Textures/BackG.png");
	BackGorund->Scale() = Vector2(30, 30);
	BackGorund->Pos() = gameTileMap->bgTiles[480]->Pos();
	BackGorund->UpdateWorld();
}
RimTestScene::~RimTestScene()
{
	delete gameTileMap;

	delete rim1;
	delete rim2;
	delete rim3;
	delete rim4;
	delete selecttarget;
	delete BackGorund;
	delete SELETCtile;
}

void RimTestScene::Update()
{
	UIS->SELETCtileintDAta = -1;
	CM->tiledatapos = gameTileMap->bgTiles;

	gameTileMap->Update();
	

	if (UIS->SELETCtileintDAta == -1)
	{
		SELETCtile->SetActive(false);
	}
	else
	{
		SELETCtile->SetActive(true);
	}

	CM->Update();
	selecttarget->Update();

	if (SELETCtile->Active())
	{
		SELETCtile->Pos() = gameTileMap->bgTiles[UIS->SELETCtileintDAta]->Pos();
		SELETCtile->UpdateWorld();
	}

	// 림 선택 관련
	RimsSelect();

	// 카메라 움직임
	CemeraMoving();

	RimMove();

	{
		// 림들의 이동 코드
		if (KEY_DOWN(VK_RBUTTON) && rim1->meselect)
		{
			int end = gameTileMap->FindCloseNode(MOUSE);
			gameTileMap->GetPath(rim1->Mytile, end, rim1->GetPath());
		}
		if (KEY_DOWN(VK_RBUTTON) && rim2->meselect)
		{
			int end = gameTileMap->FindCloseNode(MOUSE);
			gameTileMap->GetPath(rim2->Mytile, end, rim2->GetPath());
		}
		if (KEY_DOWN(VK_RBUTTON) && rim3->meselect)
		{
			int end = gameTileMap->FindCloseNode(MOUSE);
			gameTileMap->GetPath(rim3->Mytile, end, rim3->GetPath());
		}
		if (KEY_DOWN(VK_RBUTTON) && rim4->meselect)
		{
			int end = gameTileMap->FindCloseNode(MOUSE);
			gameTileMap->GetPath(rim4->Mytile, end, rim4->GetPath());
		}
	}
}
void RimTestScene::Render()
{
	BackGorund->Render();

	gameTileMap->Render();
	CM->Render();

	selecttarget->Render();

	if (SELETCtile->Active()) SELETCtile->Render();
}
void RimTestScene::PostRender()
{
	// selecttarget->PostRender();

	CM->PostRender();

	//string aaa = to_string(SELETCtile->Pos().x);
	//ImGui::Text(aaa.c_str());
}

void RimTestScene::CemeraMoving()
{
	// 키 다운시 해당 림이 있는 곳으로 즉시 카메라 이동
	if (KEY_DOWN(VK_F1)) CAMERA->SetTarget(rim1);
	if (KEY_DOWN(VK_F2)) CAMERA->SetTarget(rim2);
	if (KEY_DOWN(VK_F3)) CAMERA->SetTarget(rim3);
	if (KEY_DOWN(VK_F4)) CAMERA->SetTarget(rim4);

	// 키가 업이 될 때, 카메라 자유모드로 전환
	if (KEY_UP(VK_F1)) CAMERA->SetTarget(nullptr);
	if (KEY_UP(VK_F2)) CAMERA->SetTarget(nullptr);
	if (KEY_UP(VK_F3)) CAMERA->SetTarget(nullptr);
	if (KEY_UP(VK_F4)) CAMERA->SetTarget(nullptr);
}

void RimTestScene::RimsSelect()
{
	// 해당 림 선택
	if (KEY_DOWN(VK_LBUTTON) || UIS->UI_BTN[18]->GetDown001() || UIS->UI_BTN[19]->GetDown001() || UIS->UI_BTN[20]->GetDown001() || UIS->UI_BTN[21]->GetDown001())
	{
		if (selecttarget->Getcollider()->IsCollision(rim1->cirlce) || UIS->UI_BTN[18]->GetDown001())
		{
			UIS->SetTarget(rim1, 1);
			UIS->characterIN = true;
			rim1->meselect = true;
			UIS->UI_BTN[18]->SetDown001(true);
		}
		else if (selecttarget->Getcollider()->IsCollision(rim2->cirlce) || UIS->UI_BTN[19]->GetDown001())
		{
			UIS->SetTarget(rim2, 2);
			UIS->characterIN = true;
			rim2->meselect = true;
			UIS->UI_BTN[19]->SetDown001(true);
		}
		else if (selecttarget->Getcollider()->IsCollision(rim3->cirlce) || UIS->UI_BTN[20]->GetDown001())
		{
			UIS->SetTarget(rim3, 3);
			UIS->characterIN = true;
			rim3->meselect = true;
			UIS->UI_BTN[20]->SetDown001(true);
		}
		else if (selecttarget->Getcollider()->IsCollision(rim4->cirlce) || UIS->UI_BTN[21]->GetDown001())
		{
			UIS->SetTarget(rim4, 4);
			UIS->characterIN = true;
			rim4->meselect = true;
			UIS->UI_BTN[21]->SetDown001(true);
		}
	}

	if (KEY_DOWN(VK_LBUTTON))
	{
		UIS->characterIN = false;
	}

	/*
	if (KEY_PRESS(VK_LBUTTON))
	{
		PressTime -= DELTA;

		if (PressTime <= 0)
		{
			if (selecttarget->Getcollider()->IsCollision(rim1->cirlce))
			{
				// 현재 카메라가 가지고 있는 선택된 림의 값이 충돌된 값의 림과 같다면
				// 선택된 림의 정보값을 널로 변경 (이하동)
				if (UIS->GetRim() == rim1)
				{
					UIS->SetTarget(nullptr, 1);
				}
				rim1->meselect = true;
				UIS->SelectRim1 = true;
			}
			if (selecttarget->Getcollider()->IsCollision(rim2->cirlce))
			{
				if (UIS->GetRim() == rim2)
				{
					UIS->SetTarget(nullptr, 2);
				}
				rim2->meselect = true;
				UIS->SelectRim2 = true;
			}
			if (selecttarget->Getcollider()->IsCollision(rim3->cirlce))
			{
				if (UIS->GetRim() == rim3)
				{
					UIS->SetTarget(nullptr, 3);
				}
				rim3->meselect = true;
				UIS->SelectRim3 = true;
			}
			if (selecttarget->Getcollider()->IsCollision(rim4->cirlce))
			{
				if (UIS->GetRim() == rim4)
				{
					UIS->SetTarget(nullptr, 4);
				}
				rim4->meselect = true;
				UIS->SelectRim4 = true;
			}
		}
	}
	*/

	if (KEY_UP(VK_LBUTTON)) PressTime = max_PressTime;
	if (KEY_DOWN(VK_ESCAPE))
	{
		UIS->SetTarget(nullptr, 5);

		rim1->meselect = false;
		rim2->meselect = false;
		rim3->meselect = false;
		rim4->meselect = false;

		for (int i = 0; i < UIS->UI_BTN.size(); ++i)
		{
			UIS->UI_BTN[i]->SetDown001(false);
		}
	}

	UIS->stc[0]->InputChange(rim1);
	UIS->stc[1]->InputChange(rim2);
	UIS->stc[2]->InputChange(rim3);
	UIS->stc[3]->InputChange(rim4);
}

void RimTestScene::RimMove()
{
	if (rim1->moving)
	{
		gameTileMap->GetPath(rim1->Mytile, rim1->EndTile, rim1->GetPath());
		rim1->moving = false;
	}
	if (rim2->moving)
	{
		gameTileMap->GetPath(rim2->Mytile, rim2->EndTile, rim2->GetPath());
		rim2->moving = false;
	}
	if (rim3->moving)
	{
		gameTileMap->GetPath(rim3->Mytile, rim3->EndTile, rim3->GetPath());
		rim3->moving = false;
	}
	if (rim4->moving)
	{
		gameTileMap->GetPath(rim4->Mytile, rim4->EndTile, rim4->GetPath());
		rim4->moving = false;
	}
}