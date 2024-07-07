#pragma once
class RimCharacter : public Quad
{
	friend class RimAI;
	friend class QTileEditMap;
	friend class Node;
	friend class Heap;

public:
	enum TimeSchedule
	{
		FREETIME,
		WORKTIME,
		MYEONGSANGTIME,
		JOYTIME,
		SLEEPTIME
	};

public:
	RimCharacter(wstring file, string tag, int num);
	int RIMNUMBER;
	~RimCharacter();

	void Update();
	void Render();
	void PostRender();

	void MovePath();
	void SetPath(vector<Vector2> path) { this->path = path; }
	vector<Vector2>& GetPath() { return path; }

public: // �۾� ���� �Լ� �� ����
	void jigumTime(); // �ð��� ���� ���� ����
	void WorkTimeF(); // �����ð�
	void WorkTimeW(); // ��� �۾��� �ؾ� �ϴ��� �Ǻ�
	void WorkTimeJ(); // �����ð�
	void WorkTimeS(); // ����ð�
	void BreakFood(); // ����ļ� ������� ��
	int Sabangvalue(); // ���� 4������ ���� �޾ƿ�
	void Interaction(); // ��ȣ�� �� �۵��ϴ� �Լ�
	void carrying(string carry = "CHEST");

	void LateJobControl();
	int MyJob = 0;

	void WorkTimeW_RealJOB(); // Ȱ��ȭ�� �۾��� ���� ������ �ൿ
	bool IsJOB_001 = false;
	bool IsJOB_002 = false;
	bool IsJOB_003 = false;
	bool IsJOB_004 = false;
	bool IsJOB_005 = false;
	bool IsJOB_006 = false;
	bool IsJOB_007 = false;

	bool chamsssssssss = false;

	void FINIJOB();

public: // �����, ����� ����� �Ҹ������� ���ϴ� �Լ� ����
	void Hunger_IM();
	void Sleep_IM(); 
	void Funy_IM();
	void Vusdks_IM();
	void Dhlcnf_IM();

	bool sleepCHAM; // �ڰ��ִ��� �ƴ��� Ȯ��
	bool funyCHAM; // ����ִ��� �ƴ��� Ȯ��
	bool vusdksCHAM; // �޽��� ���ϰ� �ִ��� �ƴ��� Ȯ��
	bool dhlcnfCHAM; // �����ϰ� �ִ� �������� �ƴ��� Ȯ��

	void phase1(); // ������ 35
	void phase2(); // �ɰ��� 20
	void phase3(); // �ؽ��� 5

	// �����, �ǰ���, ���, �����, ����
	void HSFVD(int hunger, int sleep, int funy, int vusdks, int dhlcnf);

	bool pic; // �ʹ� �ǰ��ؼ� ������

public: // �۵� Ȯ�ο�
	bool onOFF;

public:
	Collider* cirlce;
	RimAI* AI;
	bool meselect = false;
	map<int, TimeSchedule> dlf;
	vector<Button*> scheDule;
	Quad* Speech_Bubble;
	  

	int Mytile; // ���� ���� ���ִ� Ÿ�� ��ȣ
	int EndTile; // ������ Ÿ���� ��ȣ
	int TargetTile; // ��ã�⿡ ���Ǵ� ���� ����Ÿ��
	vector<pair<int, string>> tiledata; // Ÿ�� ����
	vector<pair<int, string>> tkdghwkrdydDATA;

	bool moving = false;
	bool serch = false;
	bool serch2 = false;
	bool serch3 = false;
	bool serch4 = false;
	bool realTime_myJOB = false;
	float max_random_moving = 3.0f;
	float random_moving = max_random_moving;

	bool JinhangJung = false;
	int JinhangJungTile;
	float jingjingjing = 0.0f;

	// ���� �ʵ忡 ���� �ִ� �����ΰ�
	bool JobReserch1 = false;
	bool JobReserch2 = false;
	bool JobReserch3 = false;
	bool JobReserch4 = false;
	bool JobReserch5 = false;
	bool JobReserch6 = false;
	bool JobReserch7 = false;

	// �ش� �۾��� ���� �� �� �ִ� ��Ȳ�ΰ�
	bool impossibleJOB1 = true;
	bool impossibleJOB2 = true;
	bool impossibleJOB3 = true;
	bool impossibleJOB4 = true;
	bool impossibleJOB5 = true;
	bool impossibleJOB6 = true;
	bool impossibleJOB7 = true;

	bool FinishedJOB = false;

	bool JOB_complete;

	ProgressBar* Work_Process;
public:
	TimeSchedule schedule;
	vector<Vector2> path;
	float moveSpeed = 500.0f;

	pair<int, int> saveMyTiledata;

public: // Ÿ�� ����
	pair<int, int> MytileXY;
	// ���� ���ִ� Ÿ���� XY����
	void MytileXYData();
	// �ִܰŸ� ��� �Լ�
	void TargetTileSerch(string tiledata, int path = -1);
	// �Ĺ��� �ִܰŸ� ��� �Լ�
	void TargetTileSerch_plant(string tiledata, int path = -1);
	// ��ȣ�ۿ�� �ִܰŸ� ��� �Լ�
	void TargetTileSerch_Interaction(vector<pair<int,string>> data ,string tiledata, int path = -1);
	// �� ���� ������ �������� ������
	void RandomMoving();
	QTile* Bad = nullptr;

	wstring clear = L"Textures/UI_IMAGE/CharacterUI_Clear.png"; // ��ǳ��
	wstring sleep = L"Textures/UI_IMAGE/CharacterUI_Sleep.png"; // ���ڴ� �̸�Ƽ��
	wstring run = L"Textures/UI_IMAGE/CharacterUI_Run.png"; // ���ڴ� �̸�Ƽ��

	QTile* JobTile = nullptr;
	
public: // �� �����δ� �κ��丮 ����
	int Max_inven = 10;
	vector<string> Inventory;
	// �κ��丮�� ���ο� �������� ����
	void Inven_GetItem(IN string name,IN int stack);
	// �κ��丮�� �ִ� �������� �Ǽ� �������� �ű�
	void Inven_OutItem();
	// ���ڿ� �ִ� �������� �κ��丮�� ����
	void Inven_ChestGetIN(string item);
	// �κ��丮�� �ִ� �������� ���ڿ� ����
	void Inven_ChestOUT(string item);
	// �ڽ��� �������� ������ �ִ����� Ȯ���ϴ� �Լ�
	bool HvaeItem(string item);
};

/*

�ð��� 1�� �Ҵ�Ǹ� 24�ð� �ؼ� �� 24�� �Ҹ�

�⺻������ 1������ 24�� �Ҹ�Ǹ� ����� (��� * �ð�)

*/