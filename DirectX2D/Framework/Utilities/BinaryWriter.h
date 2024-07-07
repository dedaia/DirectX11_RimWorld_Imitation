#pragma once
class BinaryWriter
{
public:

    BinaryWriter(wstring filePath); // <- �� Ž����� ���� ���� ����
    BinaryWriter(string filePath);  // <- C++ �ȿ��� ���� ���� (+���� ������͵� ������, �ѱ��ο��Դ� �� �ǹ� ���� ����...)
    ~BinaryWriter();

    // �ڵ� ���꿡 ���� �ڷᰡ �߻��ϸ�, �ش� �ڷ����� ���߾ ��ٷ� ������ �ۼ��ϴ� �Լ�
    void Int(int data); //<- � �����ε� �ѹ� �����Ͱ� ����ȯ�Ǿ ����, ����ȯ�� �����͸� �ٽ� ��밡�� (���� ��������, �߰��� ����ȯ�� �ߵ�...)
    void Float(float data);
    void UInt(UINT data);
    void String(string data);
    void Wstring(wstring data);
    // �� �ۿ��� ���� �� �ڷ����� �߰��� �Ǿ�� �Ѵٸ� �� ������ �߰�...

    //// 2�� ������ ���� �Լ� (*�� ��� �ϳ��� �ڷ������� ǥ���� ���� ���µ� �׷��� ���� �ۼ��� �ؾ� �ϴ� ���)
    void Byte(void* data, UINT dataSize);

private:
    // ���⿡ �ʿ��� ����

    //�����Ϳ� ǥ�� ������ �޸𸮿� ��Ƶα� ���� �ڵ鷯(void ������:�����̵� �� �� �ִ� �װ�)
    HANDLE file;

    // ���� �ۼ� �߿� �̸� Ȯ���ؾ� �� �޸� ũ��
    // = ������ ������ ũ�� = ������� ���� ũ��
    DWORD size = 0;
};

