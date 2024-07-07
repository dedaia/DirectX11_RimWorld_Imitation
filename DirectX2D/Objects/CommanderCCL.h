#pragma once
class CommanderCCL : public Singleton<CommanderCCL>
{
public:
	CommanderCCL();
	~CommanderCCL();

	void Update();
	void Render();
	void PostRender();

	void TileDataSet();
	void Jobduqn();

	QTile* rimSetTile(int abc);
	void rimDataMatch();
	void rimDataMatch_02(RimCharacter* rim1, RimCharacter* rim2);

	void JobnumberRESET();
	void badSet();

	RimCharacter* rim1;
	RimCharacter* rim2;
	RimCharacter* rim3;
	RimCharacter* rim4;

	vector<pair<int, string>> Builddatas; // 건축 등 자료
	vector<pair<int, string>> TileInteractiondata; // 상호작용

	vector<QTile*> tiledatapos; // 타일들의 정보
	vector<QTile*> BadData; // 침대 정보
	vector<int> rimTargetNumber; // 림이 작업할 타일의 정보를 저장해 놓음

	int job01 = 0;
	int job02 = 0;
	int job03 = 0;
	int job04 = 0;
	int job05 = 0;
	int job06 = 0;
	int job07 = 0;

public:
	// 림들의 작업을 통제
	void LateJobControl();

public:
	// 내 자신의 좌표와 타일의 좌표로 거리를 구함
	int TargetTileSerchCCL(RimCharacter* rim, int tile);
	void SaBangpopopo(RimCharacter* rim, int tile);
};