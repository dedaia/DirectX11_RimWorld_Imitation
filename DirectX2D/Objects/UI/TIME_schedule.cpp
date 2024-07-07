#include "Framework.h"

TIME_schedule::TIME_schedule(Vector2 pos, float poss)
{
	aaa.resize(24);
	bbb.resize(24);

	for (int i = 0; i < 24; ++i)
	{
		aaa[i] = new Quad(L"Textures/UI_Image_TimeGra.png");
		aaa[i]->Scale() = Vector2(0.07f, 0.2f);

		bbb[i] = new RectCollider(aaa[i]->Scale());
		bbb[i]->Scale() = {4000,500};
		bbb[i]->SetParent(aaa[i]);
	}

	image1 = L"Textures/UI_Image_TimeGra.png";
	image2 = L"Textures/UI_Image_TimeOrac.png";
	image3 = L"Textures/UI_Image_Timepur.png";
	image4 = L"Textures/UI_Image_TimeYell.png";

	aaa[0]->Pos() = pos + Vector2(0, 0);
	aaa[1]->Pos() = pos + Vector2(24, 0);
	aaa[2]->Pos() = pos + Vector2(48, 0);
	aaa[3]->Pos() = pos + Vector2(72, 0);
	aaa[4]->Pos() = pos + Vector2(96, 0);
	aaa[5]->Pos() = pos + Vector2(120, 0);
	aaa[6]->Pos() = pos + Vector2(144, 0);
	aaa[7]->Pos() = pos + Vector2(168, 0);
	aaa[8]->Pos() = pos + Vector2(192, 0);
	aaa[9]->Pos() = pos + Vector2(216, 0);
	aaa[10]->Pos() = pos + Vector2(240, 0);
	aaa[11]->Pos() = pos + Vector2(264, 0);
	aaa[12]->Pos() = pos + Vector2(288, 0);
	aaa[13]->Pos() = pos + Vector2(312, 0);
	aaa[14]->Pos() = pos + Vector2(336, 0);
	aaa[15]->Pos() = pos + Vector2(360, 0);
	aaa[16]->Pos() = pos + Vector2(384, 0);
	aaa[17]->Pos() = pos + Vector2(408, 0);
	aaa[18]->Pos() = pos + Vector2(432, 0);
	aaa[19]->Pos() = pos + Vector2(456, 0);
	aaa[20]->Pos() = pos + Vector2(480, 0);
	aaa[21]->Pos() = pos + Vector2(504, 0);
	aaa[22]->Pos() = pos + Vector2(528, 0);
	aaa[23]->Pos() = pos + Vector2(552, 0);

	bbb[0]->Pos() =  pos + Vector2(-150, -poss);
	bbb[1]->Pos() =  pos + Vector2(-150, -poss);
	bbb[2]->Pos() =  pos + Vector2(-150, -poss);
	bbb[3]->Pos() =  pos + Vector2(-150, -poss);
	bbb[4]->Pos() =  pos + Vector2(-150, -poss);
	bbb[5]->Pos() =  pos + Vector2(-150, -poss);
	bbb[6]->Pos() =  pos + Vector2(-150, -poss);
	bbb[7]->Pos() =  pos + Vector2(-150, -poss);
	bbb[8]->Pos() =  pos + Vector2(-150, -poss);
	bbb[9]->Pos() =  pos + Vector2(-150, -poss);
	bbb[10]->Pos() = pos + Vector2(-150, -poss);
	bbb[11]->Pos() = pos + Vector2(-150, -poss);
	bbb[12]->Pos() = pos + Vector2(-150, -poss);
	bbb[13]->Pos() = pos + Vector2(-150, -poss);
	bbb[14]->Pos() = pos + Vector2(-150, -poss);
	bbb[15]->Pos() = pos + Vector2(-150, -poss);
	bbb[16]->Pos() = pos + Vector2(-150, -poss);
	bbb[17]->Pos() = pos + Vector2(-150, -poss);
	bbb[18]->Pos() = pos + Vector2(-150, -poss);
	bbb[19]->Pos() = pos + Vector2(-150, -poss);
	bbb[20]->Pos() = pos + Vector2(-150, -poss);
	bbb[21]->Pos() = pos + Vector2(-150, -poss);
	bbb[22]->Pos() = pos + Vector2(-150, -poss);
	bbb[23]->Pos() = pos + Vector2(-150, -poss);
}
TIME_schedule::~TIME_schedule()
{
	for (int i = 0; i < 24; ++i)
	{
		delete aaa[i];
		delete bbb[i];
	}
}

void TIME_schedule::Update()
{
	for (int i = 0; i < 24; ++i)
	{
		aaa[i]->UpdateWorld();
		bbb[i]->UpdateWorld();
	}
}
void TIME_schedule::Render()
{
	for (int i = 0; i < 24; ++i)
	{
		aaa[i]->Render();
		//bbb[i]->Render();
	}
}

void TIME_schedule::Setpa(Transform* aaa)
{
	for (int i = 0; i < 24; ++i)
	{
		this->aaa[i]->SetParent(aaa);
	}
}

void TIME_schedule::ChangeTexture(Collider* ppp)
{
	if (KEY_PRESS(VK_LBUTTON))
	{
		for (int i = 0; i < 24; ++i)
		{
			if (bbb[i]->IsCollision(ppp))
			{
				if (UIS->UI_BTN[22]->GetDown001()) // 자유시간
				{
					aaa[i]->SetTexture(image1);
					set2 = 1;
				}
				if (UIS->UI_BTN[23]->GetDown001()) // 작업시간
				{
					aaa[i]->SetTexture(image4);
					set2 = 2;
				}
				if (UIS->UI_BTN[24]->GetDown001()) // 오락시간
				{
					aaa[i]->SetTexture(image2);
					set2 = 3;
				}
				if (UIS->UI_BTN[25]->GetDown001()) // 수면시간
				{
					aaa[i]->SetTexture(image3);
					set2 = 4;
				}
				set = i;
			}
		}
	}
}

void TIME_schedule::SetChange(RimCharacter* abc)
{
	for (int i = 0; i < 24; ++i)
	{
		if (abc->dlf[i] == RimCharacter::FREETIME)
		{
			aaa[i]->SetTexture(image1);
		}
		else if (abc->dlf[i] == RimCharacter::WORKTIME)
		{
			aaa[i]->SetTexture(image4);
		}
		else if (abc->dlf[i] == RimCharacter::JOYTIME)
		{
			aaa[i]->SetTexture(image2);
		}
		else if (abc->dlf[i] == RimCharacter::SLEEPTIME)
		{
			aaa[i]->SetTexture(image3);
		}
	}
}

void TIME_schedule::InputChange(RimCharacter* abc)
{
	if (set != 0)
	{
		if (set2 == 1) abc->dlf[set] = RimCharacter::FREETIME;
		else if (set2 == 2) abc->dlf[set] = RimCharacter::WORKTIME;
		else if (set2 == 3) abc->dlf[set] = RimCharacter::JOYTIME;
		else if (set2 == 4) abc->dlf[set] = RimCharacter::SLEEPTIME;

		set = 0;
		set2 = 0;
	}
}