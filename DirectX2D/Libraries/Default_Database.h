#pragma once

class Default_Database : public Singleton<Default_Database>
{
	friend class Singleton;
public:
	Default_Database() {}
	~Default_Database() {}

public: // wstring DATA
	wstring doorClose = L"Textures/Tile/Tiles/NoTile/SA/door_closed.png";
	wstring doorOpen = L"Textures/Tile/Tiles/NoTile/SA/door_open.png";

public: // string DATA
	string food = "FOOD";
	string wood = "WOOD";
	string build = "BUILD";
	
public: // int DATA
};