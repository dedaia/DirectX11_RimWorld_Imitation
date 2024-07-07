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

	vector<Marker*> SelectMarker; // �۾����� ǥ�ÿ� �ؽ�ó

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

	// ���� ������ �ִ���
	bool RimOn = false;
	// �� ĳ���� â �¿���
	bool characterIN = false;

	vector<Button*> Build_samples; // ���� ������ ����
	vector<Button*> Badcs; // ���ǵ��� ����

	Vector2 sampleSize = { 50.0f, 50.0f };
	Quad* selected = nullptr;


	RimCharacter* SelectRim;

	OBJTile* ActiveData;

	Collider* haldng; // �����ٿ� ���콺 �ݶ��̴� �޾ƿ���


	int SELETCtileintDAta = -1; // ���콺�� � Ÿ�ϰ� �浹�ߴ��� �˱� ���� Ÿ�Ϲ�ȣ ����� ����

};