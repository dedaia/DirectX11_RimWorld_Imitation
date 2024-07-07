#pragma once
class OBJTile : public Quad
{
	friend class QTile;
public:
	enum BBB
	{
		BAD,
		FIRE,
		CART,
		CHAIR,
		CHEST,
		COFFIN,
		DOOR,
		TABLE,
		WALL
	};

	OBJTile();
	OBJTile(wstring data);
	~OBJTile();
	void Update();
	void Render();

	void SetTexture(wstring file);
	void BuildOBJ(wstring file);
	void ChangeTTT();
	void ChangeNull();

	BBB bbb;
	wstring doorCL = L"Textures/Tile/Tiles/NoTile/SA/door_closed.png";
	wstring doorOP = L"Textures/Tile/Tiles/NoTile/SA/door_open.png";

	wstring changedata; // 건축이 완료되면 바뀔 데이터를 저장해 놓음

	vector<string> woon; // 자신이 가지고 있는 나무 데이터
	int stack = 0; // 나무 데이터를 몇개까지 받아 들일 것인지

	int settype;
	int Setcost;
	bool buildON = false;

	bool changebuild = false;

public: // 이 밑으로는 상자용 함수
	vector<string> Chest;
	int MaxItem = 30;
	bool NotItem();
};