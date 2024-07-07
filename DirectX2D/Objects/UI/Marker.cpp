#include "Framework.h"

Marker::Marker(int value, string abc) : Quad(L"Textures/UI_IMAGE/TileSelect.png")
{
	Mynumber = value;
	myjob = abc;

	isActive = true;
}
Marker::~Marker()
{

}

void Marker::Update()
{
	if (!isActive) return;

	if (myjob == "WOOD")
	{
		CM->job04++;
	}
	if (myjob == "BUILD")
	{
		CM->job03++;
	}

	if (UIS->otherBTN[0]->GetDown001())
	{
		if (Mynumber == UIS->SELETCtileintDAta)
		{

		}
	}

	Quad::UpdateWorld();
}
void Marker::Render()
{
	if (!isActive) return;

	Quad::Render();
}