#pragma once
class UI_Scene : public Singleton<UI_Scene>
{
	friend class Singleton;

public:
	UI_Scene();
	~UI_Scene();

	void Update();
	void Render();
	void Setpa(Transform* tra);

	void KEY_Input();

	void Selectrim(RimCharacter* rim);
	void SetTarget(RimCharacter* rim, int value);
	void ChangeTextureQuad();

	void SetCollider(Collider* haldng) { this->haldng = haldng; }
	Collider* GetCollider() { return haldng; }
	RimCharacter* GetRim() { return SelectRim; }

	void abfvsrb();
public:
	Quad* UI_back;
	Quad* UI_jacup_back;
	Quad* Gunchuck_back;
	Quad* Gunchuck_back02;

	Quad* rim1mam;
	Quad* rim2mam;
	Quad* rim3mam;
	Quad* rim4mam;

	Quad* wlrmadltnsrks;

	vector<Button*> UI_BTN;
	vector<Button*> otherBTN;
	vector<ProgressBar*> UI_PRB;

	vector<TIME_schedule*> stc;
	vector<Schedule_CheckBox*> zero1;

	vector<Marker*> SelectMarker; // 작업지시 표시용 텍스처

	bool SelectRim1 = false;
	bool SelectRim2 = false;
	bool SelectRim3 = false;
	bool SelectRim4 = false;

	float Second = 0.0f;
	const float Max_Second = 1.0f;
	int Hour = 8;
	int Day = 0;
public:

	float BTN_size = 0.25f;
	float BTN_height = 13.0f;

	// 림의 정보가 있는지
	bool RimOn = false;
	// 림 캐릭터 창 온오프
	bool characterIN = false;

	vector<Button*> Build_samples; // 건축 물들의 정보
	vector<Button*> Badcs; // 장판들의 정보

	Vector2 sampleSize = { 50.0f, 50.0f };
	Quad* selected = nullptr;


	RimCharacter* SelectRim;

	OBJTile* ActiveData;

	Collider* haldng; // 스케줄용 마우스 콜라이더 받아오기


	int SELETCtileintDAta = -1; // 마우스가 어떤 타일과 충돌했는지 알기 위한 타일번호 도출용 변수

};