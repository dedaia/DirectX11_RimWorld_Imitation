#pragma once

class BinaryReader
{
public:

    //�⺻ ���´� �����Ϳ� ���� (����¸� �ݴ�)

    BinaryReader(string filePath);
    BinaryReader(wstring filePath);
    ~BinaryReader();

    // ������ ġȯ�� �Լ� �ۼ��� �ʿ� : 2������ ���� ���� ������� ��¥ 0�� 1�� ���ϱ�...
    int Int(); // void ��� ��ȯ�� �߰�
    float Float();
    UINT UInt();
    string String();
    wstring Wstring();

    //2�� �״�� �б⸸ ����
    void Byte(void** data, UINT dataSize);
    // void** data : ������(void*)�� �� ��ġ (�������� ������)
    // dataSize : ������ �� �ڸ� �̸� ����


    // ���� ���� �Լ� : "���Ͽ��� �����Ͱ� �������ϴ�"�� ��ȯ�ޱ� ���� �Լ�
    bool IsFailed() { return (file == INVALID_HANDLE_VALUE); } // �ڵ鸵 ����� ���ų�, �־ �������ϸ� "����" �Լ��� true
    bool IsValid() { return (file != INVALID_HANDLE_VALUE); } // �� �Լ��� �Ȱ����� �� �ٸ��� �� �ٸ� �Լ�

private:

    //����� �Ȱ��� ���� �ʿ�
    HANDLE file;
    DWORD size = 0;

};

