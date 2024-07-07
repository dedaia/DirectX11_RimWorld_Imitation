#include "Framework.h"

UI_Scene::UI_Scene()
{

	// 하단 UI (0 ~ 8) 총 9개
	UI_BTN.push_back(new Button(L"Textures/UI_IMAGE/UI_Image_01.png")); // 0
	UI_BTN.push_back(new Button(L"Textures/UI_IMAGE/UI_Image_02.png")); // 1
	UI_BTN.push_back(new Button(L"Textures/UI_IMAGE/UI_Image_03.png")); // 2
	UI_BTN.push_back(new Button(L"Textures/UI_IMAGE/UI_Image_04.png")); // 3
	UI_BTN.push_back(new Button(L"Textures/UI_IMAGE/UI_Image_05.png")); // 4
	UI_BTN.push_back(new Button(L"Textures/UI_IMAGE/UI_Image_06.png")); // 5
	UI_BTN.push_back(new Button(L"Textures/UI_IMAGE/UI_Image_07.png")); // 6
	UI_BTN.push_back(new Button(L"Textures/UI_IMAGE/UI_Image_08.png")); // 7
	UI_BTN.push_back(new Button(L"Textures/UI_IMAGE/UI_Image_09.png")); // 8

	// 구상의 건축, 구역, 바닥 3개 UI (9 ~ 11) 총 3개
	UI_BTN.push_back(new Button(L"Textures/UI_IMAGE/UI_Image_01_01.png")); // 9
	UI_BTN.push_back(new Button(L"Textures/UI_IMAGE/UI_Image_01_02.png")); // 10
	UI_BTN.push_back(new Button(L"Textures/UI_IMAGE/UI_Image_01_03.png")); // 11

	// 캐릭터 정보 UI 버튼 (12 ~ 17) 총 6개
	UI_BTN.push_back(new Button(L"Textures/UI_IMAGE/UI_Image_char_01.png")); // 12
	UI_BTN.push_back(new Button(L"Textures/UI_IMAGE/UI_Image_char_02.png")); // 13
	UI_BTN.push_back(new Button(L"Textures/UI_IMAGE/UI_Image_char_03.png")); // 14
	UI_BTN.push_back(new Button(L"Textures/UI_IMAGE/UI_Image_char_04.png")); // 15
	UI_BTN.push_back(new Button(L"Textures/UI_IMAGE/UI_Image_char_05.png")); // 16
	UI_BTN.push_back(new Button(L"Textures/UI_IMAGE/UI_Image_char_06.png")); // 17

	// 캐릭터 선택 버튼 (18 ~ 21) 총 4개
	UI_BTN.push_back(new Button(L"Textures/Tile/Characters/green_character.png"));	// 18
	UI_BTN.push_back(new Button(L"Textures/Tile/Characters/purple_character.png"));	// 19
	UI_BTN.push_back(new Button(L"Textures/Tile/Characters/red_character.png"));	// 20
	UI_BTN.push_back(new Button(L"Textures/Tile/Characters/yellow_character.png"));	// 21

	// 캐릭터 일정 수정 버튼 (22 ~ 25) 총 4개
	UI_BTN.push_back(new Button(L"Textures/UI_IMAGE/UI_Image_TimeSet01.png"));	// 22
	UI_BTN.push_back(new Button(L"Textures/UI_IMAGE/UI_Image_TimeSet02.png"));	// 23
	UI_BTN.push_back(new Button(L"Textures/UI_IMAGE/UI_Image_TimeSet04.png"));	// 24
	UI_BTN.push_back(new Button(L"Textures/UI_IMAGE/UI_Image_TimeSet05.png"));	// 25

	// 새롭게 생긴 작업 지시
	UI_BTN.push_back(new Button(L"Textures/UI_IMAGE/UI_Image_01_04.png"));	// 26

	UI_back = new Quad(L"Textures/UI_IMAGE/UI_ImageBack.png");
	UI_jacup_back = new Quad(L"Textures/UI_IMAGE/UI_ImageBack.png");
	Gunchuck_back = new Quad(L"Textures/UI_IMAGE/UI_ImageBack.png");
	Gunchuck_back02 = new Quad(L"Textures/UI_IMAGE/UI_ImageBack.png");

	rim1mam = new Quad(L"Textures/UI_IMAGE/UI_ImageBack.png");
	rim2mam = new Quad(L"Textures/UI_IMAGE/UI_ImageBack.png");
	rim3mam = new Quad(L"Textures/UI_IMAGE/UI_ImageBack.png");
	rim4mam = new Quad(L"Textures/UI_IMAGE/UI_ImageBack.png");

	// 프로세스 바 (0 ~ 3)
	UI_PRB.push_back(new ProgressBar(L"Textures/UI_IMAGE/ggggBangBnagBnagBnag.png")); // 0
	UI_PRB.push_back(new ProgressBar(L"Textures/UI_IMAGE/ggggBangBnagBnagBnag.png")); // 1
	UI_PRB.push_back(new ProgressBar(L"Textures/UI_IMAGE/ggggBangBnagBnagBnag.png")); // 2
	UI_PRB.push_back(new ProgressBar(L"Textures/UI_IMAGE/ggggBangBnagBnagBnag.png")); // 3
	UI_PRB.push_back(new ProgressBar(L"Textures/UI_IMAGE/ggggBangBnagBnagBnag.png")); // 4
	UI_PRB.push_back(new ProgressBar(L"Textures/UI_IMAGE/ggggBangBnagBnagBnag.png")); // 5
	UI_PRB.push_back(new ProgressBar(L"Textures/UI_IMAGE/ggggBangBnagBnagBnag.png")); // 6
	UI_PRB.push_back(new ProgressBar(L"Textures/UI_IMAGE/ggggBangBnagBnagBnag.png")); // 7
	UI_PRB.push_back(new ProgressBar(L"Textures/UI_IMAGE/ggggBangBnagBnagBnag.png")); // 8
	UI_PRB.push_back(new ProgressBar(L"Textures/UI_IMAGE/ggggBangBnagBnagBnag.png")); // 9

	// 시간별 작업
	stc.push_back(new TIME_schedule(Vector2(130, 250), 250)); // 0
	stc.push_back(new TIME_schedule(Vector2(130, 200), 200)); // 1
	stc.push_back(new TIME_schedule(Vector2(130, 150), 150)); // 2
	stc.push_back(new TIME_schedule(Vector2(130, 100), 100)); // 3

	// 작업 체크박스
	zero1.push_back(new Schedule_CheckBox(Vector2(200, 350))); // 0
	zero1.push_back(new Schedule_CheckBox(Vector2(200, 275))); // 1
	zero1.push_back(new Schedule_CheckBox(Vector2(200, 200))); // 2
	zero1.push_back(new Schedule_CheckBox(Vector2(200, 125))); // 3

	// 작업지시용 버튼 (추후 추가를 편하게 하기 위한 추가 선언
	otherBTN.push_back(new Button(L"Textures/clear.png")); // 0
	otherBTN.push_back(new Button(L"Textures/clear.png")); // 1
	otherBTN.push_back(new Button(L"Textures/clear.png")); // 2

	wlrmadltnsrks = new Quad(L"Textures/Tile/Characters/green_character.png");
	ActiveData = new OBJTile();
	ActiveData->SetActive(false);

	// 건축용 타일들 총 14개
	Build_samples.push_back(new Button(L"Textures/Tile/Tiles/NoTile/SA/bed_luxurious.png"));	// 0
	Build_samples.push_back(new Button(L"Textures/Tile/Tiles/NoTile/SA/campfire.png"));			// 1
	Build_samples.push_back(new Button(L"Textures/Tile/Tiles/NoTile/SA/cart.png"));				// 2
	Build_samples.push_back(new Button(L"Textures/Tile/Tiles/NoTile/SA/chair.png"));			// 3
	Build_samples.push_back(new Button(L"Textures/Tile/Tiles/NoTile/SA/chest.png"));			// 4
	Build_samples.push_back(new Button(L"Textures/Tile/Tiles/NoTile/SA/coffin.png"));			// 5
	Build_samples.push_back(new Button(L"Textures/Tile/Tiles/NoTile/SA/crate.png"));			// 6
	Build_samples.push_back(new Button(L"Textures/Tile/Tiles/NoTile/SA/door_closed.png"));		// 7
	Build_samples.push_back(new Button(L"Textures/Tile/Tiles/NoTile/SA/table.png"));			// 8
	Build_samples.push_back(new Button(L"Textures/Tile/Tiles/NoTile/SA/wall.png"));				// 9
	Build_samples.push_back(new Button(L"Textures/Tile/Tiles/NoTile/SA/wall_corner.png"));		// 10
	Build_samples.push_back(new Button(L"Textures/Tile/Tiles/NoTile/SA/wall_damaged.png"));		// 11

	// 바닥 타일들 총 9개
	Badcs.push_back(new Button(L"Textures/Tile/Tiles/Floor Tile/carpet.png"));				// 0
	Badcs.push_back(new Button(L"Textures/Tile/Tiles/Floor Tile/grass.png"));				// 1
	Badcs.push_back(new Button(L"Textures/Tile/Tiles/Floor Tile/tile.png"));				// 2
	Badcs.push_back(new Button(L"Textures/Tile/Tiles/Floor Tile/tiles.png"));	      		 // 3
	Badcs.push_back(new Button(L"Textures/Tile/Tiles/Floor Tile/tiles_center.png"));		// 4
	Badcs.push_back(new Button(L"Textures/Tile/Tiles/Floor Tile/tiles_cracked.png"));		// 5
	Badcs.push_back(new Button(L"Textures/Tile/Tiles/Floor Tile/tiles_decorative.png"));	 // 6
	Badcs.push_back(new Button(L"Textures/Tile/Tiles/Floor Tile/water.png"));				// 7
	Badcs.push_back(new Button(L"Textures/Tile/Tiles/Floor Tile/wood.png"));				 // 8

	// 기본 UI
	{
		UI_BTN[0]->Scale() = { BTN_size, BTN_size };
		UI_BTN[0]->Pos() = { 73,  BTN_height };

		UI_BTN[1]->Scale() = { BTN_size, BTN_size };
		UI_BTN[1]->Pos() = { 218,  BTN_height };

		UI_BTN[2]->Scale() = { BTN_size, BTN_size };
		UI_BTN[2]->Pos() = { 363,  BTN_height };

		UI_BTN[3]->Scale() = { BTN_size, BTN_size };
		UI_BTN[3]->Pos() = { 508,  BTN_height };

		UI_BTN[4]->Scale() = { BTN_size, BTN_size };
		UI_BTN[4]->Pos() = { 653,  BTN_height };

		UI_BTN[5]->Scale() = { BTN_size, BTN_size };
		UI_BTN[5]->Pos() = { 798,  BTN_height };

		UI_BTN[6]->Scale() = { BTN_size, BTN_size };
		UI_BTN[6]->Pos() = { 943,  BTN_height };

		UI_BTN[7]->Scale() = { BTN_size, BTN_size };
		UI_BTN[7]->Pos() = { 1088,  BTN_height };

		UI_BTN[8]->Scale() = { BTN_size + 0.18f, BTN_size + 0.000f };
		UI_BTN[8]->Pos() = { 1225,  BTN_height };
	}

	// 배경 UI
	{
		UI_back->Scale() = { 0.48, 0.7f };
		UI_back->Pos() = { 72,  131 };

		Gunchuck_back->Scale() = { 3.3f, 0.3f };
		Gunchuck_back->Pos() = { 645,  73 };
	}

	// 부가 UI
	{
		UI_BTN[9]->Scale() = { BTN_size - 0.03f, BTN_size + 0.1f };
		UI_BTN[9]->Pos() = { 73.0f,  207.0f };

		UI_BTN[10]->Scale() = { BTN_size - 0.03f, BTN_size + 0.1f };
		UI_BTN[10]->Pos() = { 73.0f,  165.0f };

		UI_BTN[11]->Scale() = { BTN_size - 0.03f, BTN_size + 0.1f };
		UI_BTN[11]->Pos() = { 73.0f,  123.0f };

		UI_BTN[26]->Scale() = { BTN_size - 0.03f, BTN_size + 0.1f };
		UI_BTN[26]->Pos() = { 73.0f,  81.0f };

		UI_BTN[22]->Scale() = { 0.4f, 0.4f };
		UI_BTN[22]->Pos() = { 120,  400 };

		UI_BTN[23]->Scale() = { 0.4f, 0.4f };
		UI_BTN[23]->Pos() = { 250,  400 };

		UI_BTN[24]->Scale() = { 0.4f, 0.4f };
		UI_BTN[24]->Pos() = { 380,  400 };

		UI_BTN[25]->Scale() = { 0.4f, 0.4f };
		UI_BTN[25]->Pos() = { 510,  400 };


		// 작업 지시 버튼
		otherBTN[0]->Scale() = { 0.4f, 0.4f };
		otherBTN[0]->Pos() = { 220,  75 };

		otherBTN[1]->Scale() = { 0.4f, 0.4f };
		otherBTN[1]->Pos() = { 300,  75 };

		otherBTN[2]->Scale() = { 0.4f, 0.4f };
		otherBTN[2]->Pos() = { 380,  75 };
	}

	// 캐릭터 정보 UI
	{
		float valueY = 268;
		float scaleX = 0.2f;

		UI_BTN[12]->Scale() = { scaleX, 0.3f };
		UI_BTN[12]->Pos() = { 60,  valueY };

		UI_BTN[13]->Scale() = { scaleX, 0.3f };
		UI_BTN[13]->Pos() = { 180,  valueY };

		UI_BTN[14]->Scale() = { scaleX, 0.3f };
		UI_BTN[14]->Pos() = { 300,  valueY };

		UI_BTN[15]->Scale() = { scaleX, 0.3f };
		UI_BTN[15]->Pos() = { 420,  valueY };

		UI_BTN[16]->Scale() = { scaleX, 0.3f };
		UI_BTN[16]->Pos() = { 540,  valueY };

		UI_BTN[17]->Scale() = { scaleX, 0.3f };
		UI_BTN[17]->Pos() = { 660,  valueY };

		// 프로세스 바
		{
			UI_PRB[0]->Scale() = { 1.3f, 0.2f };
			UI_PRB[0]->Pos() = { 40, 180 };

			UI_PRB[1]->Scale() = { 1.3f, 0.2f };
			UI_PRB[1]->Pos() = { 210, 180 };

			UI_PRB[2]->Scale() = { 1.3f, 0.2f };
			UI_PRB[2]->Pos() = { 380, 180 };

			UI_PRB[3]->Scale() = { 1.3f, 0.2f };
			UI_PRB[3]->Pos() = { 550, 180 };


			UI_PRB[4]->Scale() = { 3.4f, 0.4f };
			UI_PRB[4]->Pos() = { 300, 615 };

			UI_PRB[5]->Scale() = { 1.8f, 0.3f };
			UI_PRB[5]->Pos() = { 40, 620 };

			UI_PRB[6]->Scale() = { 1.8f, 0.3f };
			UI_PRB[6]->Pos() = { 40, 550 };

			UI_PRB[7]->Scale() = { 1.8f, 0.3f };
			UI_PRB[7]->Pos() = { 40, 480 };

			UI_PRB[8]->Scale() = { 1.3f, 0.2f };
			UI_PRB[8]->Pos() = { 40, 410 };

			UI_PRB[9]->Scale() = { 1.3f, 0.2f };
			UI_PRB[9]->Pos() = { 40, 340 };
		}

		Gunchuck_back02->Scale() = { 2.4f, 1.3f };
		Gunchuck_back02->Pos() = { 360,  480 };


		UI_BTN[18]->Scale() = { 1, 1 };
		UI_BTN[18]->Pos() = { CENTER_X - 150,  680 };

		UI_BTN[19]->Scale() = { 1, 1 };
		UI_BTN[19]->Pos() = { CENTER_X - 50,  680 };

		UI_BTN[20]->Scale() = { 1, 1 };
		UI_BTN[20]->Pos() = { CENTER_X + 50,  680 };

		UI_BTN[21]->Scale() = { 1, 1 };
		UI_BTN[21]->Pos() = { CENTER_X + 150,  680 };

		float hcd = 0.18f;

		rim1mam->Scale() = { hcd, hcd };
		rim1mam->Pos() = { CENTER_X - 150,  680 };

		rim2mam->Scale() = { hcd, hcd };
		rim2mam->Pos() = { CENTER_X - 50,  680 };

		rim3mam->Scale() = { hcd, hcd };
		rim3mam->Pos() = { CENTER_X + 50,  680 };

		rim4mam->Scale() = { hcd, hcd };
		rim4mam->Pos() = { CENTER_X + 150,  680 };

		wlrmadltnsrks->Scale() = { 1.5f, 1.5f };
		wlrmadltnsrks->Pos() = { 100,  100 };
	}

	// 구상용 (건축, 바닥, 지시)
	{
		float YYY = 75.0f;
		float XXX = 230.0f;

		int plusValue = 0;

		for (int i = 0; i < Build_samples.size(); ++i)
		{
			Build_samples[i]->Scale() = { 1, 1 };
			Build_samples[i]->Pos() = { XXX + plusValue,  YYY };

			plusValue += 75;
		}
		plusValue = 0;

		for (int i = 0; i < Badcs.size(); ++i)
		{
			Badcs[i]->Scale() = { 1, 1 };
			Badcs[i]->Pos() = { XXX + plusValue,  YYY };

			plusValue += 75;
		}
	}
}
UI_Scene::~UI_Scene()
{
	delete UI_back;
	delete UI_jacup_back;
	delete Gunchuck_back;
	delete Gunchuck_back02;
	delete haldng;
	delete wlrmadltnsrks;
	delete rim1mam;
	delete rim2mam;
	delete rim3mam;
	delete rim4mam;
	delete ActiveData;

	for (ProgressBar* prp : UI_PRB)
		delete prp;
	for (Button* button : UI_BTN)
		delete button;
	for (Button* button : Build_samples)
		delete button;
	for (Button* button : Badcs)
		delete button;
	for (Button* button : otherBTN)
		delete button;
	for (TIME_schedule* sss : stc)
		delete sss;
	for (Schedule_CheckBox* adb : zero1)
		delete adb;
	for (Marker* adb : SelectMarker)
		delete adb;
}

void UI_Scene::Update()
{
	CM->JobnumberRESET(); // 모든 작업들의 횟수 0으로 초기화

	KEY_Input();

	Second += DELTA;

	for (int i = 0; i < SelectMarker.size(); ++i)
	{
		SelectMarker[i]->Update();

		if (otherBTN[0]->GetDown001() && SelectMarker[0]->myjob == "WOOD")
		{
			if (SelectMarker[i]->Mynumber == SELETCtileintDAta)
			{
				SelectMarker.erase(SelectMarker.begin() + i);
			}
		}
	}

	if (Second >= Max_Second)
	{
		Second = 0.0f;

		Hour++;
	}

	if (Hour >= 24)
	{
		Hour = 0;
		Day++;
	}

	for (Button* button : UI_BTN)
		button->Update();

	// 캐릭터 UI 정보창
	{
		for (ProgressBar* prp : UI_PRB)
			prp->Update();

		rim1mam->UpdateWorld();
		rim2mam->UpdateWorld();
		rim3mam->UpdateWorld();
		rim4mam->UpdateWorld();

		Gunchuck_back02->UpdateWorld();
	}

	if (SelectRim != nullptr) SelectRim->Update();

	if (UI_BTN[9]->GetDown() || UI_BTN[10]->GetDown() || UI_BTN[11]->GetDown() || UI_BTN[26]->GetDown())
	{
		ActiveData->SetActive(false);

		for (int i = 0; i < otherBTN.size(); ++i)
		{
			otherBTN[i]->SetDown001(false);
		}
	}
	if (!UI_BTN[0]->GetDown001() || UI_BTN[0]->GetDown())
	{
		UI_BTN[9]->SetDown001(false);
		UI_BTN[10]->SetDown001(false);
		UI_BTN[11]->SetDown001(false);
		UI_BTN[26]->SetDown001(false);
		for (int i = 0; i < Build_samples.size(); ++i)
		{
			Build_samples[i]->SetDown001(false);
		}
	}

	// 구상 버튼
	if (UI_BTN[9]->GetDown001())
	{
		if (Build_samples[0]->GetDown())
		{
			ActiveData->SetTexture(Build_samples[0]->wwwsss);
			ActiveData->SetActive(true);
			ActiveData->bbb = OBJTile::BAD;
		}
		if (Build_samples[1]->GetDown())
		{
			ActiveData->SetTexture(Build_samples[1]->wwwsss);
			ActiveData->SetActive(true);
			ActiveData->bbb = OBJTile::FIRE;
		}
		if (Build_samples[2]->GetDown())
		{
			ActiveData->SetTexture(Build_samples[2]->wwwsss);
			ActiveData->SetActive(true);
			ActiveData->bbb = OBJTile::CART;
		}
		if (Build_samples[3]->GetDown())
		{
			ActiveData->SetTexture(Build_samples[3]->wwwsss);
			ActiveData->SetActive(true);
			ActiveData->bbb = OBJTile::CHAIR;
		}
		if (Build_samples[4]->GetDown())
		{
			ActiveData->SetTexture(Build_samples[4]->wwwsss);
			ActiveData->SetActive(true);
			ActiveData->bbb = OBJTile::CHEST;
		}
		if (Build_samples[5]->GetDown())
		{
			ActiveData->SetTexture(Build_samples[5]->wwwsss);
			ActiveData->SetActive(true);
			ActiveData->bbb = OBJTile::COFFIN;
		}
		if (Build_samples[6]->GetDown())
		{
			ActiveData->SetTexture(Build_samples[6]->wwwsss);
			ActiveData->SetActive(true);
			ActiveData->bbb = OBJTile::CHEST;
		}
		if (Build_samples[7]->GetDown())
		{
			ActiveData->SetTexture(Build_samples[7]->wwwsss);
			ActiveData->SetActive(true);
			ActiveData->bbb = OBJTile::DOOR;
		}
		if (Build_samples[8]->GetDown())
		{
			ActiveData->SetTexture(Build_samples[8]->wwwsss);
			ActiveData->SetActive(true);
			ActiveData->bbb = OBJTile::TABLE;
		}
		if (Build_samples[9]->GetDown())
		{
			ActiveData->SetTexture(Build_samples[9]->wwwsss);
			ActiveData->SetActive(true);
			ActiveData->bbb = OBJTile::WALL;
		}
		if (Build_samples[10]->GetDown())
		{
			ActiveData->SetTexture(Build_samples[10]->wwwsss);
			ActiveData->SetActive(true);
			ActiveData->bbb = OBJTile::WALL;
		}
		if (Build_samples[11]->GetDown())
		{
			ActiveData->SetTexture(Build_samples[11]->wwwsss);
			ActiveData->SetActive(true);
			ActiveData->bbb = OBJTile::WALL;
		}

		for (int i = 0; i < Build_samples.size(); ++i)
		{
			Build_samples[i]->SetDown001(false);
			Build_samples[i]->Update();
		}
	}
	if (UI_BTN[10]->GetDown001())
	{

	}
	if (UI_BTN[11]->GetDown001())
	{
		if (Badcs[0]->GetDown())
		{
			ActiveData->SetTexture(Badcs[0]->wwwsss);
			ActiveData->SetActive(true);
		}
		if (Badcs[1]->GetDown())
		{
			ActiveData->SetTexture(Badcs[1]->wwwsss);
			ActiveData->SetActive(true);
		}
		if (Badcs[2]->GetDown())
		{
			ActiveData->SetTexture(Badcs[2]->wwwsss);
			ActiveData->SetActive(true);
		}
		if (Badcs[3]->GetDown())
		{
			ActiveData->SetTexture(Badcs[3]->wwwsss);
			ActiveData->SetActive(true);
		}
		if (Badcs[4]->GetDown())
		{
			ActiveData->SetTexture(Badcs[4]->wwwsss);
			ActiveData->SetActive(true);
		}
		if (Badcs[5]->GetDown())
		{
			ActiveData->SetTexture(Badcs[5]->wwwsss);
			ActiveData->SetActive(true);
		}
		if (Badcs[6]->GetDown())
		{
			ActiveData->SetTexture(Badcs[6]->wwwsss);
			ActiveData->SetActive(true);
		}
		if (Badcs[7]->GetDown())
		{
			ActiveData->SetTexture(Badcs[7]->wwwsss);
			ActiveData->SetActive(true);
		}
		if (Badcs[8]->GetDown())
		{
			ActiveData->SetTexture(Badcs[8]->wwwsss);
			ActiveData->SetActive(true);
		}

		for (int i = 0; i < Badcs.size(); ++i)
		{
			Badcs[i]->SetDown001(false);
			Badcs[i]->Update();
		}
	}
	if (UI_BTN[26]->GetDown001())
	{
		for (Button* btn : otherBTN)
			btn->Update();


		if (KEY_DOWN('C'))
		{
			if (otherBTN[0]->GetDown001()) otherBTN[0]->SetDown001(false);
			else if (!otherBTN[0]->GetDown001()) otherBTN[0]->SetDown001(true);

			otherBTN[1]->SetDown001(false);
			otherBTN[2]->SetDown001(false);
		}
		if (KEY_DOWN('X'))
		{
			if (otherBTN[1]->GetDown001()) otherBTN[1]->SetDown001(false);
			else if (!otherBTN[1]->GetDown001()) otherBTN[1]->SetDown001(true);

			otherBTN[0]->SetDown001(false);
			otherBTN[2]->SetDown001(false);
		}
		if (KEY_DOWN('B'))
		{
			if (otherBTN[2]->GetDown001()) otherBTN[2]->SetDown001(false);
			else if (!otherBTN[2]->GetDown001()) otherBTN[2]->SetDown001(true);

			otherBTN[0]->SetDown001(false);
			otherBTN[1]->SetDown001(false);
		}

		if (otherBTN[0]->GetDown001() || otherBTN[1]->GetDown001() || otherBTN[2]->GetDown001())
		{
			if (otherBTN[0]->GetDown001())
			{
				if (otherBTN[1]->GetDown() || otherBTN[2]->GetDown())
				{
					otherBTN[0]->SetDown001(false);
				}
			}
			if (otherBTN[1]->GetDown001())
			{
				if (otherBTN[0]->GetDown() || otherBTN[2]->GetDown())
				{
					otherBTN[1]->SetDown001(false);
				}
			}
			if (otherBTN[2]->GetDown001())
			{
				if (otherBTN[0]->GetDown() || otherBTN[1]->GetDown())
				{
					otherBTN[2]->SetDown001(false);
				}
			}
		}
	}

	// 작업 버튼
	if (UI_BTN[1]->GetDown001())
	{
		UI_jacup_back->Scale() = { 2.5f, 1.5f };
		UI_jacup_back->Pos() = { 370,  250 };

		for (Schedule_CheckBox* abc : zero1)
			abc->Update();
	}
	// 일정 버튼
	if (UI_BTN[2]->GetDown001())
	{
		UI_jacup_back->Scale() = { 2.5f, 1.5f };
		UI_jacup_back->Pos() = { 370,  250 };

		for (TIME_schedule* sss : stc)
		{
			sss->Update();
			if (haldng != nullptr)
			{
				sss->ChangeTexture(haldng);
			}
		}

		if (UI_BTN[22]->GetDown001())
		{
			if (UI_BTN[23]->GetDown() || UI_BTN[24]->GetDown() || UI_BTN[25]->GetDown())
			{
				UI_BTN[22]->SetDown001(false);
			}
		}
		if (UI_BTN[23]->GetDown001())
		{
			if (UI_BTN[22]->GetDown() || UI_BTN[24]->GetDown() || UI_BTN[25]->GetDown())
			{
				UI_BTN[23]->SetDown001(false);
			}
		}
		if (UI_BTN[24]->GetDown001())
		{
			if (UI_BTN[22]->GetDown() || UI_BTN[23]->GetDown() || UI_BTN[25]->GetDown())
			{
				UI_BTN[24]->SetDown001(false);
			}
		}
		if (UI_BTN[25]->GetDown001())
		{
			if (UI_BTN[22]->GetDown() || UI_BTN[23]->GetDown() || UI_BTN[24]->GetDown())
			{
				UI_BTN[25]->SetDown001(false);
			}
		}

	}
	else
	{
		UI_BTN[22]->SetDown001(false);
		UI_BTN[23]->SetDown001(false);
		UI_BTN[24]->SetDown001(false);
		UI_BTN[25]->SetDown001(false);
	}
	// 메뉴 버튼
	if (UI_BTN[8]->GetDown001())
	{
		UI_jacup_back->Scale() = { 0.5f, 0.75f };
		UI_jacup_back->Pos() = { 1200,  140 };
	}

	if (SelectRim != nullptr)
	{
		RimOn = true;
	}
	else
	{
		RimOn = false;
	}

	if (RimOn && characterIN)
	{
		UI_jacup_back->Scale() = { 2.4f, 0.75f };
		UI_jacup_back->Pos() = { 360,  140 };

		Selectrim(SelectRim);

		wlrmadltnsrks->SetTexture(SelectRim->GetTexture());
		wlrmadltnsrks->UpdateWorld();
	}

	UI_back->UpdateWorld();
	UI_jacup_back->UpdateWorld();
	Gunchuck_back->UpdateWorld();

	if (selected != nullptr)
	{
		selected->Pos() = MOUSE;
		selected->UpdateWorld();
	}

	if (UI_BTN[18]->GetDown001())
	{
		SelectRim1 = true;
		if (UI_BTN[19]->GetDown() || UI_BTN[20]->GetDown() || UI_BTN[21]->GetDown())
		{
			UI_BTN[18]->SetDown001(false);
		}
	}
	else
	{
		SelectRim1 = false;
	}
	if (UI_BTN[19]->GetDown001())
	{
		SelectRim2 = true;
		if (UI_BTN[18]->GetDown() || UI_BTN[20]->GetDown() || UI_BTN[21]->GetDown())
		{
			UI_BTN[19]->SetDown001(false);
		}
	}
	else
	{
		SelectRim2 = false;
	}
	if (UI_BTN[20]->GetDown001())
	{
		SelectRim3 = true;
		if (UI_BTN[18]->GetDown() || UI_BTN[19]->GetDown() || UI_BTN[21]->GetDown())
		{
			UI_BTN[20]->SetDown001(false);
		}
	}
	else
	{
		SelectRim3 = false;
	}
	if (UI_BTN[21]->GetDown001())
	{
		SelectRim4 = true;
		if (UI_BTN[18]->GetDown() || UI_BTN[19]->GetDown() || UI_BTN[20]->GetDown())
		{
			UI_BTN[21]->SetDown001(false);
		}
	}
	else
	{
		SelectRim4 = false;
	}

	// 건축물 미리보기
	if (ActiveData != nullptr)
	{
		if (KEY_DOWN(VK_RBUTTON)) ActiveData->SetActive(false);

		if (KEY_DOWN('Q'))
		{
			ActiveData->Rot().z += XM_PIDIV2;

			if (ActiveData->Rot().z > XM_2PI)
				ActiveData->Rot().z -= XM_2PI;
		}
		if (KEY_DOWN('E'))
		{
			ActiveData->Rot().z -= XM_PIDIV2;

			if (ActiveData->Rot().z < 0)
				ActiveData->Rot().z += XM_2PI;
		}

		ActiveData->Pos() = MOUSE;
		ActiveData->Update();
	}
}

void UI_Scene::Render()
{
	for (Marker* adb : SelectMarker)
		adb->Render();

	for (int i = 0; i < 9; ++i)
	{
		UI_BTN[i]->Render();
	}

	if (SelectRim != nullptr) SelectRim->Render();

	if (selected != nullptr) selected->Render();

	// 구상 버튼
	if (UI_BTN[0]->GetDown001())
	{
		if (UI_BTN[1]->GetDown() || UI_BTN[2]->GetDown() || UI_BTN[8]->GetDown())
		{
			UI_BTN[0]->SetDown001(false);
		}

		UI_back->Render();

		for (int i = 9; i < 12; ++i)
		{
			UI_BTN[i]->Render();
		}
		UI_BTN[26]->Render();

		// 구상 -> 건축, 구역, 바닥 버튼
		if (UI_BTN[9]->GetDown001() || UI_BTN[10]->GetDown001() || UI_BTN[11]->GetDown001() || UI_BTN[26]->GetDown001())
		{
			Gunchuck_back->Render();

			if (UI_BTN[9]->GetDown001())
			{
				if (UI_BTN[10]->GetDown() || UI_BTN[11]->GetDown() || UI_BTN[26]->GetDown())
				{
					UI_BTN[9]->SetDown001(false);
				}

				for (Button* button : Build_samples)
					button->Render();
			}
			if (UI_BTN[10]->GetDown001())
			{
				if (UI_BTN[9]->GetDown() || UI_BTN[11]->GetDown() || UI_BTN[26]->GetDown())
				{
					UI_BTN[10]->SetDown001(false);
				}
			}
			if (UI_BTN[11]->GetDown001())
			{
				if (UI_BTN[9]->GetDown() || UI_BTN[10]->GetDown() || UI_BTN[26]->GetDown())
				{
					UI_BTN[11]->SetDown001(false);
				}

				for (Button* button : Badcs)
					button->Render();


			}
			if (UI_BTN[26]->GetDown001())
			{
				if (UI_BTN[9]->GetDown() || UI_BTN[10]->GetDown() || UI_BTN[11]->GetDown())
				{
					UI_BTN[26]->SetDown001(false);
					for (Button* btn : otherBTN)
						btn->SetDown001(false);
				}

				for (Button* btn : otherBTN)
					btn->Render();
			}
		}
	}
	else
	{
		for (int i = 9; i < 12; ++i)
		{
			UI_BTN[i]->SetDown001(false);
		}
		for (Button* btn : otherBTN)
			btn->SetDown001(false);
	}
	// 작업 버튼
	if (UI_BTN[1]->GetDown001())
	{
		if (UI_BTN[0]->GetDown() || UI_BTN[2]->GetDown() || UI_BTN[8]->GetDown())
		{
			UI_BTN[1]->SetDown001(false);
		}
		UI_jacup_back->Render();

		for (Schedule_CheckBox* abc : zero1)
			abc->Render();

	}
	// 일정 버튼
	if (UI_BTN[2]->GetDown001())
	{
		if (UI_BTN[0]->GetDown() || UI_BTN[1]->GetDown() || UI_BTN[8]->GetDown())
		{
			UI_BTN[2]->SetDown001(false);
		}
		UI_jacup_back->Render();

		for (TIME_schedule* sss : stc)
			sss->Render();

		for (int i = 22; i < 26; ++i)
		{
			UI_BTN[i]->Render();
		}
	}
	// 메뉴 버튼
	if (UI_BTN[8]->GetDown001())
	{
		if (UI_BTN[0]->GetDown() || UI_BTN[1]->GetDown() || UI_BTN[2]->GetDown())
		{
			UI_BTN[8]->SetDown001(false);
		}
		UI_jacup_back->Render();
	}
	// 캐릭터 정보 UI
	if (RimOn)
	{
		UI_jacup_back->Render();
		wlrmadltnsrks->Render();
		for (int i = 12; i < 18; ++i)
		{
			UI_BTN[i]->Render();
		}
		for (int i = 0; i < 4; ++i)
		{
			UI_PRB[i]->Render();
		}

		if (UI_BTN[12]->GetDown001() || UI_BTN[13]->GetDown001() || UI_BTN[14]->GetDown001() || UI_BTN[15]->GetDown001() || UI_BTN[16]->GetDown001() || UI_BTN[17]->GetDown001())
		{
			Gunchuck_back02->Render();

			if (UI_BTN[12]->GetDown001())
			{
				if (UI_BTN[13]->GetDown() ||
					UI_BTN[14]->GetDown() ||
					UI_BTN[15]->GetDown() ||
					UI_BTN[16]->GetDown() ||
					UI_BTN[17]->GetDown())
				{
					UI_BTN[12]->SetDown001(false);
				}
			}
			if (UI_BTN[13]->GetDown001())
			{
				if (UI_BTN[12]->GetDown() ||
					UI_BTN[14]->GetDown() ||
					UI_BTN[15]->GetDown() ||
					UI_BTN[16]->GetDown() ||
					UI_BTN[17]->GetDown())
				{
					UI_BTN[13]->SetDown001(false);
				}
			}
			if (UI_BTN[14]->GetDown001())
			{
				if (UI_BTN[12]->GetDown() ||
					UI_BTN[13]->GetDown() ||
					UI_BTN[15]->GetDown() ||
					UI_BTN[16]->GetDown() ||
					UI_BTN[17]->GetDown())
				{
					UI_BTN[14]->SetDown001(false);
				}
			}
			if (UI_BTN[15]->GetDown001())
			{
				if (UI_BTN[12]->GetDown() ||
					UI_BTN[13]->GetDown() ||
					UI_BTN[14]->GetDown() ||
					UI_BTN[16]->GetDown() ||
					UI_BTN[17]->GetDown())
				{
					UI_BTN[15]->SetDown001(false);
				}
			}
			if (UI_BTN[16]->GetDown001())
			{
				if (UI_BTN[12]->GetDown() ||
					UI_BTN[13]->GetDown() ||
					UI_BTN[14]->GetDown() ||
					UI_BTN[15]->GetDown() ||
					UI_BTN[17]->GetDown())
				{
					UI_BTN[16]->SetDown001(false);
				}

				for (int i = 4; i < 10; ++i)
				{
					UI_PRB[i]->Render();
				}
			}
			if (UI_BTN[17]->GetDown001())
			{
				if (UI_BTN[12]->GetDown() ||
					UI_BTN[13]->GetDown() ||
					UI_BTN[14]->GetDown() ||
					UI_BTN[15]->GetDown() ||
					UI_BTN[16]->GetDown())
				{
					UI_BTN[17]->SetDown001(false);
				}
			}
		}
	}
	else if (!RimOn)
	{
		UI_BTN[12]->SetDown001(false);
		UI_BTN[13]->SetDown001(false);
		UI_BTN[14]->SetDown001(false);
		UI_BTN[15]->SetDown001(false);
		UI_BTN[16]->SetDown001(false);
		UI_BTN[17]->SetDown001(false);
	}

	if (SelectRim1) rim1mam->Render();
	if (SelectRim2) rim2mam->Render();
	if (SelectRim3) rim3mam->Render();
	if (SelectRim4) rim4mam->Render();

	for (int i = 18; i < 22; ++i)
	{
		UI_BTN[i]->Render();
	}


	if (ActiveData != nullptr) ActiveData->Render();
}

// 카메라를 따라다니게 하기 위한 UI 설정
void UI_Scene::Setpa(Transform* tra)
{
	for (Button* button : UI_BTN)
		button->SetParent(tra);

	UI_back->SetParent(tra);
	UI_jacup_back->SetParent(tra);
	Gunchuck_back->SetParent(tra);
	Gunchuck_back02->SetParent(tra);

	for (ProgressBar* prp : UI_PRB)
		prp->SetParent(tra);

	for (TIME_schedule* aaa : stc)
		aaa->Setpa(tra);

	for (Schedule_CheckBox* aaa : zero1)
		aaa->Setpa(tra);

	rim1mam->SetParent(tra);
	rim2mam->SetParent(tra);
	rim3mam->SetParent(tra);
	rim4mam->SetParent(tra);
	wlrmadltnsrks->SetParent(tra);

	for (Button* button : Build_samples)
		button->SetParent(tra);

	for (Button* button : Badcs)
		button->SetParent(tra);

	for (Button* btn : otherBTN)
		btn->SetParent(tra);
}

void UI_Scene::KEY_Input()
{
	if (KEY_PRESS(VK_LBUTTON))
	{

	}

	if (selected != nullptr && selected->GetTexture() != nullptr)
	{
		if (KEY_DOWN('Q'))
		{
			selected->Rot().z += XM_PIDIV2;

			if (selected->Rot().z > XM_2PI)
				selected->Rot().z -= XM_2PI;
			selected->Rot().z = XM_2PI;
		}

		if (KEY_DOWN('E'))
		{
			selected->Rot().z -= XM_PIDIV2;

			if (selected->Rot().z < 0)
				selected->Rot().z += XM_2PI;
			selected->Rot().z = 0.0f;
		}


	}
}

void UI_Scene::Selectrim(RimCharacter* rim)
{
	if (RimOn && characterIN)
	{

		UI_PRB[0]->Scale() = { 0.65f + (0.65f * rim->AI->HP / rim->AI->Max_HP), 0.2f };
		UI_PRB[1]->Scale() = { 0.65f + (0.65f * rim->AI->chongHap_feel / 100), 0.2f };

		UI_PRB[4]->Scale() = { 3.4f * rim->AI->chongHap_feel / 100, 0.4f };
		UI_PRB[5]->Scale() = { 1.8f * rim->AI->hunger / 100, 0.3f };
		UI_PRB[6]->Scale() = { 1.8f * rim->AI->sleep / 100, 0.3f };
		UI_PRB[7]->Scale() = { 1.8f * rim->AI->funy / 100, 0.3f };
		UI_PRB[8]->Scale() = { 1.3f * rim->AI->vusdks / 100, 0.2f };
		UI_PRB[9]->Scale() = { 1.3f * rim->AI->dhlcnf / 100, 0.2f };

		abfvsrb();
	}
}
void UI_Scene::abfvsrb()
{
	if (SelectRim->dlf[Hour] == RimCharacter::FREETIME)
	{
		UI_PRB[2]->image->SetTexture(L"Textures/UI_IMAGE/UI_Image_TimeSet01.png");
	}
	else if (SelectRim->dlf[Hour] == RimCharacter::WORKTIME)
	{
		UI_PRB[2]->image->SetTexture(L"Textures/UI_IMAGE/UI_Image_TimeSet02.png");
	}
	else if (SelectRim->dlf[Hour] == RimCharacter::JOYTIME)
	{
		UI_PRB[2]->image->SetTexture(L"Textures/UI_IMAGE/UI_Image_TimeSet04.png");
	}
	else if (SelectRim->dlf[Hour] == RimCharacter::SLEEPTIME)
	{
		UI_PRB[2]->image->SetTexture(L"Textures/UI_IMAGE/UI_Image_TimeSet05.png");
	}

}

void UI_Scene::SetTarget(RimCharacter* rim, int value)
{
	SelectRim = rim;

	if (value == 1) SelectRim1 = true;
	if (value == 2) SelectRim2 = true;
	if (value == 3) SelectRim3 = true;
	if (value == 4) SelectRim4 = true;

	if (value == 5)
	{
		SelectRim1 = false;
		SelectRim2 = false;
		SelectRim3 = false;
		SelectRim4 = false;
	}
}

void UI_Scene::ChangeTextureQuad()
{
	wlrmadltnsrks->SetTexture(SelectRim->GetTexture());
}