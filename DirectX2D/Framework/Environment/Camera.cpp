#include "Framework.h"

// ī�޶� ���� : ������ ������ ���� Ʈ�������� ����, �� ��ġ�� ����Ʈ�� ����� �ǵ���
// �⺻�� winAPI ���� ��� : ���̴� ī�޶�(ī�޶� ����) ����ϴ� ���� �ƴ϶�
//                          ����� �Ȱ��� ����Ʈ�� �ϴ� �ͻ� (���� ���� ��ġ�� �޶�����)

//                         -> ����, ���� ī�޶� �ٷ� �Ŵ����� ����� �ϰų� �ڵ����� ���̴� ���� �ƴ϶�
//                            Environment���� ������ ����� �Ѵ� (�׷��� Environment�� ���� �ڵ����� ���)

Camera::Camera()
{
	//���� ����
	viewBuffer = new MatrixBuffer();
	viewBuffer->SetPS(1);
	// 1 : 0 �ƴ�, 2 �ƴ� = "������ ����"���� ���еȴ�
	// ui�ʹ� ���� = VS�� �ٸ� �� �־ (���� ó���� �ٸ� �� �־) ��Ÿ ���̴�, ��� ������ �Ϻ� ������ ����...

	//tag = "Camera"; // ���߿� ��ü������ (�����̵� �и���) �ʿ��� ��� �±׷ε� ������ �� �ֵ���

	UI_Scene::Get()->Setpa(this);
}

Camera::~Camera()
{
	delete viewBuffer;
}

void Camera::Update()
{
	// �������� ������ �ȷο�ķ���� ����, �ƴϸ� ����ķ���� ����
	if (target != nullptr) FollowMode();
	else FreeMode();

	if (mouseWheel < 0.0f) // �� ����
	{
		Scale() += { 0.1f, 0.1f };
		mouseWheel = 0;
	}
	if (mouseWheel > 0.0f) // �� �б�
	{
		Scale() -= { 0.1f, 0.1f };
		mouseWheel = 0;
	}

	mouseOscaleffset = Scale();
	
	//�� ���� (��� �� ���ΰ�?)
	SetView();
}

void Camera::SetView()
{
	UpdateWorld(); // Ʈ���������μ��� ���� ������Ʈ (ī�޶�� ��� ��� �ִ°�)

	view = XMMatrixInverse(nullptr, world);

	viewBuffer->Set(view);
	viewBuffer->SetVS(1); //���� ������� ����� �� ������ ���� ����
}

void Camera::FollowMode()
{
	Pos() = target->Pos() - Vector2(CENTER_X, CENTER_Y) * mouseOscaleffset;
}

void Camera::FreeMode()
{
	// ī�޶� ���� �̵�

	if (KEY_PRESS('W'))
	{
		Pos().y += speed * DELTA;
	}
	if (KEY_PRESS('S'))
	{
		Pos().y -= speed * DELTA;
	}
	if (KEY_PRESS('A'))
	{
		Pos().x -= speed * DELTA;
	}
	if (KEY_PRESS('D'))
	{
		Pos().x += speed * DELTA;
	}
	mouseOffset = Pos();
}

void Camera::RenderUITO()
{
	UI_Scene::Get()->Render();
}