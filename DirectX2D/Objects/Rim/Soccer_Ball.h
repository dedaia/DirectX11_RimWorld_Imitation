#pragma once
class Soccer_Ball : public Quad
{
public:
	Soccer_Ball();
	~Soccer_Ball();

	void Update();
	void Render();

	void MovePath();
	void SetPath(vector<Vector2> path) { this->path = path; }
	vector<Vector2>& GetPath() { return path; }

	int MYposdata;
	int FUTUREposdata;
	bool kick = false;

	bool moving = false;

	vector<Vector2> path;
	float moveSpeed = 500.0f;
};