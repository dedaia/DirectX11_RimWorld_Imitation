#include "Framework.h"

OBJTile::OBJTile() : Quad(L"Textures/Tile/Tiles/Floor Tile/grass.png")
{

}
OBJTile::OBJTile(wstring data) : Quad(data)
{

}
OBJTile::~OBJTile()
{

}

void OBJTile::Update()
{
	if (!isActive) return;

	Quad::UpdateWorld();
	if (changebuild) CM->job03++;
	if (woon.size() < stack)
	{
		CM->job07++;
		buildON = false;
	}
	else
	{
		buildON = true;
	}
}
void OBJTile::Render()
{
	if (!isActive) return;
	Quad::Render();
}

void OBJTile::SetTexture(wstring file)
{
	Quad::SetTexture(file);

	if (wwwsss == doorCL || wwwsss == doorOP)
	{
		bbb = DOOR;
	}
}
void OBJTile::BuildOBJ(wstring file)
{
	Quad::SetTexture(L"Textures/Tile/Tiles/NoTile/planks.png");
	changedata = file;
	changebuild = true;

	stack = 2;

	switch (bbb)
	{
	case OBJTile::BAD:
		settype = 0;
		Setcost = 2;
		break;

	case OBJTile::FIRE:
		settype = 0;
		Setcost = 2;
		break;

	case OBJTile::CART:
		settype = 0;
		Setcost = 2;
		break;

	case OBJTile::CHAIR:
		settype = 0;
		Setcost = 2;
		break;

	case OBJTile::CHEST:
		settype = 0;
		Setcost = 2;
		break;

	case OBJTile::COFFIN:
		settype = 0;
		Setcost = 2;
		break;

	case OBJTile::DOOR:
		settype = 0;
		Setcost = 2;
		break;

	case OBJTile::TABLE:
		settype = 0;
		Setcost = 2;
		break;

	case OBJTile::WALL:
		settype = 1;
		break;
	}
}
void OBJTile::ChangeTTT()
{
	Quad::SetTexture(changedata);
	changebuild = false;

	if (wwwsss == doorCL || wwwsss == doorOP)
	{
		bbb = DOOR;
	}
}
void OBJTile::ChangeNull()
{
	isActive = false;
}

bool OBJTile::NotItem()
{
	if (Chest.size() <= 0) return true;
	else return false;
}