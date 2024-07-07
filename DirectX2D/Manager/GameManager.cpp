#include "Framework.h"

#include "Scenes/RimTestScene.h"

GameManager::GameManager()
{
	Create();

	UI_Scene::Get();

	uiViewBuffer = new MatrixBuffer();
	SCENE->Register("Rimtest", new RimTestScene());

	SCENE->ChangeScene("Rimtest");

	DB;
}

GameManager::~GameManager()
{
	SCENE->Delete();
	delete uiViewBuffer;

	Delete();
}

void GameManager::Update()
{
	CAMERA->Update();

	UI_Scene::Get()->Update();

	Keyboard::Get()->Update();
	Timer::Get()->Update();

	SCENE->Update();
}

void GameManager::Render()
{
	FONT->SetColor("Black");
	Font::Get()->SetStyle("PGothic");

	SCENE->PreRender();


	FONT->GetDC()->BeginDraw();
	string fps = "FPS : " + to_string(Timer::Get()->GetFPS());
	FONT->RenderText(fps, { 100, WIN_HEIGHT - 10 });

	string Htime;
	if (UIS->Hour < 10)
	{
		Htime = "0" + to_string(UIS->Hour) + " : 00";
	}
	else
	{
		Htime = to_string(UIS->Hour) + " : 00";
	}
	FONT->RenderText(Htime, { 1280, CENTER_Y });

	Htime = "Day " + to_string(UIS->Day);
	FONT->RenderText(Htime, { 1260, CENTER_Y + 25 });



	Device::Get()->Clear();


	SCENE->Render();

	ImGui_ImplDX11_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();

	if (UIS->UI_BTN[2]->GetDown001())
	{
		Font::Get()->SetColor("White");
		Font::Get()->SetStyle("PGothicABC");
		float atpos = 135.0f;
		FONT->RenderText("00", { atpos + 0, CENTER_Y - 80 });
		FONT->RenderText("01", { atpos + 25, CENTER_Y - 80 });
		FONT->RenderText("02", { atpos + 50, CENTER_Y - 80 });
		FONT->RenderText("03", { atpos + 75, CENTER_Y - 80 });
		FONT->RenderText("04", { atpos + 100, CENTER_Y - 80 });
		FONT->RenderText("05", { atpos + 122, CENTER_Y - 80 });
		FONT->RenderText("06", { atpos + 145, CENTER_Y - 80 });
		FONT->RenderText("07", { atpos + 170, CENTER_Y - 80 });
		FONT->RenderText("08", { atpos + 195, CENTER_Y - 80 });
		FONT->RenderText("09", { atpos + 220, CENTER_Y - 80 });
		FONT->RenderText("10", { atpos + 240, CENTER_Y - 80 });
		FONT->RenderText("11", { atpos + 263, CENTER_Y - 80 });
		FONT->RenderText("12", { atpos + 286, CENTER_Y - 80 });
		FONT->RenderText("13", { atpos + 312, CENTER_Y - 80 });
		FONT->RenderText("14", { atpos + 334, CENTER_Y - 80 });
		FONT->RenderText("15", { atpos + 360, CENTER_Y - 80 });
		FONT->RenderText("16", { atpos + 384, CENTER_Y - 80 });
		FONT->RenderText("17", { atpos + 407, CENTER_Y - 80 });
		FONT->RenderText("18", { atpos + 431, CENTER_Y - 80 });
		FONT->RenderText("19", { atpos + 454, CENTER_Y - 80 });
		FONT->RenderText("20", { atpos + 480, CENTER_Y - 80 });
		FONT->RenderText("21", { atpos + 504, CENTER_Y - 80 });
		FONT->RenderText("22", { atpos + 528, CENTER_Y - 80 });
		FONT->RenderText("23", { atpos + 552, CENTER_Y - 80 });
	}

	if (UIS->UI_BTN[1]->GetDown001())
	{
		Font::Get()->SetColor("White");
		float atpos = 216.0f;
		FONT->RenderText("Ä¡·á", { atpos + 0, 385 });
		FONT->RenderText("ÈÞ½Ä", { atpos + 50, 385 });
		FONT->RenderText("°Ç¼³", { atpos + 100, 385 });
		FONT->RenderText("Àç¹è", { atpos + 150, 385 });
		FONT->RenderText("Ã¤±¼", { atpos + 200, 385 });
		FONT->RenderText("Á¦·Ã", { atpos + 250, 385 });
		FONT->RenderText("¿î¹Ý", { atpos + 300, 385 });
	}

	CAMERA->RenderUI();


	if (UIS->UI_BTN[26]->GetDown001())
	{
		//Font::Get()->SetColor("White");

		FONT->RenderText("Ãë¼Ò", { 240, 75 });
		FONT->RenderText("Ã¶°Å", { 320, 75 });
		FONT->RenderText("¹ú¸ñ", { 400, 75 });
	}


	if (UIS->UI_BTN[16]->GetDown001())
	{
		Font::Get()->SetColor("White");
		FONT->RenderText("±âºÐ", { 500, 653 });
		FONT->RenderText("¹è°íÇÄ", { 98, 653 });
		FONT->RenderText("ÇÇ°ïÇÔ", { 98, 585 });
		FONT->RenderText("Àç¹Ì", { 85, 515 });
		FONT->RenderText("Æí¾ÈÇÔ", { 98, 440 });
		FONT->RenderText("¿ÜÃâ", { 85, 370 });
	}
	if (UIS->UI_BTN[13]->GetDown001())
	{
		float X = 100.0f;
		float Y = 550.0f;
		Font::Get()->SetColor("White");
		Font::Get()->SetStyle("ITEM");
		FONT->RenderText("¾ÆÀÌÅÛ ¸ñ·Ï", { 200.0f, 590.0f });
		Font::Get()->SetStyle("PGothic");
		for (int i = 0; i < UIS->SelectRim->Inventory.size(); ++i)
		{
			FONT->RenderText(UIS->SelectRim->Inventory[i], { X, Y });
			Y -= 25;
		}
	}

	UI_Scene::Get()->Render();

	uiViewBuffer->SetVS(1);
	SCENE->PostRender();

	ImGui::Render();

	ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());


	Font::Get()->GetDC()->EndDraw();

	Device::Get()->Present();

	// -------------------------------------------------------------------------


}

void GameManager::Create()
{
	Keyboard::Get();
	Timer::Get();
	Device::Get();
	Environment::Get();
	Observer::Get();

	Font::Get()->AddColor("White", 1, 1, 1);
	Font::Get()->AddColor("Black", 0, 0, 0);
	Font::Get()->AddStyle("PGothic", L"¸¼Àº °íµñ");
	Font::Get()->AddStyle("PGothicABC", L"¸¼Àº °íµñ", 15.0f);
	Font::Get()->AddStyle("ITEM", L"¸¼Àº °íµñ", 30.0f);

	Font::Get()->SetColor("Black");
	Font::Get()->SetStyle("PGothic");

	ImGui::CreateContext();
	ImGui::StyleColorsDark();

	ImGui_ImplWin32_Init(hWnd);
	ImGui_ImplDX11_Init(DEVICE, DC);
}

void GameManager::Delete()
{
	Keyboard::Delete();
	Timer::Delete();
	Device::Delete();
	Shader::Delete();
	Texture::Delete();
	Environment::Delete();
	Observer::Delete();
	Font::Delete();

	ImGui_ImplDX11_Shutdown();
	ImGui_ImplWin32_Shutdown();

	ImGui::DestroyContext();
}
