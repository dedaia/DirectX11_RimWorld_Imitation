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

	vector<pair<int, string>> Builddatas; // ���� �� �ڷ�
	vector<pair<int, string>> TileInteractiondata; // ��ȣ�ۿ�

	vector<QTile*> tiledatapos; // Ÿ�ϵ��� ����
	vector<QTile*> BadData; // ħ�� ����
	vector<int> rimTargetNumber; // ���� �۾��� Ÿ���� ������ ������ ����

	int job01 = 0;
	int job02 = 0;
	int job03 = 0;
	int job04 = 0;
	int job05 = 0;
	int job06 = 0;
	int job07 = 0;

public:
	// ������ �۾��� ����
	void LateJobControl();

public:
	// �� �ڽ��� ��ǥ�� Ÿ���� ��ǥ�� �Ÿ��� ����
	int TargetTileSerchCCL(RimCharacter* rim, int tile);
	void SaBangpopopo(RimCharacter* rim, int tile);
};