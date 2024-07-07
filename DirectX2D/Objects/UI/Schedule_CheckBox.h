#pragma once
class Schedule_CheckBox
{
public:
	Schedule_CheckBox(Vector2 pos);
	~Schedule_CheckBox();

	void Update();
	void Render();
	void Setpa(Transform* aaa);

	void SetBOOL(class RimCharacter* rim);

public:
	vector<Button*> btn_checkbox;
};