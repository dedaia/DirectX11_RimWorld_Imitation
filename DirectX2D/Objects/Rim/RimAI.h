#pragma once
class RimAI
{
public:
	RimAI();
	~RimAI();

	void Update();

	void Stat_over();
	void Stat_reset();

public:
	float Max_HP = 10;
	float HP = Max_HP;
	float chongHap_feel;
	float hunger = 100; // �����
	float sleep = 100; // �ǰ���
	float funy = 100; // ���
	float vusdks = 100; // ���
	float dhlcnf = 100; // ����
	float feeling = 100; // ��� (������� ���� ����)
	float alrhks = 100; // �̰� (������� ���� ����)

	int berserker_count = 0;

	bool Phase1_Stress;
	bool Phase2_Stress;
	bool Phase3_Stress;

	// ������ 35
	// �ɰ��� 20
	// �ؽ��� 5

public: // �Ҹ���
	int HG = 1; // ����� ���
	int SP = 1; // �ǰ��� ���
	int FY = 1; // ��� ���
	int VD = 1; // ��� ���
	int DL = 1; // ���� ���
};