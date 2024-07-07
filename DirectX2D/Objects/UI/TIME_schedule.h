#pragma once
class TIME_schedule : public Transform
{
public:
	TIME_schedule(Vector2 pos, float poss);
	~TIME_schedule();

	void Update();
	void Render();

	void Setpa(Transform* aaa);
	void ChangeTexture(Collider* ppp);
	void SetChange(RimCharacter* abc);
	void InputChange(RimCharacter* abc);

public:
	vector<Quad*> aaa;
	vector<Collider*> bbb;

	wstring image1;
	wstring image2;
	wstring image3;
	wstring image4;

	int set = 0;
	int set2 = 0;
};