#pragma once

class ProgressBar : public Transform
{
public:

    ProgressBar();
    ProgressBar(wstring file);
    ~ProgressBar();

    // Ʈ���������� ��� Update�� ����(�ʿ䵵 ����)
    // �׷��� �� ����� Ŭ������ �繰ó�� ��� �Ǵϱ� Update Render�� ��ӿ� ������� ���� �����
    void Update();
    void Render();
    void PostRender() {} // ���� ������ �� �ƴ����� �̸� �����д�

    void SetPosition(Vector2 pos); // ��ġ ���� �Լ� = Pos() ���� ��ü��

    Quad* image;
private:

    //�� Ŭ������ ������� : �ؽ�ó (�̹���)

    void Adjust(); //���� �Լ� = ������ ���� ȣ���
};

