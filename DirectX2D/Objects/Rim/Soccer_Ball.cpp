#include "Framework.h"

Soccer_Ball::Soccer_Ball() : Quad(L"Textures/Tile/Tiles/NoTile/barrel.png")
{

}
Soccer_Ball::~Soccer_Ball()
{

}

void Soccer_Ball::Update()
{
	if (MYposdata == FUTUREposdata) kick = true;
	else kick = false;

	MovePath();
	UpdateWorld();
}
void Soccer_Ball::Render()
{
	Quad::Render();
}

void Soccer_Ball::MovePath()
{
	if (path.empty())
		return;

	Vector2 direction = path.back() - Pos();
	Rot().z = direction.Angle();

	Pos() += Right() * moveSpeed * DELTA;

	if (direction.Length() < 5.0f)
		path.pop_back();
}