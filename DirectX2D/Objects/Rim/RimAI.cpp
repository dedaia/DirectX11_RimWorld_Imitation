#include "Framework.h"

RimAI::RimAI()
{

}

RimAI::~RimAI()
{

}

void RimAI::Update()
{
	Stat_over();
	Stat_reset();
}

// 현재 상태
void RimAI::Stat_over()
{
	if (HP >= Max_HP) HP = Max_HP;
	if (hunger >= 100) hunger = 100;
	if (feeling >= 100) feeling = 100;
	if (funy >= 100) funy = 100;
	if (alrhks >= 100) alrhks = 100;
	if (vusdks >= 100) vusdks = 100;
	if (dhlcnf >= 100) dhlcnf = 100;
	if (sleep >= 100) sleep = 100;

	if (hunger <= 0) hunger = 0;
	if (feeling <= 0) feeling = 0;
	if (funy <= 0) funy = 0;
	if (alrhks <= 0) alrhks = 0;
	if (vusdks <= 0) vusdks = 0;
	if (dhlcnf <= 0) dhlcnf = 0;
	if (sleep <= 0) sleep = 0;

	chongHap_feel = (feeling + funy + vusdks + dhlcnf) / 4;
}
void RimAI::Stat_reset()
{
	HG = 1;
	SP = 1;
	FY = 1;
	VD = 1;
	DL = 1;
}