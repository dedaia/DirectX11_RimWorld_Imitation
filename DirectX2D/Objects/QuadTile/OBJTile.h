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

	wstring changedata; // ������ �Ϸ�Ǹ� �ٲ� �����͸� ������ ����

	vector<string> woon; // �ڽ��� ������ �ִ� ���� ������
	int stack = 0; // ���� �����͸� ����� �޾� ���� ������

	int settype;
	int Setcost;
	bool buildON = false;

	bool changebuild = false;

public: // �� �����δ� ���ڿ� �Լ�
	vector<string> Chest;
	int MaxItem = 30;
	bool NotItem();
};