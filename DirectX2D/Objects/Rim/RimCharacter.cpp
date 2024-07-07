#include "Framework.h"

RimCharacter::RimCharacter(wstring file, string tag, int num) : Quad(file)
{
	srand(GetTickCount64());
	RIMNUMBER = num;

	this->tag = tag;

	AI = new RimAI();

	cirlce = new CircleCollider(20);
	cirlce->Load();
	cirlce->SetParent(this);

	dlf[0] = SLEEPTIME;
	dlf[1] = SLEEPTIME;
	dlf[2] = SLEEPTIME;
	dlf[3] = SLEEPTIME;
	dlf[4] = SLEEPTIME;
	dlf[5] = SLEEPTIME;
	dlf[6] = FREETIME;
	dlf[7] = FREETIME;
	dlf[8] = FREETIME;
	dlf[9] = FREETIME;
	dlf[10] = FREETIME;
	dlf[11] = FREETIME;
	dlf[12] = FREETIME;
	dlf[13] = FREETIME;
	dlf[14] = FREETIME;
	dlf[15] = FREETIME;
	dlf[16] = FREETIME;
	dlf[17] = FREETIME;
	dlf[18] = FREETIME;
	dlf[19] = FREETIME;
	dlf[20] = FREETIME;
	dlf[21] = FREETIME;
	dlf[22] = SLEEPTIME;
	dlf[23] = SLEEPTIME;

	Work_Process = new ProgressBar();
	Work_Process->Scale() = Vector2(0.1f, 0.1f);
	Work_Process->SetActive(false);

	Speech_Bubble = new Quad(clear);
	Speech_Bubble->Scale() = Vector2(0.25f, 0.25f);
	Speech_Bubble->SetActive(false);

	//Inventory.push_back("WOOD");
	//Inventory.push_back("WOOD");
	//Inventory.push_back("WOOD");
}
RimCharacter::~RimCharacter()
{
	delete cirlce;
	delete AI;
	delete Work_Process;
	delete Speech_Bubble;
}

void RimCharacter::Update()
{
	moveSpeed = 500.0f;
	funyCHAM = false;
	MyJob = 0;
	MytileXY = CM->tiledatapos[Mytile]->myXY;

	onOFF = false;
	sleepCHAM = false;
	funyCHAM = false;
	vusdksCHAM = false;
	dhlcnfCHAM = false;
	AI->Update();

	HSFVD(4, 4, 4, 4, 4);

	Work_Process->SetActive(false);
	jigumTime();
	// LateJobControl();

	MovePath();
	Interaction();

	UpdateWorld();
	cirlce->UpdateWorld();

	Work_Process->Pos() = this->Pos() - (Vector2(25, 26));
	Work_Process->Update();

	Speech_Bubble->Pos() = this->Pos() + (Vector2(0, 35));
	Speech_Bubble->UpdateWorld();

	Hunger_IM();	// �����
	Sleep_IM();		// ����
	Funy_IM();		// ���
	//Vusdks_IM();	// �����
	//Dhlcnf_IM();	// ����
}

void RimCharacter::Render()
{
	Quad::Render();
	// cirlce->Render();
	if (Work_Process->Active())
	{
		Work_Process->Render();
	}
	if (Speech_Bubble->Active())
	{
		Speech_Bubble->Render();
	}
}
void RimCharacter::PostRender()
{
	if (ImGui::TreeNode(tag.c_str()))
	{
		RenderUI();

		string aaa = tag + "[Mood]";
		ImGui::DragFloat(aaa.c_str(), (float*)&AI->chongHap_feel, 1.0f);
		aaa = tag + "[Hunger]";
		ImGui::DragFloat(aaa.c_str(), (float*)&AI->hunger, 1.0f);
		aaa = tag + "[Sleep]";
		ImGui::DragFloat(aaa.c_str(), (float*)&AI->sleep, 1.0f);
		aaa = tag + "[Fun]";
		ImGui::DragFloat(aaa.c_str(), (float*)&AI->funy, 1.0f);
		aaa = tag + "[Comfort]";
		ImGui::DragFloat(aaa.c_str(), (float*)&AI->vusdks, 1.0f);
		aaa = tag + "[Outing]";
		ImGui::DragFloat(aaa.c_str(), (float*)&AI->dhlcnf, 1.0f);

		ImGui::TreePop();
	}
}
void RimCharacter::MovePath()
{
	if (path.empty())
		return;

	Vector2 direction = path.back() - Pos();
	Rot().z = direction.Angle();

	Pos() += Right() * moveSpeed * DELTA;

	if (direction.Length() < 5.0f)
		path.pop_back();
}

// 4�������� �̵��Ҷ� ������ �ִ� �Լ�
int RimCharacter::Sabangvalue()
{
	int value = Random(1, 5);

	if (value == 1)
	{
		return 1;
	}
	else if (value == 2)
	{
		return (-1);
	}
	else if (value == 3)
	{
		return 31;
	}
	else if (value == 4)
	{
		return (-31);
	}
}

void RimCharacter::jigumTime()
{
	Speech_Bubble->SetActive(false);

	if (AI->hunger >= 50)
	{
		serch2 = true;
	}
	if (dlf[UIS->Hour] != SLEEPTIME)
	{
		serch3 = true;
	}

	if (pic) // �ʹ� �ǰ��ؼ� ������
	{
		sleepCHAM = true;
		moving = false;

		Speech_Bubble->SetActive(true);
		Speech_Bubble->SetTexture(sleep);
		EndTile = Mytile;

		vusdksCHAM = false;
		realTime_myJOB = false;
		JobTile = nullptr;
		HSFVD(2, 6, 0, 2, 0);

		if (AI->sleep >= 50) pic = false;
	}
	else if (AI->hunger <= 20)
	{
		BreakFood();
		MyJob = 0;
	}
	else if (AI->sleep <= 0)
	{
		pic = true;
		MyJob = 0;
	}
	else if (dlf[UIS->Hour] == FREETIME)
	{
		WorkTimeF();
	}
	else if (dlf[UIS->Hour] == WORKTIME)
	{
		WorkTimeW();
	}
	else if (dlf[UIS->Hour] == JOYTIME)
	{
		WorkTimeJ();
		MyJob = 0;
	}
	else if (dlf[UIS->Hour] == SLEEPTIME)
	{
		WorkTimeS();
		MyJob = 0;
	}
}

// �۾� ������
void RimCharacter::WorkTimeF() // �����ð�
{
	// ����
	if (AI->funy <= 10)
	{
		WorkTimeJ();
		chamsssssssss = true;
	}
	else if (chamsssssssss)
	{
		if (AI->funy >= 80)chamsssssssss = false;

		WorkTimeJ();
	}
	else if ((scheDule[0]->GetDown001() && JobReserch1) ||
		(scheDule[1]->GetDown001() && JobReserch2) ||
		(scheDule[2]->GetDown001() && JobReserch3) ||
		(scheDule[3]->GetDown001() && JobReserch4) ||
		(scheDule[4]->GetDown001() && JobReserch5) ||
		(scheDule[5]->GetDown001() && JobReserch6) ||
		(scheDule[6]->GetDown001() && JobReserch7))
	{
		WorkTimeW();
	}
	else
	{
		RandomMoving();
		serch = false;
	}
}
void RimCharacter::WorkTimeW() // �۾��ð�
{
	// ġ�� (�λ���� ���� ġ��)
	if (scheDule[0]->GetDown001() && JobReserch1 && impossibleJOB1)
	{
		MyJob = 1;
	}
	// �޽� (�λ������ ���)
	else if (scheDule[1]->GetDown001() && JobReserch2 && impossibleJOB2)
	{
		MyJob = 2;
	}
	// �Ǽ� (���๰ �Ǽ�, ö��)
	else if (scheDule[2]->GetDown001() && JobReserch3 && impossibleJOB3)
	{
		MyJob = 3;
	}
	// ��� (�Ĺ����, ����, ����)
	else if (scheDule[3]->GetDown001() && JobReserch4 && impossibleJOB4)
	{
		MyJob = 4;
	}
	// ä�� (ä��)
	else if (scheDule[4]->GetDown001() && JobReserch5 && impossibleJOB5)
	{
		MyJob = 5;
	}
	// ���� (����)
	else if (scheDule[5]->GetDown001() && JobReserch6 && impossibleJOB6)
	{
		MyJob = 6;
	}
	// ��� (���ٴڿ� ������ �������� �ű�)
	else if (scheDule[6]->GetDown001() && JobReserch7 && impossibleJOB7)
	{
		// �ϴ� ����
		bool UnDain = false;
		if (HvaeItem("WOOD"))
		{
			carrying();
			moving = true;
			if (JobTile == nullptr)
			{
				JobTile = CM->rimSetTile(JinhangJungTile); // Ÿ�� ������ �޾ƿ�

				if (JobTile->TileCHildren->Chest.size() >= JobTile->TileCHildren->MaxItem)
				{
					TargetTileSerch_Interaction(CM->TileInteractiondata, "CHEST", JinhangJungTile);
				}

				CM->rimTargetNumber[RIMNUMBER] = JinhangJungTile;
			}

			// ��ǥ Ÿ���� �����¿� ���� ������
			if (JinhangJungTile + 31 == Mytile || JinhangJungTile - 31 == Mytile
				|| JinhangJungTile + 1 == Mytile || JinhangJungTile - 1 == Mytile)
			{
				UnDain = true;
				onOFF = true;
			}

			if (UnDain)
			{
				moving = false;
				Inven_ChestOUT("WOOD");
				FinishedJOB = true;
				IsJOB_007 = false;
			}
		}
		else
		{
			impossibleJOB1 = false;
			impossibleJOB2 = false;
			impossibleJOB3 = false;
			impossibleJOB4 = false;
			impossibleJOB5 = false;
			impossibleJOB6 = false;
			impossibleJOB7 = false;
			realTime_myJOB = false;
			JobTile = nullptr;
			return;
		}
	}
	// ���� ���� (�۾��� �� ������ �ƴ� ��) [���� ���� ����]
	else
	{
		RandomMoving();
		serch = false;
	}
}
void RimCharacter::WorkTimeW_RealJOB()
{
	//if (dlf[UIS->Hour] == SLEEPTIME) return;

	if (IsJOB_001)
	{

	}
	else if (IsJOB_002)
	{

	}
	else if (IsJOB_003)
	{
		if (JobTile != nullptr && !JobTile->TileCHildren->buildON && !JobTile->Floortile->buildON)
		{
			//���� ������ ���°� �ƴ϶��
			carrying("COS"); // ��� �Լ� ȣ�� ��
			return; // �ش� �Լ� ��ü ����
		}
		else if (realTime_myJOB)
		{
			bool dlatl = false;

			if (JinhangJungTile + 31 == Mytile || JinhangJungTile - 31 == Mytile
				|| JinhangJungTile + 1 == Mytile || JinhangJungTile - 1 == Mytile)
			{
				dlatl = true;
			}
			else
			{
				Work_Process->SetActive(false);
				jingjingjing = 0.0f;
				dlatl = false;
			}

			if (dlatl && JobTile != nullptr && (JobTile->TileCHildren->buildON || JobTile->Floortile->buildON))
			{
				Work_Process->SetActive(true);
				moving = false;

				onOFF = true;

				jingjingjing += DELTA;
				HSFVD(12, 8, 8, 8, 1);
				if (jingjingjing >= 1)
				{
					jingjingjing = 0.0f; // ���μ����� ������
					JinhangJung = false; // �� ����
					JOB_complete = true; // �굵 ����
					realTime_myJOB = false; // ���� �۾����ΰ�?
					moving = true; // ������ Ȱ��ȭ
					JOB_complete = false; // ��¥ ����

					for (int i = 0; i < CM->Builddatas.size(); ++i)
					{
						if (CM->Builddatas[i].first == JinhangJungTile)
						{
							CM->Builddatas.erase(CM->Builddatas.begin() + i);
							break;
						}
					}
					JobTile->TileTEXChange(); // ���� �۾����� Ÿ���� ���� ����
					JobTile = nullptr; // Ÿ���� ���� ������ ������ ���� ��
					FinishedJOB = true;
					IsJOB_003 = false;
				}
				Work_Process->Scale() = Vector2(0.1f * (jingjingjing / 1), 0.1f);
			}
		}
		else
		{
			impossibleJOB1 = false;
			impossibleJOB2 = false;
			impossibleJOB3 = false;
			JobTile = nullptr;
			realTime_myJOB = false;
		}
	}
	else if (IsJOB_004)
	{
		bool dlatl = false;

		if (realTime_myJOB)
		{
			if (JinhangJungTile + 31 == Mytile || JinhangJungTile - 31 == Mytile
				|| JinhangJungTile + 1 == Mytile || JinhangJungTile - 1 == Mytile)
			{
				dlatl = true;
			}
			else
			{
				Work_Process->SetActive(false);
				jingjingjing = 0.0f;
			}

			if (dlatl)
			{
				Work_Process->SetActive(true);
				moving = false;

				jingjingjing += DELTA;
				HSFVD(12, 8, 8, 8, 1);
				if (jingjingjing >= 1)
				{
					jingjingjing = 0.0f;
					JinhangJung = false;
					JOB_complete = true;
					realTime_myJOB = false;
					JobTile->TileCHildren->ChangeNull();
					for (int i = 0; i < UIS->SelectMarker.size(); ++i)
					{
						if (JinhangJungTile == UIS->SelectMarker[i]->Mynumber)
						{
							if (UIS->SelectMarker[i]->myjob == "WOOD")
							{
								Inven_GetItem("WOOD", 5);
							}
							UIS->SelectMarker.erase(UIS->SelectMarker.begin() + i);
						}
					}

					for (int i = 0; i < CM->Builddatas.size(); ++i)
					{
						if (CM->Builddatas[i].first == JinhangJungTile)
						{
							CM->Builddatas.erase(CM->Builddatas.begin() + i);
							break;
						}
					}
					JobTile = nullptr;
					JOB_complete = false;
					moving = true;
					FinishedJOB = true;
					IsJOB_004 = false;
				}

				Work_Process->Scale() = Vector2(0.1f * (jingjingjing / 1), 0.1f);
			}
		}
	}
	else if (IsJOB_005)
	{

	}
	else if (IsJOB_006)
	{

	}
}
void RimCharacter::WorkTimeJ() // �����ð�
{
	funyCHAM = true;
	HSFVD(8, 8, 50, 8, 0);
	moveSpeed = 1000.0f;
	Speech_Bubble->SetActive(true);
	Speech_Bubble->SetTexture(run);
	RandomMoving();
	serch = false;
}
void RimCharacter::WorkTimeS() // ����ð�
{
	sleepCHAM = true;
	MyJob = 0;

	if (Bad != nullptr && Bad->TileCHildren->Active())
	{
		if (serch3)
		{
			moving = true;
			serch3 = false;
		}

		EndTile = Bad->node1->index;
		if (Bad->GetCollider()->IsCircleCollision((CircleCollider*)cirlce))
		{
			moving = false;

			Speech_Bubble->SetActive(true);
			Speech_Bubble->SetTexture(sleep);

			realTime_myJOB = false;
			JobTile = nullptr;

			vusdksCHAM = true;
			HSFVD(2, 12, 0, 50, 0);
		}
	}
	else
	{
		moving = false;

		Speech_Bubble->SetActive(true);
		Speech_Bubble->SetTexture(sleep);
		EndTile = Mytile;

		vusdksCHAM = false;
		realTime_myJOB = false;
		JobTile = nullptr;
		HSFVD(2, 6, 0, 2, 0);
	}
}

// ������ �۾��� �����ϴ� �����ൿ
void RimCharacter::BreakFood()
{
	if (serch2)
	{
		int food_COUNT = 0;
		bool dlatlqorhvma = false;

		moving = true;
		JinhangJung = true;

		for (int i = 0; i < Inventory.size(); ++i)
		{
			if (Inventory[i] == "FOOD")
			{
				Inventory.erase(Inventory.begin() + i);

				AI->hunger += 50;
				food_COUNT++;
				moving = false;
			}
		}
		if (moving)
		{

		}

		if (food_COUNT == 0)
		{
			TargetTileSerch("FOOD");

			if (JinhangJungTile + 31 == Mytile || JinhangJungTile - 31 == Mytile
				|| JinhangJungTile + 1 == Mytile || JinhangJungTile - 1 == Mytile)
			{
				dlatlqorhvma = true;
			}

			if (dlatlqorhvma)
			{
				Inven_GetItem("FOOD", 3);
			}
		}


		serch2 = false;
	}
}

// ġ��, �޽�, �Ǽ�, ���, ä��, ����, ���
// ĵ��, ö��, ����

void RimCharacter::MytileXYData()
{
	int min = 0;
	int max = 30;
	for (int j = 1; j < 32; ++j)
	{
		if (Mytile >= min && Mytile <= max)
		{
			MytileXY.first = Mytile - min;
			MytileXY.second = j;
			break;
		}
		min += 31;
		max += 31;
	}
}
void RimCharacter::TargetTileSerch(string STRtiledata, int path)
{
	MytileXYData();
	vector<int> foodtile;
	for (int i = 0; i < tiledata.size(); ++i)
	{
		if (path == -1)
		{
			if (tiledata[i].second == STRtiledata)
			{
				foodtile.push_back(tiledata[i].first);
			}
		}
		else if (tiledata[i].second == STRtiledata)
		{
			if (tiledata[i].first != path)
			{
				foodtile.push_back(tiledata[i].first);
			}
		}
	}

	// �޾ƿ� �������� ���� Ÿ�Ͽ����� ��ġ ����ϱ�
	vector<pair<int, int>> XY;
	int min = 0;
	int max = 30;
	for (int i = 0; i < foodtile.size(); ++i)
	{
		min = 0;
		max = 30;
		for (int j = 1; j < 32; ++j)
		{
			if (foodtile[i] >= min && foodtile[i] <= max)
			{
				pair<int, int> xy;
				xy.first = (foodtile[i] - min) - MytileXY.first;
				xy.second = j - MytileXY.second;
				xy.first = abs(xy.first);
				xy.second = abs(xy.second);

				XY.push_back(xy);
				break;
			}
			min += 31;
			max += 31;
		}
	}

	// xy�� ���� �⺻���� �Ÿ��� ���� ����
	vector< pair<int, int>> Tilenumber_sumXY;
	for (int i = 0; i < foodtile.size(); ++i)
	{
		pair<int, int> dlatl;
		int sumdata = XY[i].first + XY[i].second;
		dlatl.first = foodtile[i];
		dlatl.second = sumdata;

		Tilenumber_sumXY.push_back(dlatl);
	}
	XY.clear();

	// �Ÿ��� �� �ͺ��� ����
	while (Tilenumber_sumXY.size() > 1)
	{
		if (Tilenumber_sumXY[0].second < Tilenumber_sumXY[1].second)
		{
			Tilenumber_sumXY.erase(Tilenumber_sumXY.begin() + 1);
		}
		else
		{
			Tilenumber_sumXY.erase(Tilenumber_sumXY.begin());
		}
	}

	int api = Sabangvalue();
	if (Tilenumber_sumXY.size() != 0)
	{
		EndTile = Tilenumber_sumXY[0].first + api;
		JinhangJungTile = Tilenumber_sumXY[0].first;
		if (EndTile < 0) EndTile -= api;
		if (EndTile > 960) EndTile -= api;
	}
}
void RimCharacter::TargetTileSerch_plant(string STRtiledata, int path)
{
	MytileXYData();
	vector<int> foodtile;
	for (int i = 0; i < UIS->SelectMarker.size(); ++i)
	{
		if (path == -1)
		{
			if (UIS->SelectMarker[i]->myjob == STRtiledata)
			{
				foodtile.push_back(UIS->SelectMarker[i]->Mynumber);
			}
		}
		else if (UIS->SelectMarker[i]->myjob == STRtiledata)
		{
			if (UIS->SelectMarker[i]->Mynumber != path)
			{
				foodtile.push_back(UIS->SelectMarker[i]->Mynumber);
			}
		}
	}

	// �޾ƿ� �������� ���� Ÿ�Ͽ����� ��ġ ����ϱ�
	vector<pair<int, int>> XY;
	int min = 0;
	int max = 30;
	for (int i = 0; i < foodtile.size(); ++i)
	{
		min = 0;
		max = 30;
		for (int j = 1; j < 32; ++j)
		{
			if (foodtile[i] >= min && foodtile[i] <= max)
			{
				pair<int, int> xy;
				xy.first = (foodtile[i] - min) - MytileXY.first;
				xy.second = j - MytileXY.second;
				xy.first = abs(xy.first);
				xy.second = abs(xy.second);

				XY.push_back(xy);
				break;
			}
			min += 31;
			max += 31;
		}
	}

	vector< pair<int, int>> Tilenumber_sumXY;
	for (int i = 0; i < foodtile.size(); ++i)
	{
		pair<int, int> dlatl;
		int sumdata = XY[i].first + XY[i].second;
		dlatl.first = foodtile[i];
		dlatl.second = sumdata;

		Tilenumber_sumXY.push_back(dlatl);
	}

	while (Tilenumber_sumXY.size() > 1)
	{
		if (Tilenumber_sumXY[0].second < Tilenumber_sumXY[1].second)
		{
			Tilenumber_sumXY.erase(Tilenumber_sumXY.begin() + 1);
		}
		else
		{
			Tilenumber_sumXY.erase(Tilenumber_sumXY.begin());
		}
	}

	/* 4 ���⿡ ���� ������ ������
	int api = Sabangvalue();
	if (Tilenumber_sumXY.size() != 0)
	{
		EndTile = Tilenumber_sumXY[0].first + api;
		JinhangJungTile = Tilenumber_sumXY[0].first;
		if (EndTile < 0) EndTile -= api;
		if (EndTile > 960) EndTile -= api;
	}
	*/

	vector<int> sabang;
	if (Tilenumber_sumXY[0].first - 1 > 0 && Tilenumber_sumXY[0].first - 31 > 0)
	{
		sabang.push_back(Tilenumber_sumXY[0].first - 1);
		sabang.push_back(Tilenumber_sumXY[0].first - 31);
	}
	else
	{
		sabang.push_back(0);
	}

	if (Tilenumber_sumXY[0].first + 31 < 961 && Tilenumber_sumXY[0].first + 1 < 961)
	{
		sabang.push_back(Tilenumber_sumXY[0].first + 1);
		sabang.push_back(Tilenumber_sumXY[0].first + 31);
	}
	else
	{
		sabang.push_back(960);
	}

	Tilenumber_sumXY.clear();

	// xy�� ��ǥ�� �޾ƿ�
	for (int i = 0; i < sabang.size(); ++i)
	{
		min = 0;
		max = 30;
		for (int j = 1; j < 32; ++j)
		{
			if (sabang[i] >= min && sabang[i] <= max)
			{
				pair<int, int> xy;
				xy.first = (sabang[i] - min) - MytileXY.first;
				xy.second = j - MytileXY.second;
				xy.first = abs(xy.first);
				xy.second = abs(xy.second);

				XY.push_back(xy);
				break;
			}
			min += 31;
			max += 31;
		}
	}

	for (int i = 0; i < foodtile.size(); ++i)
	{
		pair<int, int> dlatl;
		int sumdata = XY[i].first + XY[i].second;
		dlatl.first = foodtile[i];
		dlatl.second = sumdata;

		Tilenumber_sumXY.push_back(dlatl);
	}
	XY.clear();

	while (Tilenumber_sumXY.size() > 1)
	{
		if (Tilenumber_sumXY[0].second < Tilenumber_sumXY[1].second)
		{
			Tilenumber_sumXY.erase(Tilenumber_sumXY.begin() + 1);
		}
		else
		{
			Tilenumber_sumXY.erase(Tilenumber_sumXY.begin());
		}
	}

	if (Tilenumber_sumXY.size() != 0)
	{
		saveMyTiledata = Tilenumber_sumXY[0];
	}

}
void RimCharacter::TargetTileSerch_Interaction(vector<pair<int, string>> data, string STRtiledata, int path)
{
	MytileXYData();
	vector<int> foodtile;
	for (int i = 0; i < data.size(); ++i)
	{
		if (path == -1)
		{
			if (data[i].second == STRtiledata)
			{
				foodtile.push_back(data[i].first);
			}
		}
		else if (data[i].second == STRtiledata)
		{
			if (data[i].first != path)
			{
				foodtile.push_back(data[i].first);
			}
		}
	}

	// �޾ƿ� �������� ���� Ÿ�Ͽ����� ��ġ ����ϱ�
	vector<pair<int, int>> XY;
	int min = 0;
	int max = 30;
	for (int i = 0; i < foodtile.size(); ++i)
	{
		min = 0;
		max = 30;
		for (int j = 1; j < 32; ++j)
		{
			if (foodtile[i] >= min && foodtile[i] <= max)
			{
				pair<int, int> xy;
				xy.first = (foodtile[i] - min) - MytileXY.first;
				xy.second = j - MytileXY.second;
				xy.first = abs(xy.first);
				xy.second = abs(xy.second);

				XY.push_back(xy);
				break;
			}
			min += 31;
			max += 31;
		}
	}

	vector< pair<int, int>> Tilenumber_sumXY;
	for (int i = 0; i < foodtile.size(); ++i)
	{
		pair<int, int> dlatl;
		int sumdata = XY[i].first + XY[i].second;
		dlatl.first = foodtile[i];
		dlatl.second = sumdata;

		Tilenumber_sumXY.push_back(dlatl);
	}

	while (Tilenumber_sumXY.size() > 1)
	{
		if (Tilenumber_sumXY[0].second < Tilenumber_sumXY[1].second)
		{
			Tilenumber_sumXY.erase(Tilenumber_sumXY.begin() + 1);
		}
		else
		{
			Tilenumber_sumXY.erase(Tilenumber_sumXY.begin());
		}
	}

	int api = Sabangvalue();
	if (Tilenumber_sumXY.size() != 0)
	{
		EndTile = Tilenumber_sumXY[0].first + api;
		JinhangJungTile = Tilenumber_sumXY[0].first;
		if (EndTile < 0) EndTile -= api;
		if (EndTile > 960) EndTile -= api;
	}
}
void RimCharacter::RandomMoving()
{
	JobTile = nullptr;
	random_moving -= DELTA;
	if (random_moving <= 0)
	{
		random_moving = max_random_moving;
		moving = true;
		serch = true;
	}
	else
	{
		// �ǹ�
		// ���� �� �� �ִ� �۾��� ���� ���
		// �̷��� ���� ������ ���콺 ���ʹ�ư�� Ŭ���� �� ���� ����ؼ� �������� �߻���
		moving = false;
	}

	EndTile = Mytile;

	int abcdefg;
	abcdefg = Random(3, 6);

	max_random_moving = Random(1, 5);

	for (int h = 0; h < abcdefg; ++h)
	{
		int api = Sabangvalue();
		EndTile += api;
		if (EndTile < 0) EndTile -= api;
		if (EndTile > 960) EndTile -= api;
	}
	for (int it = 0; it < tiledata.size(); ++it)
	{
		if (tiledata[it].first == EndTile)
		{
			int api = Sabangvalue();
			EndTile += api;
			if (EndTile < 0) EndTile -= api;
			if (EndTile > 960) EndTile -= api;
			continue;
		}
	}
}
void RimCharacter::FINIJOB()
{
	if (KEY_DOWN(VK_LBUTTON) || FinishedJOB)
	{
		impossibleJOB1 = true;
		impossibleJOB2 = true;
		impossibleJOB3 = true;
		impossibleJOB4 = true;
		impossibleJOB5 = true;
		impossibleJOB6 = true;
		impossibleJOB7 = true;

		FinishedJOB = false;
	}
}

void RimCharacter::Interaction()
{
	if (JinhangJung)
	{
		if (JinhangJungTile + 31 == Mytile)
		{
			Work_Process->SetActive(true);
			moving = false;

			jingjingjing += DELTA;
			if (jingjingjing >= 1)
			{
				jingjingjing = 0.0f;
				JinhangJung = false;
				AI->hunger += 70;
				if (AI->hunger <= 20)
				{
					JinhangJung = true;
				}
			}

			Work_Process->Scale() = Vector2(0.1f * (jingjingjing / 1), 0.1f);
		}
		else if (JinhangJungTile - 31 == Mytile)
		{
			Work_Process->SetActive(true);
			moving = false;

			jingjingjing += DELTA;
			if (jingjingjing >= 1)
			{
				jingjingjing = 0.0f;
				JinhangJung = false;
				AI->hunger += 70;
				if (AI->hunger <= 20)
				{
					JinhangJung = true;
				}
			}

			Work_Process->Scale() = Vector2(0.1f * (jingjingjing / 1), 0.1f);
		}
		else if (JinhangJungTile + 1 == Mytile)
		{
			Work_Process->SetActive(true);
			moving = false;

			jingjingjing += DELTA;
			if (jingjingjing >= 1)
			{
				jingjingjing = 0.0f;
				JinhangJung = false;
				AI->hunger += 70;
				if (AI->hunger <= 20)
				{
					JinhangJung = true;
				}
			}

			Work_Process->Scale() = Vector2(0.1f * (jingjingjing / 1), 0.1f);
		}
		else if (JinhangJungTile - 1 == Mytile)
		{
			Work_Process->SetActive(true);
			moving = false;

			jingjingjing += DELTA;
			if (jingjingjing >= 1)
			{
				jingjingjing = 0.0f;
				JinhangJung = false;
				AI->hunger += 70;
				if (AI->hunger <= 20)
				{
					JinhangJung = true;
				}
			}

			Work_Process->Scale() = Vector2(0.1f * (jingjingjing / 1), 0.1f);
		}
		else
		{
			Work_Process->SetActive(false);
			jingjingjing = 0.0f;
		}
	}
}

void RimCharacter::LateJobControl()
{

	FINIJOB();
	// ġ��
	if (MyJob == 1 && impossibleJOB1)
	{

	}
	// �޽�
	else if (MyJob == 2 && impossibleJOB2)
	{

	}
	// �Ǽ�
	else if (MyJob == 3 && impossibleJOB3)
	{

	}
	// ���
	else if (MyJob == 4 && impossibleJOB4)
	{
		int zero4 = JinhangJungTile;
		// �ڽŰ��� �Ÿ��� ���Ͽ� ���� ����� ���� �ִ� �۾��� �Ǻ�
		TargetTileSerch_plant("WOOD");

		// �ٸ� ������ ������ �ִ� (JinhangJungTile) ������ �޾ƿ� �ڽŰ� ���� ���� ������ �ִ����� �Ǻ�
		// ���� ���� ���� ������ �ִٸ� �ٸ� ���� �ٽ� �޾ƿ�
		for (int i = 0; i < CM->rimTargetNumber.size(); ++i)
		{
			if (i != RIMNUMBER) // �� ��ȣ�� ���� �ƴ� ���
			{
				if (CM->rimTargetNumber[i] == JinhangJungTile) // �ٸ� ���� ���� ������ �ִ� ������ ��ġ�� ��� �ٸ� �����ͷ� ����
				{
					TargetTileSerch_plant("WOOD", JinhangJungTile); // �ش� ���� �����ϰ� �ٽ� ��θ� �ٽ� Ž��

					JobTile = CM->rimSetTile(JinhangJungTile); // Ÿ�� ������ �ٽ� ���Ҵ�
					CM->rimTargetNumber[RIMNUMBER] = JinhangJungTile;
				}
			}
		}

		if (zero4 == JinhangJungTile) // Ž�� �Ŀ��� ���� ������ ���ٸ� ��ȿȭ
		{
			moving = false;
			realTime_myJOB = false;
			JinhangJungTile = Mytile;
			CM->rimTargetNumber[RIMNUMBER] = JinhangJungTile;

			impossibleJOB1 = false;
			impossibleJOB2 = false;
			impossibleJOB3 = false;
			impossibleJOB4 = false;
		}

		/*
		���� ���� : ���� �ڽ��� �����ؾ� �ϴ� �۾����� ĵ������ ����..
					���⼭ �̷��� �۾��� �ع����� ��� �۾��� �����ϰ� �����
		*/
	}
	// ä��
	else if (MyJob == 5 && impossibleJOB5)
	{

	}
	// ����
	else if (MyJob == 6 && impossibleJOB6)
	{

	}
	// ���
	else if (MyJob == 7 && impossibleJOB7)
	{

	}


	MyJob = 0;
}

void RimCharacter::Inven_GetItem(IN string name, IN int stack)
{
	for (int i = 0; i < stack; ++i)
	{
		if (Inventory.size() > Max_inven) return;
		// �κ��丮�� �������� �ƽ� ������ �� ���� �������� �ϸ� �Լ� ��!!

		Inventory.push_back(name);
	}
}
void RimCharacter::Inven_OutItem()
{
	if (JobTile == nullptr) return;

	if (JobTile->OBJTTT)
	{
		for (int i = 0; i < Inventory.size(); ++i)
		{
			if (Inventory[i] == "WOOD" && // ���� �κ��丮�� ������ �ְ�
				JobTile->TileCHildren->woon.size() != JobTile->TileCHildren->stack)
				// ������ Ÿ���� woon ������� stack�� ���� ��ġ���� ������
			{
				JobTile->TileCHildren->woon.push_back(Inventory[i]); // �κ��丮�� ���� �Ҵ� ��
				Inventory.erase(Inventory.begin() + i); // �ڽ��� �κ��丮���� �ش� ���� ����
			}

			if (JobTile->TileCHildren->woon.size() >= JobTile->TileCHildren->stack)
			{
				// ������(����)���� ������ �� �۰ų� ������ �ݺ��� ����
				// �ִ� ������ ä���ٴ� �� (�Ǽ��� ������ ��Ȳ)
				break;
			}
		}
	}

	if (JobTile->TILE)
	{
		for (int i = 0; i < Inventory.size(); ++i)
		{
			if (Inventory[i] == "WOOD" && // ���� �κ��丮�� ������ �ְ�
				JobTile->Floortile->woon.size() != JobTile->Floortile->stack)
				// ������ Ÿ���� woon ������� stack�� ���� ��ġ���� ������
			{
				JobTile->Floortile->woon.push_back(Inventory[i]); // �κ��丮�� ���� �Ҵ� ��
				Inventory.erase(Inventory.begin() + i); // �ڽ��� �κ��丮���� �ش� ���� ����
			}

			if (JobTile->Floortile->woon.size() >= JobTile->Floortile->stack)
			{
				// ������(����)���� ������ �� �۰ų� ������ �ݺ��� ����
				// �ִ� ������ ä���ٴ� �� (�Ǽ��� ������ ��Ȳ)
				break;
			}
		}
	}

}
void RimCharacter::Inven_ChestGetIN(string item)
{
	if (JobTile->TileCHildren == nullptr) return;

	for (int i = 0; i < JobTile->TileCHildren->Chest.size(); ++i)
	{
		if (JobTile->TileCHildren->Chest[i] == item)
		{
			if (Inventory.size() > Max_inven) return;
			Inventory.push_back(JobTile->TileCHildren->Chest[i]);
			JobTile->TileCHildren->Chest.erase(JobTile->TileCHildren->Chest.begin() + i);
		}
	}
}
void RimCharacter::Inven_ChestOUT(string item)
{
	if (JobTile == nullptr) return;

	for (int i = 0; i < Inventory.size(); ++i)
	{
		if (Inventory[i] == item)
		{
			JobTile->TileCHildren->Chest.push_back(Inventory[i]);
			Inventory.erase(Inventory.begin() + i);
		}
	}
}
bool RimCharacter::HvaeItem(string item)
{
	for (int i = 0; i < Inventory.size(); ++i)
	{
		if (Inventory[i] == item)
		{
			return true;
		}
	}

	return false;
}

void RimCharacter::carrying(string carry)
{
	bool dlqtlffhs = false;

	vector<string> woodstack;
	vector<pair<int, string>> chestStack;
	for (int i = 0; i < Inventory.size(); ++i)
	{
		if (Inventory[i] == "WOOD")
		{
			woodstack.push_back(Inventory[i]);
		}
	}
	for (int i = 0; i < CM->TileInteractiondata.size(); ++i)
	{
		if (CM->TileInteractiondata[i].second == "CHEST")
		{
			if (CM->tiledatapos[CM->TileInteractiondata[i].first]->TileCHildren->NotItem()) continue;

			chestStack.push_back(CM->TileInteractiondata[i]);
		}
	}

	// ������ ��� �ڽ��� ���� �������� ���ڷ� �ű�� ��
	// �� ��� �� -> ����
	// ��� 1
	if (carry == "CHEST")
	{
		TargetTileSerch_Interaction(CM->TileInteractiondata, "CHEST");
	}
	// �Ǽ������� ��� �ڽ��� ���� �������� �Ǽ��������� �ű�
	// �� ��� �� -> �Ǽ�����
	// �ڽ��� ������ ������ ���� �ʴٸ� �ش� �۾��� ����
	// �� ��� ���� �۾����� ����
	// ���ڿ� ������ �ִٸ� ���ڱ��� �̵��Ͽ� ������ �ڽ��� �κ��丮�� �ְ� �Ǽ��������� �ű�
	// �� ��� �� -> ����(�������� ����) -> �Ǽ�����
	// ��� 3
	else if (carry == "COS")
	{
		// ����� 0���� ũ�ٴ� ���� �κ��丮�� �̸�ŭ�� ������ �ִٴ� �ǹ� (������ ���� ���)
		if (woodstack.size() > 0)
		{
			if (JinhangJungTile + 31 == Mytile || JinhangJungTile - 31 == Mytile
				|| JinhangJungTile + 1 == Mytile || JinhangJungTile - 1 == Mytile)
			{
				dlqtlffhs = true;
			}

			if (dlqtlffhs)
			{
				Inven_OutItem();
			}
		}
		// ü��Ʈ ������ ����� 0�� �ƴ϶�� �ʵ� �߿� ü��Ʈ ������Ʈ�� �ϳ� �̻��� �ִٴ� �ǹ�
		else if (chestStack.size() != 0)
		{
			TargetTileSerch_Interaction(chestStack, "CHEST");
			moving = true;

			if (JinhangJungTile + 31 == Mytile || JinhangJungTile - 31 == Mytile
				|| JinhangJungTile + 1 == Mytile || JinhangJungTile - 1 == Mytile)
			{
				dlqtlffhs = true;
			}

			if (dlqtlffhs)
			{
				Inven_ChestGetIN("WOOD");
			}
		}
		else
		{
			impossibleJOB1 = false;
			impossibleJOB2 = false;
			impossibleJOB3 = false;
			JobTile = nullptr;
			realTime_myJOB = false;
			WorkTimeW();
		}
	}

	/*
	�� �Լ��� ���� : �ڽ��� �κ��丮�� �ִ� �͵��� �ٸ� ������ �ű� ��
	*/
}











void RimCharacter::Hunger_IM()
{
	float non_second = DELTA / UIS->Max_Second;

	AI->hunger -= non_second * AI->HG;
}
void RimCharacter::Sleep_IM()
{
	float non_second = DELTA / UIS->Max_Second;

	if (sleepCHAM) // �ܴ�
	{
		AI->sleep += non_second * AI->SP;
	}
	else if (!sleepCHAM) // �� �ܴ�
	{
		AI->sleep -= non_second * AI->SP;
	}

}
void RimCharacter::Funy_IM()
{
	float non_second = DELTA / UIS->Max_Second;


	if (funyCHAM) AI->funy += non_second * AI->FY; // ��� ��
	else if (!funyCHAM) AI->funy -= non_second * AI->FY; // �� ��..

}
void RimCharacter::Vusdks_IM()
{
	float non_second = DELTA / UIS->Max_Second;

	if (vusdksCHAM) AI->vusdks += non_second * AI->VD; // �޽� ��
	else if (!vusdksCHAM) AI->vusdks -= non_second * AI->VD; // �޽� �ƴ�


}
void RimCharacter::Dhlcnf_IM()
{
	float non_second = DELTA / UIS->Max_Second;

	if (dhlcnfCHAM) AI->dhlcnf -= non_second * AI->DL; // ���� ��
	else if (!dhlcnfCHAM) AI->dhlcnf -= non_second * AI->DL; // �ǳ�
}
void RimCharacter::HSFVD(int hunger, int sleep, int funy, int vusdks, int dhlcnf)
{
	AI->HG = hunger;
	AI->SP = sleep;
	AI->FY = funy;
	AI->VD = vusdks;
	AI->DL = dhlcnf;
}
void RimCharacter::phase1() // ������ ���źҾ�
{

}
void RimCharacter::phase2() // �ɰ��� ���źҾ�
{

}
void RimCharacter::phase3() // �ؽ��� ���źҾ�
{

}

/*
������ ���
ccl ���Ͽ� �ִ� �� ������ ������ �ִ� �ڽ��� Ÿ��Ÿ�� ��ȣ�� for ���� �̿��Ѵ�.

for �������� �ڽ��� �� ��ȣ�� for���� �ݺ��� i�� ���� ���Ͽ� ��ġ���� �ʴ´ٴ� �������� if���� �۵���Ŵ
if�������� �� ������ ���� Ÿ��Ÿ���� ��ȣ�� ��ġ�ϸ� �ٸ� Ÿ�Ϸ� ���� �۵��ϵ��� �Ǿ� ����

������� �۾� ���� �ϳ��� ��� �ش� �۾��� �����ؾ� �ϴ� �� ���� ������ �̵��ϴ� ���� �������� �۵��̳�
���ݰ��� ���� �׷����� ����

�ϳ��� ���� ������ 4���� ��ΰ� �޷��� ���� �ذ��� ���� �۵����� ���� ���ɼ��� ����..


*�����Ǵ� ������*
ó������ ��Ʈ���� �޾ƿ��� �׷��� �ؼ� �޾ƿ� ������ �ٸ� ����� �����͸� ���Ͽ�
�ش� ���� ������ �ٸ� ���� ���Ӱ� �޾ƿ´�.

������ �۾��� �ϳ���� �ٸ� �۾�Ÿ���� ���Ӱ� �޾ƿ��� ���ϹǷ� ���Ӱ� ���� ��������
�Լ��� ����� �۵����� ���ϰ� ������ ������ �ִ� ������ �۵��ϴ� ������ ������
*/

/*
���ο� ���
������ ����� �ش� ���� ���� �ϰ� �ִ� �۾��� ���� ��� ó������ ���� �޴� ���� ��� ���� ��������.

������ ��� �������� �ڿ������� ����� ���ؼ��� �ǽð����� ������ ������ �ʿ䰡 ����,
������ �ǽð����� �۾��� �߰��� �� �ڱ���� ��ġ���� ���� ����� �Ÿ��� �ִ� ��ǥ���� �۾��� ���� �ʿ䰡 ����
������ �ǽð����� ���ο� �۾��� �������� ���ϴ� ������ �̹� �� �� ���� ������ �ٸ� ���� ã�� ������ ���� �ʱ� ����

�� �۾��鸶�� int ������ ��ȣ�� �ű��.

�۾� �Լ� �������� �ش� ��Ʈ�� �۵��ϴ� �Լ��� �ʿ�
�� �Լ����� ��ġ�ϴ����� �ľ�
*/