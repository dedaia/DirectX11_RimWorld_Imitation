#pragma once

class Camera : public Transform
{
public:
    Camera();
    ~Camera();

    void Update();
    void SetView();
    void RenderUITO();
    

    void SetTarget(Transform* target) { this->target = target; }

private:
    // ī�޶��� �þ� ���� ����
    void FollowMode(); // Follow-Cam : ī�޶� �������� �־ ������ ��ġ�� ��� ����
    void FreeMode();   // Free-Cam   : ī�޶� ������ ���� �Է¹��� ��� ��ġ�� �ٲ��

    //������ ���� ����
    MatrixBuffer* viewBuffer;
    Matrix view;

    float speed = 1000.0f;

    Transform* target = nullptr; // �ȷο� ķ ����� �� ������ �� �� �ִ� ǥ�� �繰
};

