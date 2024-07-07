#include "Framework.h"

ProgressBar::ProgressBar()
{
    //�⺻ �ؽ�ó�� ����� ���� ����
    image = new Quad(L"Textures/yellow.png");

    Adjust();
}

ProgressBar::ProgressBar(wstring file) //�Ű������� ���� ���� ��������� �״�� �佺
{
    image = new Quad(file);

    Adjust();
}

ProgressBar::~ProgressBar()
{
    delete image;
}

void ProgressBar::Update()
{
    Transform::UpdateWorld();
    image->UpdateWorld();
}

void ProgressBar::Render()
{
    image->Render();
}

// �Ʒ� �� �Լ��� ����
// 1. �ڱ� �ڽ��� �̸� �������� ��¦ �̵�
// 2. �������� �� ���� �׸� �ؽ�ó�� �ٽ� ���������� �̵�

// -> �׸��� ���� �� �ڸ��� �״�� ������ �θ� Ʈ������(�������� �߽�)�� �������� �̵��� ����
// -> ��ǻ� ���� �̵��� ���̳� �ٸ�����

void ProgressBar::Adjust()
{
    //������ ����� ��ġ�� �����ϱ� ���� ��
    
    // �ؽ�ó�� �θ� Ʈ�������� ��� �Ѵ�(�ٷ� �� Ŭ����)
    image->SetParent(this);
    
    // �ؽ�ó�� ������ ��ġ(0, 0)=�θ��� ��ġ���� ���������� �о��
    image->Pos() = { image->Half().x, 0 };
    //image->Pos() = { image->Scale().x, 0 };
}

void ProgressBar::SetPosition(Vector2 pos)
{
    localPosition = { pos.x - image->Half().x, pos.y };
}