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

	Hunger_IM();	// 배고픔
	Sleep_IM();		// 수면
	Funy_IM();		// 재미
	//Vusdks_IM();	// 편안함
	//Dhlcnf_IM();	// 외출
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

// 4방향으로 이동할때 도움을 주는 함수
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

	if (pic) // 너무 피곤해서 쓰러짐
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

// 작업 스케줄
void RimCharacter::WorkTimeF() // 자유시간
{
	// 오락
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
void RimCharacter::WorkTimeW() // 작업시간
{
	// 치료 (부상당한 림을 치료)
	if (scheDule[0]->GetDown001() && JobReserch1 && impossibleJOB1)
	{
		MyJob = 1;
	}
	// 휴식 (부상당했을 경우)
	else if (scheDule[1]->GetDown001() && JobReserch2 && impossibleJOB2)
	{
		MyJob = 2;
	}
	// 건설 (건축물 건설, 철거)
	else if (scheDule[2]->GetDown001() && JobReserch3 && impossibleJOB3)
	{
		MyJob = 3;
	}
	// 재배 (식물재배, 제초, 벌목)
	else if (scheDule[3]->GetDown001() && JobReserch4 && impossibleJOB4)
	{
		MyJob = 4;
	}
	// 채굴 (채굴)
	else if (scheDule[4]->GetDown001() && JobReserch5 && impossibleJOB5)
	{
		MyJob = 5;
	}
	// 제련 (미정)
	else if (scheDule[5]->GetDown001() && JobReserch6 && impossibleJOB6)
	{
		MyJob = 6;
	}
	// 운반 (땅바닥에 떨어진 아이템을 옮김)
	else if (scheDule[6]->GetDown001() && JobReserch7 && impossibleJOB7)
	{
		// 일단 봉인
		bool UnDain = false;
		if (HvaeItem("WOOD"))
		{
			carrying();
			moving = true;
			if (JobTile == nullptr)
			{
				JobTile = CM->rimSetTile(JinhangJungTile); // 타일 정보를 받아옴

				if (JobTile->TileCHildren->Chest.size() >= JobTile->TileCHildren->MaxItem)
				{
					TargetTileSerch_Interaction(CM->TileInteractiondata, "CHEST", JinhangJungTile);
				}

				CM->rimTargetNumber[RIMNUMBER] = JinhangJungTile;
			}

			// 목표 타일의 상하좌우 어디든 있으면
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
	// 랜덤 무브 (작업중 그 무엇도 아닐 때) [일이 없는 상태]
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
			//건축 가능한 상태가 아니라면
			carrying("COS"); // 운반 함수 호출 후
			return; // 해당 함수 전체 종료
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
					jingjingjing = 0.0f; // 프로세스바 게이지
					JinhangJung = false; // 얜 뭐지
					JOB_complete = true; // 얘도 뭐지
					realTime_myJOB = false; // 현재 작업중인가?
					moving = true; // 움직임 활성화
					JOB_complete = false; // 진짜 뭐지

					for (int i = 0; i < CM->Builddatas.size(); ++i)
					{
						if (CM->Builddatas[i].first == JinhangJungTile)
						{
							CM->Builddatas.erase(CM->Builddatas.begin() + i);
							break;
						}
					}
					JobTile->TileTEXChange(); // 현재 작업중인 타일의 정보 변경
					JobTile = nullptr; // 타일의 정보 변경이 끝나면 널을 줌
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
void RimCharacter::WorkTimeJ() // 오락시간
{
	funyCHAM = true;
	HSFVD(8, 8, 50, 8, 0);
	moveSpeed = 1000.0f;
	Speech_Bubble->SetActive(true);
	Speech_Bubble->SetTexture(run);
	RandomMoving();
	serch = false;
}
void RimCharacter::WorkTimeS() // 수면시간
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

// 지정된 작업을 무시하는 돌발행동
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

// 치료, 휴식, 건설, 재배, 채굴, 제련, 운반
// 캔슬, 철거, 벌목

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

	// 받아온 정보들을 토대로 타일에서의 위치 계산하기
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

	// xy의 값을 기본으로 거리의 값을 정함
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

	// 거리가 먼 것부터 제거
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

	// 받아온 정보들을 토대로 타일에서의 위치 계산하기
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

	/* 4 방향에 대한 정보를 가져옴
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

	// xy의 좌표를 받아옴
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

	// 받아온 정보들을 토대로 타일에서의 위치 계산하기
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
		// 의미
		// 지금 할 수 있는 작업이 없을 경우
		// 이렇게 하지 않으면 마우스 왼쪽버튼을 클릭할 때 마다 계속해서 움직임이 발생함
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
	// 치료
	if (MyJob == 1 && impossibleJOB1)
	{

	}
	// 휴식
	else if (MyJob == 2 && impossibleJOB2)
	{

	}
	// 건설
	else if (MyJob == 3 && impossibleJOB3)
	{

	}
	// 재배
	else if (MyJob == 4 && impossibleJOB4)
	{
		int zero4 = JinhangJungTile;
		// 자신과의 거리를 비교하여 가장 가까운 곳에 있는 작업을 판별
		TargetTileSerch_plant("WOOD");

		// 다른 림들이 가지고 있는 (JinhangJungTile) 정보를 받아와 자신과 같은 값을 가지고 있는지를 판별
		// 만약 같은 값을 가지고 있다면 다른 값을 다시 받아옴
		for (int i = 0; i < CM->rimTargetNumber.size(); ++i)
		{
			if (i != RIMNUMBER) // 림 번호가 내가 아닐 경우
			{
				if (CM->rimTargetNumber[i] == JinhangJungTile) // 다른 림과 내가 가지고 있는 정보가 일치할 경우 다른 데이터로 변경
				{
					TargetTileSerch_plant("WOOD", JinhangJungTile); // 해당 값을 제외하고 다시 경로를 다시 탐색

					JobTile = CM->rimSetTile(JinhangJungTile); // 타일 정보를 다시 재할당
					CM->rimTargetNumber[RIMNUMBER] = JinhangJungTile;
				}
			}
		}

		if (zero4 == JinhangJungTile) // 탐색 후에도 값에 변동이 없다면 무효화
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
		문제 사항 : 본래 자신이 수행해야 하는 작업조차 캔슬시켜 버림..
					여기서 이러한 작업을 해버리면 모든 작업이 동일하게 진행됨
		*/
	}
	// 채굴
	else if (MyJob == 5 && impossibleJOB5)
	{

	}
	// 제련
	else if (MyJob == 6 && impossibleJOB6)
	{

	}
	// 운반
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
		// 인벤토리에 아이템을 맥스 값보다 더 많이 넣으려고 하면 함수 펑!!

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
			if (Inventory[i] == "WOOD" && // 림의 인벤토리에 나무가 있고
				JobTile->TileCHildren->woon.size() != JobTile->TileCHildren->stack)
				// 오비제 타일의 woon 사이즈와 stack의 값이 일치하지 않을때
			{
				JobTile->TileCHildren->woon.push_back(Inventory[i]); // 인벤토리의 값을 할당 후
				Inventory.erase(Inventory.begin() + i); // 자신의 인벤토리에서 해당 값을 삭제
			}

			if (JobTile->TileCHildren->woon.size() >= JobTile->TileCHildren->stack)
			{
				// 사이즈(갯수)보다 스택이 더 작거나 같으면 반복문 종료
				// 최대 스택을 채웠다는 뜻 (건설이 가능한 상황)
				break;
			}
		}
	}

	if (JobTile->TILE)
	{
		for (int i = 0; i < Inventory.size(); ++i)
		{
			if (Inventory[i] == "WOOD" && // 림의 인벤토리에 나무가 있고
				JobTile->Floortile->woon.size() != JobTile->Floortile->stack)
				// 오비제 타일의 woon 사이즈와 stack의 값이 일치하지 않을때
			{
				JobTile->Floortile->woon.push_back(Inventory[i]); // 인벤토리의 값을 할당 후
				Inventory.erase(Inventory.begin() + i); // 자신의 인벤토리에서 해당 값을 삭제
			}

			if (JobTile->Floortile->woon.size() >= JobTile->Floortile->stack)
			{
				// 사이즈(갯수)보다 스택이 더 작거나 같으면 반복문 종료
				// 최대 스택을 채웠다는 뜻 (건설이 가능한 상황)
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

	// 상자일 경우 자신이 가진 아이템을 상자로 옮기는 것
	// 이 경우 나 -> 상자
	// 경우 1
	if (carry == "CHEST")
	{
		TargetTileSerch_Interaction(CM->TileInteractiondata, "CHEST");
	}
	// 건설현장의 경우 자신이 가진 아이템을 건설현장으로 옮김
	// 이 경우 나 -> 건설현장
	// 자신이 나무를 가지고 있지 않다면 해당 작업을 포기
	// 이 경우 다음 작업으로 이행
	// 상자에 나무가 있다면 상자까지 이동하여 나무를 자신의 인벤토리에 넣고 건설현장으로 옮김
	// 이 경우 나 -> 상자(아이템을 받음) -> 건설현장
	// 경우 3
	else if (carry == "COS")
	{
		// 사이즈가 0보다 크다는 것은 인벤토리에 이만큼의 나무가 있다는 의미 (나무가 있을 경우)
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
		// 체스트 벡터의 사이즈가 0이 아니라면 필드 중에 체스트 오브젝트가 하나 이상은 있다는 의미
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
	이 함수의 역할 : 자신의 인벤토리에 있는 것들을 다른 곳으로 옮길 뿐
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

	if (sleepCHAM) // 잔다
	{
		AI->sleep += non_second * AI->SP;
	}
	else if (!sleepCHAM) // 안 잔다
	{
		AI->sleep -= non_second * AI->SP;
	}

}
void RimCharacter::Funy_IM()
{
	float non_second = DELTA / UIS->Max_Second;


	if (funyCHAM) AI->funy += non_second * AI->FY; // 노는 중
	else if (!funyCHAM) AI->funy -= non_second * AI->FY; // 안 놈..

}
void RimCharacter::Vusdks_IM()
{
	float non_second = DELTA / UIS->Max_Second;

	if (vusdksCHAM) AI->vusdks += non_second * AI->VD; // 휴식 중
	else if (!vusdksCHAM) AI->vusdks -= non_second * AI->VD; // 휴식 아님


}
void RimCharacter::Dhlcnf_IM()
{
	float non_second = DELTA / UIS->Max_Second;

	if (dhlcnfCHAM) AI->dhlcnf -= non_second * AI->DL; // 외출 중
	else if (!dhlcnfCHAM) AI->dhlcnf -= non_second * AI->DL; // 실내
}
void RimCharacter::HSFVD(int hunger, int sleep, int funy, int vusdks, int dhlcnf)
{
	AI->HG = hunger;
	AI->SP = sleep;
	AI->FY = funy;
	AI->VD = vusdks;
	AI->DL = dhlcnf;
}
void RimCharacter::phase1() // 가벼운 정신불안
{

}
void RimCharacter::phase2() // 심각한 정신불안
{

}
void RimCharacter::phase3() // 극심한 정신불안
{

}

/*
기존의 방식
ccl 파일에 있는 각 림들이 가지고 있는 자신의 타겟타일 번호를 for 문을 이용한다.

for 문에서는 자신의 림 번호와 for문의 반복된 i의 값과 비교하여 일치하지 않는다는 조건으로 if문을 작동시킴
if문에서는 각 림들이 가진 타겟타일의 번호가 일치하면 다른 타일로 변경 작동하도록 되어 잇음

본래라면 작업 량이 하나인 경우 해당 작업을 시행해야 하는 한 명의 림만이 이동하는 것이 정상적인 작동이나
지금같은 경우는 그러하지 않음

하나의 일을 받으면 4마리 모두가 달려들어서 일을 해결함 정상 작동하지 않을 가능성이 높음..


*추정되는 문제점*
처음으로 인트값을 받아오면 그렇게 해서 받아온 값으로 다른 림들과 데이터를 비교하여
해당 값을 제외한 다른 값을 새롭게 받아온다.

하지만 작업이 하나라면 다른 작업타일을 새롭게 받아오지 못하므로 새롭게 값을 가져오는
함수가 제대로 작동하지 못하고 기존에 가지고 있던 값으로 작동하는 것으로 추정됨
*/

/*
새로운 방식
기존의 방식은 해당 림이 지금 하고 있는 작업이 없을 경우 처음으로 일을 받는 순간 모든 것이 정해진다.

림들의 모든 움직임을 자연스럽게 만들기 위해서는 실시간으로 정보를 갱신할 필요가 있음,
림들이 실시간으로 작업이 추가될 때 자기와의 위치에서 가장 가까운 거리에 있는 목표물의 작업에 임할 필요가 있음
림들이 실시간으로 새로운 작업을 인지하지 못하는 이유는 이미 한 번 일을 받으면 다른 일을 찾는 연산을 하지 않기 때문

각 작업들마다 int 변수로 번호를 매긴다.

작업 함수 다음으로 해당 인트로 작동하는 함수가 필요
이 함수에서 일치하는지를 파악
*/