#pragma once
class RimTestScene : public Scene
{
public:
	RimTestScene();
	~RimTestScene();

	virtual void Update() override;
	virtual void Render() override;
	virtual void PostRender() override;

	void CemeraMoving();
	void RimsSelect();
	void RimMove();

private:
	QTileEditMap* gameTileMap; // Ÿ�� ������ ���� Ÿ�� ��ġ�� ���� ���� Ŭ����

	RimCharacter* rim1;
	RimCharacter* rim2;
	RimCharacter* rim3;
	RimCharacter* rim4;
	SelectTarget* selecttarget;

	Quad* SELETCtile;

	string fullPath;

	int selectobj = 0;

	int abc;

	float max_PressTime = 0.5f;
	float PressTime = max_PressTime;

	Quad* BackGorund;
};

