#include "Framework.h"

CommanderCCL::CommanderCCL()
{
	rimTargetNumber.resize(4);
	rim1 = new RimCharacter(L"Textures/Tile/Characters/green_character.png", "GreenRim", 0);
	rim2 = new RimCharacter(L"Textures/Tile/Characters/purple_character.png", "PurpleRim", 1);
	rim3 = new RimCharacter(L"Textures/Tile/Characters/red_character.png", "RedRim", 2);
	rim4 = new RimCharacter(L"Textures/Tile/Characters/yellow_character.png", "YellowRim", 3);

	//BALL.push_back(new Soccer_Ball());

	UIS->stc[0]->SetChange(rim1);
	UIS->stc[1]->SetChange(rim2);
	UIS->stc[2]->SetChange(rim3);
	UIS->stc[3]->SetChange(rim4);

	UIS->zero1[0]->SetBOOL(rim1);
	UIS->zero1[1]->SetBOOL(rim2);
	UIS->zero1[2]->SetBOOL(rim3);
	UIS->zero1[3]->SetBOOL(rim4);
}
CommanderCCL::~CommanderCCL()
{
	delete rim1;
	delete rim2;
	delete rim3;
	delete rim4;
}

void CommanderCCL::Update()
{
	TileDataSet();
	Jobduqn();

	rimTargetNumber[0] = rim1->JinhangJungTile;
	rimTargetNumber[1] = rim2->JinhangJungTile;
	rimTargetNumber[2] = rim3->JinhangJungTile;
	rimTargetNumber[3] = rim4->JinhangJungTile;

	rim1->Update();
	rim2->Update();
	rim3->Update();
	rim4->Update();

	LateJobControl();

	rim1->WorkTimeW_RealJOB();
	rim2->WorkTimeW_RealJOB();
	rim3->WorkTimeW_RealJOB();
	rim4->WorkTimeW_RealJOB();

	badSet();

	if (rim1->HvaeItem("WOOD")) job07++;
	if (rim2->HvaeItem("WOOD")) job07++;
	if (rim3->HvaeItem("WOOD")) job07++;
	if (rim4->HvaeItem("WOOD")) job07++;

}
void CommanderCCL::Render()
{
	rim1->Render();
	rim2->Render();
	rim3->Render();
	rim4->Render();
}
void CommanderCCL::PostRender()
{
	string aaa;

	rim1->PostRender();
	rim2->PostRender();
	rim3->PostRender();
	rim4->PostRender();

	if (ImGui::TreeNode("job count"))
	{
		aaa = "count 01 : " + to_string(job01);
		ImGui::Text(aaa.c_str());
		aaa = "count 02 : " + to_string(job02);
		ImGui::Text(aaa.c_str());
		aaa = "count 03 : " + to_string(job03);
		ImGui::Text(aaa.c_str());
		aaa = "count 04 : " + to_string(job04);
		ImGui::Text(aaa.c_str());
		aaa = "count 05 : " + to_string(job05);
		ImGui::Text(aaa.c_str());
		aaa = "count 05 : " + to_string(job06);
		ImGui::Text(aaa.c_str());
		aaa = "count 07 : " + to_string(job07);
		ImGui::Text(aaa.c_str());

		ImGui::TreePop();
	}

	aaa = "1number1 : " + to_string(rim1->realTime_myJOB);
	ImGui::Text(aaa.c_str());

	aaa = "2number2 : " + to_string(rim2->realTime_myJOB);
	ImGui::Text(aaa.c_str());

	aaa = "3number3 : " + to_string(rim3->realTime_myJOB);
	ImGui::Text(aaa.c_str());

	aaa = "4number4 : " + to_string(rim4->realTime_myJOB);
	ImGui::Text(aaa.c_str());

}

void CommanderCCL::TileDataSet()
{
	rim1->tiledata = Builddatas;
	rim2->tiledata = Builddatas;
	rim3->tiledata = Builddatas;
	rim4->tiledata = Builddatas;

	rim1->tkdghwkrdydDATA = TileInteractiondata;
	rim2->tkdghwkrdydDATA = TileInteractiondata;
	rim3->tkdghwkrdydDATA = TileInteractiondata;
	rim4->tkdghwkrdydDATA = TileInteractiondata;
}

void CommanderCCL::Jobduqn()
{
	if (job01 > 0)
	{
		rim1->JobReserch1 = true;
		rim2->JobReserch1 = true;
		rim3->JobReserch1 = true;
		rim4->JobReserch1 = true;
	}
	else
	{
		rim1->JobReserch1 = false;
		rim2->JobReserch1 = false;
		rim3->JobReserch1 = false;
		rim4->JobReserch1 = false;
		job01 = 0;
	}

	if (job02 > 0)
	{
		rim1->JobReserch2 = true;
		rim2->JobReserch2 = true;
		rim3->JobReserch2 = true;
		rim4->JobReserch2 = true;
	}
	else
	{
		rim1->JobReserch2 = false;
		rim2->JobReserch2 = false;
		rim3->JobReserch2 = false;
		rim4->JobReserch2 = false;
		job02 = 0;
	}

	if (job03 > 0)
	{
		rim1->JobReserch3 = true;
		rim2->JobReserch3 = true;
		rim3->JobReserch3 = true;
		rim4->JobReserch3 = true;
	}
	else
	{
		rim1->JobReserch3 = false;
		rim2->JobReserch3 = false;
		rim3->JobReserch3 = false;
		rim4->JobReserch3 = false;
		job03 = 0;
	}

	if (job04 > 0)
	{
		rim1->JobReserch4 = true;
		rim2->JobReserch4 = true;
		rim3->JobReserch4 = true;
		rim4->JobReserch4 = true;
	}
	else
	{
		rim1->JobReserch4 = false;
		rim2->JobReserch4 = false;
		rim3->JobReserch4 = false;
		rim4->JobReserch4 = false;
		job04 = 0;
	}

	if (job05 > 0)
	{
		rim1->JobReserch5 = true;
		rim2->JobReserch5 = true;
		rim3->JobReserch5 = true;
		rim4->JobReserch5 = true;
	}
	else
	{
		rim1->JobReserch5 = false;
		rim2->JobReserch5 = false;
		rim3->JobReserch5 = false;
		rim4->JobReserch5 = false;
		job05 = 0;
	}

	if (job06 > 0)
	{
		rim1->JobReserch6 = true;
		rim2->JobReserch6 = true;
		rim3->JobReserch6 = true;
		rim4->JobReserch6 = true;
	}
	else
	{
		rim1->JobReserch6 = false;
		rim2->JobReserch6 = false;
		rim3->JobReserch6 = false;
		rim4->JobReserch6 = false;
		job06 = 0;
	}

	if (job07 > 0)
	{
		rim1->JobReserch7 = true;
		rim2->JobReserch7 = true;
		rim3->JobReserch7 = true;
		rim4->JobReserch7 = true;
	}
	else
	{
		rim1->JobReserch7 = false;
		rim2->JobReserch7 = false;
		rim3->JobReserch7 = false;
		rim4->JobReserch7 = false;
		job07 = 0;
	}

	TileDataSet();
}

QTile* CommanderCCL::rimSetTile(int abc)
{
	return tiledatapos[abc];
}

void CommanderCCL::rimDataMatch()
{
	if (rim1->JobTile != nullptr)
	{
		if (rim1->JinhangJungTile == rim2->JinhangJungTile)
		{
			rimDataMatch_02(rim2, rim1);
		}
		if (rim1->JinhangJungTile == rim3->JinhangJungTile)
		{
			rimDataMatch_02(rim3, rim1);
		}
		if (rim1->JinhangJungTile == rim4->JinhangJungTile)
		{
			rimDataMatch_02(rim4, rim1);
		}
	}
	if (rim2->JobTile != nullptr)
	{
		if (rim2->JinhangJungTile == rim1->JinhangJungTile)
		{
			rimDataMatch_02(rim1, rim2);
		}
		if (rim2->JinhangJungTile == rim3->JinhangJungTile)
		{
			rimDataMatch_02(rim3, rim2);
		}
		if (rim2->JinhangJungTile == rim4->JinhangJungTile)
		{
			rimDataMatch_02(rim4, rim2);
		}
	}
	if (rim3->JobTile != nullptr)
	{
		if (rim3->JinhangJungTile == rim1->JinhangJungTile)
		{
			rimDataMatch_02(rim1, rim3);
		}
		if (rim3->JinhangJungTile == rim2->JinhangJungTile)
		{
			rimDataMatch_02(rim2, rim3);
		}
		if (rim3->JinhangJungTile == rim4->JinhangJungTile)
		{
			rimDataMatch_02(rim4, rim3);
		}
	}
	if (rim4->JobTile != nullptr)
	{
		if (rim4->JinhangJungTile == rim1->JinhangJungTile)
		{
			rimDataMatch_02(rim1, rim4);
		}
		if (rim4->JinhangJungTile == rim2->JinhangJungTile)
		{
			rimDataMatch_02(rim2, rim4);
		}
		if (rim4->JinhangJungTile == rim3->JinhangJungTile)
		{
			rimDataMatch_02(rim3, rim4);
		}
	}
}

void CommanderCCL::rimDataMatch_02(RimCharacter* rim1, RimCharacter* rim2)
{
	rim1->JinhangJungTile = rim1->Mytile;
	rim1->EndTile = rim1->Mytile;
	rim1->realTime_myJOB = true;
	rim1->JobTile = nullptr;
	rim1->TargetTileSerch("BUILD", rim2->JinhangJungTile);
	rim1->JobTile = rimSetTile(rim1->JinhangJungTile);
}

void CommanderCCL::JobnumberRESET()
{
	job01 = 0;
	job02 = 0;
	job03 = 0;
	job04 = 0;
	job05 = 0;
	job06 = 0;
	job07 = 0;
}

void CommanderCCL::badSet()
{
	if ((rim1->FinishedJOB || rim2->FinishedJOB || rim3->FinishedJOB || rim4->FinishedJOB)
		&& rim1->Bad == nullptr)
	{
		for (int i = 0; i < TileInteractiondata.size(); ++i)
		{
			if (rim4->Bad != nullptr && TileInteractiondata[i].first == rim4->Bad->node1->index) continue;
			if (rim2->Bad != nullptr && TileInteractiondata[i].first == rim2->Bad->node1->index) continue;
			if (rim3->Bad != nullptr && TileInteractiondata[i].first == rim3->Bad->node1->index) continue;

			if (TileInteractiondata[i].second == "BAD")
			{
				rim1->Bad = tiledatapos[TileInteractiondata[i].first];
				break;
			}
		}
	}
	if ((rim1->FinishedJOB || rim2->FinishedJOB || rim3->FinishedJOB || rim4->FinishedJOB) && rim2->Bad == nullptr)
	{
		for (int i = 0; i < TileInteractiondata.size(); ++i)
		{
			if (rim1->Bad != nullptr && TileInteractiondata[i].first == rim1->Bad->node1->index) continue;
			if (rim4->Bad != nullptr && TileInteractiondata[i].first == rim4->Bad->node1->index) continue;
			if (rim3->Bad != nullptr && TileInteractiondata[i].first == rim3->Bad->node1->index) continue;

			if (TileInteractiondata[i].second == "BAD")
			{
				rim2->Bad = tiledatapos[TileInteractiondata[i].first];
				break;
			}
		}
	}
	if ((rim1->FinishedJOB || rim2->FinishedJOB || rim3->FinishedJOB || rim4->FinishedJOB) && rim3->Bad == nullptr)
	{
		for (int i = 0; i < TileInteractiondata.size(); ++i)
		{
			if (rim1->Bad != nullptr && TileInteractiondata[i].first == rim1->Bad->node1->index) continue;
			if (rim2->Bad != nullptr && TileInteractiondata[i].first == rim2->Bad->node1->index) continue;
			if (rim4->Bad != nullptr && TileInteractiondata[i].first == rim4->Bad->node1->index) continue;

			if (TileInteractiondata[i].second == "BAD")
			{
				rim3->Bad = tiledatapos[TileInteractiondata[i].first];
				break;
			}
		}
	}
	if ((rim1->FinishedJOB || rim2->FinishedJOB || rim3->FinishedJOB || rim4->FinishedJOB) && rim4->Bad == nullptr)
	{
		for (int i = 0; i < TileInteractiondata.size(); ++i)
		{
			if (rim1->Bad != nullptr && TileInteractiondata[i].first == rim1->Bad->node1->index) continue;
			if (rim2->Bad != nullptr && TileInteractiondata[i].first == rim2->Bad->node1->index) continue;
			if (rim3->Bad != nullptr && TileInteractiondata[i].first == rim3->Bad->node1->index) continue;

			if (TileInteractiondata[i].second == "BAD")
			{
				rim4->Bad = tiledatapos[TileInteractiondata[i].first];
				break;
			}
		}
	}
}




void CommanderCCL::LateJobControl()
{
	if (rim1->MyJob == 0 && rim2->MyJob == 0 && rim3->MyJob == 0 && rim4->MyJob == 0) return;

	if (job01 != 0)
	{

	}
	if (job02 != 0)
	{

	}
	if (job03 != 0)
	{
		vector<pair<int, int>> number_lang;
		vector<int> plant;
		int zount = 0;
		bool job3ON = false;

		for (int i = 0; i < Builddatas.size(); ++i)
		{
			if (Builddatas[i].second == "BUILD")
			{
				plant.push_back(Builddatas[i].first);
			}
		}
		for (int i = 0; i < UIS->SelectMarker.size(); ++i)
		{
			if (UIS->SelectMarker[i]->myjob == "BUILD")
			{
				plant.push_back(UIS->SelectMarker[i]->Mynumber);
			}
		}

		if (rim1->MyJob == 3 && rim1->realTime_myJOB) zount++;
		if (rim2->MyJob == 3 && rim2->realTime_myJOB) zount++;
		if (rim3->MyJob == 3 && rim3->realTime_myJOB) zount++;
		if (rim4->MyJob == 3 && rim4->realTime_myJOB) zount++;

		// 사이즈와 값이 같거나 크다는 것은 그대로 배열에 값이 들어가면 오류가 생긴다는 뜻
		if (plant.size() <= zount)
		{
			zount = -1;
		}

		if (zount != -1)
		{
			if (rim1->MyJob == 3 && !rim1->realTime_myJOB && rim1->HvaeItem("WOOD"))
			{
				pair<int, int> baryy;
				baryy.first = rim1->RIMNUMBER;
				baryy.second = TargetTileSerchCCL(rim1, plant[zount]);
				number_lang.push_back(baryy);
			}
			else if (!rim1->HvaeItem("WOOD") && !rim1->realTime_myJOB)
			{
				rim1->impossibleJOB3 = false;
			}

			if (rim2->MyJob == 3 && !rim2->realTime_myJOB && rim2->HvaeItem("WOOD"))
			{
				pair<int, int> baryy;
				baryy.first = rim2->RIMNUMBER;
				baryy.second = TargetTileSerchCCL(rim2, plant[zount]);
				number_lang.push_back(baryy);
			}
			else if(!rim2->HvaeItem("WOOD") && !rim2->realTime_myJOB)
			{
				rim2->impossibleJOB3 = false;
			}

			if (rim3->MyJob == 3 && !rim3->realTime_myJOB && rim3->HvaeItem("WOOD"))
			{
				pair<int, int> baryy;
				baryy.first = rim3->RIMNUMBER;
				baryy.second = TargetTileSerchCCL(rim3, plant[zount]);
				number_lang.push_back(baryy);
			}
			else if (!rim3->HvaeItem("WOOD") && !rim3->realTime_myJOB)
			{
				rim3->impossibleJOB3 = false;
			}

			if (rim4->MyJob == 3 && !rim4->realTime_myJOB && rim4->HvaeItem("WOOD"))
			{
				pair<int, int> baryy;
				baryy.first = rim4->RIMNUMBER;
				baryy.second = TargetTileSerchCCL(rim4, plant[zount]);
				number_lang.push_back(baryy);
			}
			else if (!rim4->HvaeItem("WOOD") && !rim4->realTime_myJOB)
			{
				rim4->impossibleJOB3 = false;
			}

			while (number_lang.size() > 1)
			{
				if (number_lang[0].second < number_lang[1].second)
				{
					number_lang.erase(number_lang.begin() + 1);
				}
				else
				{
					number_lang.erase(number_lang.begin());
				}
			}

			if (number_lang.size() == 1)
			{
				job3ON = true;
			}
			else
			{
				job3ON = false;
			}
		}

		if (job3ON)
		{
			if (number_lang.size() != 0)
			{
				if (number_lang[0].first == 0 && !rim1->realTime_myJOB)
				{
					rim1->realTime_myJOB = true;
					rim1->JinhangJungTile = plant[zount];
					SaBangpopopo(rim1, rim1->JinhangJungTile);
					rim1->moving = true;
					rim1->JobTile = CM->rimSetTile(rim1->JinhangJungTile);
					rim1->IsJOB_003 = true;
				}
				else if (number_lang[0].first == 1 && !rim2->realTime_myJOB)
				{
					rim2->realTime_myJOB = true;
					rim2->JinhangJungTile = plant[zount];
					SaBangpopopo(rim2, rim2->JinhangJungTile);
					rim2->moving = true;
					rim2->JobTile = CM->rimSetTile(rim2->JinhangJungTile);
					rim2->IsJOB_003 = true;
				}
				else if (number_lang[0].first == 2 && !rim3->realTime_myJOB)
				{
					rim3->realTime_myJOB = true;
					rim3->JinhangJungTile = plant[zount];
					SaBangpopopo(rim3, rim3->JinhangJungTile);
					rim3->moving = true;
					rim3->JobTile = CM->rimSetTile(rim3->JinhangJungTile);
					rim3->IsJOB_003 = true;
				}
				else if (number_lang[0].first == 3 && !rim4->realTime_myJOB)
				{
					rim4->realTime_myJOB = true; // 작업중 활성화
					rim4->JinhangJungTile = plant[zount]; // 작업할 목표 타일
					SaBangpopopo(rim4, rim4->JinhangJungTile); // 해당 림의 목적지 타일 설정
					rim4->moving = true; // 움직일 수 있도록 무빙 활성화
					rim4->JobTile = CM->rimSetTile(rim4->JinhangJungTile); // 작업할 타일의 정보를 받아옴
					rim4->IsJOB_003 = true;
				}
			}
		}
	}
	if (job04 != 0)
	{
		vector<pair<int, int>> number_lang;
		vector<int> plant;
		int zount = 0;

		bool job4ON = false;

		for (int i = 0; i < UIS->SelectMarker.size(); ++i)
		{
			if (UIS->SelectMarker[i]->myjob == "WOOD")
			{
				plant.push_back(UIS->SelectMarker[i]->Mynumber);
			}
		}

		if (rim1->MyJob == 4 && rim1->realTime_myJOB) zount++;
		if (rim2->MyJob == 4 && rim2->realTime_myJOB) zount++;
		if (rim3->MyJob == 4 && rim3->realTime_myJOB) zount++;
		if (rim4->MyJob == 4 && rim4->realTime_myJOB) zount++;

		if (plant.size() <= zount)
		{
			zount = -1;
		}

		if (zount != -1)
		{
			if (rim1->MyJob == 4 && !rim1->realTime_myJOB)
			{
				pair<int, int> baryy;
				baryy.first = rim1->RIMNUMBER;
				baryy.second = TargetTileSerchCCL(rim1, plant[zount]);
				number_lang.push_back(baryy);
			}
			if (rim2->MyJob == 4 && !rim2->realTime_myJOB)
			{
				pair<int, int> baryy;
				baryy.first = rim2->RIMNUMBER;
				baryy.second = TargetTileSerchCCL(rim2, plant[zount]);
				number_lang.push_back(baryy);
			}
			if (rim3->MyJob == 4 && !rim3->realTime_myJOB)
			{
				pair<int, int> baryy;
				baryy.first = rim3->RIMNUMBER;
				baryy.second = TargetTileSerchCCL(rim3, plant[zount]);
				number_lang.push_back(baryy);
			}
			if (rim4->MyJob == 4 && !rim4->realTime_myJOB)
			{
				pair<int, int> baryy;
				baryy.first = rim4->RIMNUMBER;
				baryy.second = TargetTileSerchCCL(rim4, plant[zount]);
				number_lang.push_back(baryy);
			}

			while (number_lang.size() > 1)
			{
				if (number_lang[0].second <= number_lang[1].second)
				{
					number_lang.erase(number_lang.begin() + 1);
				}
				else
				{
					number_lang.erase(number_lang.begin());
				}
			}

			job4ON = true;
		}

		if (job4ON)
		{
			if (number_lang.size() != 0)
			{
				if (number_lang[0].first == 0 && !rim1->realTime_myJOB)
				{
					rim1->realTime_myJOB = true;
					rim1->JinhangJungTile = plant[zount];
					SaBangpopopo(rim1, rim1->JinhangJungTile);
					rim1->moving = true;
					rim1->JobTile = CM->rimSetTile(rim1->JinhangJungTile);
					rim1->IsJOB_004 = true;
				}
				else if (number_lang[0].first == 1 && !rim2->realTime_myJOB)
				{
					rim2->realTime_myJOB = true;
					rim2->JinhangJungTile = plant[zount];
					SaBangpopopo(rim2, rim2->JinhangJungTile);
					rim2->moving = true;
					rim2->JobTile = CM->rimSetTile(rim2->JinhangJungTile);
					rim2->IsJOB_004 = true;
				}
				else if (number_lang[0].first == 2 && !rim3->realTime_myJOB)
				{
					rim3->realTime_myJOB = true;
					rim3->JinhangJungTile = plant[zount];
					SaBangpopopo(rim3, rim3->JinhangJungTile);
					rim3->moving = true;
					rim3->JobTile = CM->rimSetTile(rim3->JinhangJungTile);
					rim3->IsJOB_004 = true;
				}
				else if (number_lang[0].first == 3 && !rim4->realTime_myJOB)
				{
					rim4->realTime_myJOB = true; // 작업중 활성화
					rim4->JinhangJungTile = plant[zount]; // 작업할 목표 타일
					SaBangpopopo(rim4, rim4->JinhangJungTile); // 해당 림의 목적지 타일 설정
					rim4->moving = true; // 움직일 수 있도록 무빙 활성화
					rim4->JobTile = CM->rimSetTile(rim4->JinhangJungTile); // 작업할 타일의 정보를 받아옴
					rim4->IsJOB_004 = true; // 4번 작업 실행!
				}
			}
		}
	}
	if (job05 != 0)
	{

	}
	if (job06 != 0)
	{

	}
}

int CommanderCCL::TargetTileSerchCCL(RimCharacter* rim, int tile)
{
	int x = rim->MytileXY.first - tiledatapos[tile]->myXY.first;
	int y = rim->MytileXY.second - tiledatapos[tile]->myXY.second;

	int sum = abs(x) + abs(y);

	return sum;
}
void CommanderCCL::SaBangpopopo(RimCharacter* rim, int tile)
{
	int left;
	int right;
	int top;
	int bottom;
	if (tile - 1 >= 0)
	{
		left = tile - 1;
	}
	else
	{
		left = 0;
	}

	if (tile - 31 >= 0)
	{
		bottom = tile - 31;
	}
	else
	{
		bottom = 0;
	}

	if (tile + 1 <= 960)
	{
		right = tile + 1;
	}
	else
	{
		right = 960;
	}

	if (tile + 31 <= 960)
	{
		top = tile + 31;
	}
	else
	{
		top = 960;
	}

	vector<pair<int, int>> asdf;
	pair<int, int> jkl;
	int x;
	int y;

	x = tiledatapos[left]->myXY.first - rim->MytileXY.first;
	y = tiledatapos[left]->myXY.second - rim->MytileXY.second;
	jkl.first = left;
	jkl.second = abs(x) + abs(y);
	asdf.push_back(jkl);

	x = tiledatapos[right]->myXY.first - rim->MytileXY.first;
	y = tiledatapos[right]->myXY.second - rim->MytileXY.second;
	jkl.first = right;
	jkl.second = abs(x) + abs(y);
	asdf.push_back(jkl);

	x = tiledatapos[top]->myXY.first - rim->MytileXY.first;
	y = tiledatapos[top]->myXY.second - rim->MytileXY.second;
	jkl.first = top;
	jkl.second = abs(x) + abs(y);
	asdf.push_back(jkl);

	x = tiledatapos[bottom]->myXY.first - rim->MytileXY.first;
	y = tiledatapos[bottom]->myXY.second - rim->MytileXY.second;
	jkl.first = bottom;
	jkl.second = abs(x) + abs(y);
	asdf.push_back(jkl);

	while (asdf.size() > 1)
	{
		if (asdf[0].second < asdf[1].second)
		{
			asdf.erase(asdf.begin() + 1);
		}
		else
		{
			asdf.erase(asdf.begin());
		}
	}

	rim->EndTile = asdf[0].first;
}

/*
결과적으로는 내 타일 위치와 목적이되는 타일의 위치만 받아와서 거리를 구하면 됨
이렇게 하면 그냥 타일의 거리만 알면 됨

list 사용 예정
0 = 림의 번호
1 = 엔드타일 번호
2 = 엔드타일과의 거리
*/