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
	float hunger = 100; // 배고픔
	float sleep = 100; // 피곤함
	float funy = 100; // 재미
	float vusdks = 100; // 편안
	float dhlcnf = 100; // 외출
	float feeling = 100; // 기분 (사용하지 않을 예정)
	float alrhks = 100; // 미관 (사용하지 않을 예정)

	int berserker_count = 0;

	bool Phase1_Stress;
	bool Phase2_Stress;
	bool Phase3_Stress;

	// 가벼운 35
	// 심각한 20
	// 극심한 5

public: // 소모계수
	int HG = 1; // 배고픔 계수
	int SP = 1; // 피곤함 계수
	int FY = 1; // 재미 계수
	int VD = 1; // 편안 계수
	int DL = 1; // 외출 계수
};