#pragma once
class SelectTarget : public Singleton<SelectTarget>
{
	friend class Singleton;

public:
	SelectTarget();
	~SelectTarget();
	
	void Update();
	void Render();
	void PostRender();

	void select();

	RectCollider* Getcollider() { return rectsize; }

	void SelecteTargetmouseDrag();
	RectCollider* rectsize;
private:
	Quad* ttt;

	//RectCollider* attsize;

	bool firstValue = false;
	Vector2 first;
};