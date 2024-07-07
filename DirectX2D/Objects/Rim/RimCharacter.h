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

public: // 작업 관련 함수 및 변수
	void jigumTime(); // 시간에 따라 일을 나눔
	void WorkTimeF(); // 자유시간
	void WorkTimeW(); // 어떠한 작업을 해야 하는지 판별
	void WorkTimeJ(); // 오락시간
	void WorkTimeS(); // 수면시간
	void BreakFood(); // 배고파서 밥먹으러 감
	int Sabangvalue(); // 랜덤 4방향의 값을 받아옴
	void Interaction(); // 백호플 때 작동하는 함수
	void carrying(string carry = "CHEST");

	void LateJobControl();
	int MyJob = 0;

	void WorkTimeW_RealJOB(); // 활성화된 작업에 따라 실제로 행동
	bool IsJOB_001 = false;
	bool IsJOB_002 = false;
	bool IsJOB_003 = false;
	bool IsJOB_004 = false;
	bool IsJOB_005 = false;
	bool IsJOB_006 = false;
	bool IsJOB_007 = false;

	bool chamsssssssss = false;

	void FINIJOB();

public: // 배고픔, 편안함 등등의 소모정도를 정하는 함수 라인
	void Hunger_IM();
	void Sleep_IM(); 
	void Funy_IM();
	void Vusdks_IM();
	void Dhlcnf_IM();

	bool sleepCHAM; // 자고있는지 아닌지 확인
	bool funyCHAM; // 놀고있는지 아닌지 확인
	bool vusdksCHAM; // 휴식을 취하고 있는지 아닌지 확인
	bool dhlcnfCHAM; // 외출하고 있는 상태인지 아닌지 확인

	void phase1(); // 가벼운 35
	void phase2(); // 심각한 20
	void phase3(); // 극심한 5

	// 배고픔, 피곤함, 재미, 편안함, 외출
	void HSFVD(int hunger, int sleep, int funy, int vusdks, int dhlcnf);

	bool pic; // 너무 피곤해서 쓰러짐

public: // 작동 확인용
	bool onOFF;

public:
	Collider* cirlce;
	RimAI* AI;
	bool meselect = false;
	map<int, TimeSchedule> dlf;
	vector<Button*> scheDule;
	Quad* Speech_Bubble;
	  

	int Mytile; // 지금 내가 서있는 타일 번호
	int EndTile; // 목적지 타일의 번호
	int TargetTile; // 길찾기에 사용되는 원본 엔드타일
	vector<pair<int, string>> tiledata; // 타일 정보
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

	// 현재 필드에 일이 있는 상태인가
	bool JobReserch1 = false;
	bool JobReserch2 = false;
	bool JobReserch3 = false;
	bool JobReserch4 = false;
	bool JobReserch5 = false;
	bool JobReserch6 = false;
	bool JobReserch7 = false;

	// 해당 작업을 진행 할 수 있는 상황인가
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

public: // 타일 정보
	pair<int, int> MytileXY;
	// 내가 서있는 타일의 XY정보
	void MytileXYData();
	// 최단거리 계산 함수
	void TargetTileSerch(string tiledata, int path = -1);
	// 식물용 최단거리 계산 함수
	void TargetTileSerch_plant(string tiledata, int path = -1);
	// 상호작용용 최단거리 계산 함수
	void TargetTileSerch_Interaction(vector<pair<int,string>> data ,string tiledata, int path = -1);
	// 할 일이 없을때 랜덤으로 움직임
	void RandomMoving();
	QTile* Bad = nullptr;

	wstring clear = L"Textures/UI_IMAGE/CharacterUI_Clear.png"; // 말풍선
	wstring sleep = L"Textures/UI_IMAGE/CharacterUI_Sleep.png"; // 잠자는 이모티콘
	wstring run = L"Textures/UI_IMAGE/CharacterUI_Run.png"; // 잠자는 이모티콘

	QTile* JobTile = nullptr;
	
public: // 이 밑으로는 인벤토리 관련
	int Max_inven = 10;
	vector<string> Inventory;
	// 인벤토리에 새로운 아이템을 넣음
	void Inven_GetItem(IN string name,IN int stack);
	// 인벤토리에 있는 아이템을 건설 예정지에 옮김
	void Inven_OutItem();
	// 상자에 있는 아이템을 인벤토리에 넣음
	void Inven_ChestGetIN(string item);
	// 인벤토리에 있는 아이템을 상자에 넣음
	void Inven_ChestOUT(string item);
	// 자신이 아이템을 가지고 있는지를 확인하는 함수
	bool HvaeItem(string item);
};

/*

시간당 1이 할당되면 24시간 해서 총 24가 소모

기본상태인 1에서는 24가 소모되며 관계는 (배수 * 시간)

*/