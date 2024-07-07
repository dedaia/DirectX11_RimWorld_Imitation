#pragma once
class Marker : public Quad
{
public:
	Marker(int value, string abc);
	~Marker();

	void Update();
	void Render();

	int Mynumber;
	string myjob;
};