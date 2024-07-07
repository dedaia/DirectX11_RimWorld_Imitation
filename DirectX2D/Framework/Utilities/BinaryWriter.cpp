#include "Framework.h"

BinaryWriter::BinaryWriter(wstring filePath)
{

    // �����쿡�� ������ ���̳ʸ� ��� �Լ��� ���ؼ� �����͸� ���Ͽ� ��ų�,
    // �����Ͱ� ���� �̸� �ʱ�ȭ�� ������ �ۼ�

    file = CreateFile(filePath.c_str(), // ������ ��θ�
        GENERIC_WRITE,                  // ���� ���� �׼���
        0,                              // ���� ��� (������ 0)
        0,                              // ���� ���� �Ӽ��� �� ���� ��� �ۼ� (������ 0)
        CREATE_ALWAYS,                  // ���� ������ ���� �� �ִ��� (ALWAYS : ���� ������ �ֵ� ���� ������ �����)
        FILE_ATTRIBUTE_NORMAL,          // ������� ������ OS �� �Ӽ� ���� (�б� ���� ����, ���� ����.... �⺻�� NORMAL[�ƹ� �Ӽ� ����])
        nullptr);                       // ������ ������� ���� ������ �ִ°�?

    // ��θ� : (����̺��̸�[��������]) + �����̸� + �����̸�

}

BinaryWriter::BinaryWriter(string filePath)
{
    file = CreateFileA(filePath.c_str(),
        GENERIC_WRITE,
        0,
        0,
        CREATE_ALWAYS,
        FILE_ATTRIBUTE_NORMAL,
        nullptr);
}

BinaryWriter::~BinaryWriter()
{
    // delete file;
    CloseHandle(file); // �� �ڵ�� ������ ������, ���� �� ����
}

// �� �ڷ����� ���� ���� �ۼ�
void BinaryWriter::Int(int data)
{
    // �ۼ� ��� ��ü�� �����쿡�� ������ ���ش� (��κ��� �ٸ� �����ӿ�ũ�� ������ ��������)
    WriteFile(file,  // �ۼ��� ������ �̸�(Ȥ�� ��θ�)
        &data,       // � �����͸� ���� ���ΰ�? (=�������� �޸� �� ��ġ)
        sizeof(int), // �� �����ʹ� ������ ���� ũ��
        &size,       // �� ���� ũ��
        nullptr);     // ������ ������ �ٸ� ���� ���� ���� �ִ°�? (������ nullptr)
}

void BinaryWriter::Float(float data)
{
    WriteFile(file, &data, sizeof(float), &size, nullptr);
}

void BinaryWriter::UInt(UINT data)
{
    WriteFile(file, &data, sizeof(UINT), &size, nullptr);
}

void BinaryWriter::String(string data)
{
    //���� �ۼ��� UInt�� �Ἥ ������ ��ü ����(�� "������ ����"�� �� �� ���ڴ�)�� ����
    UInt(data.size()); // ���� ��  data = string = ������ ����

    //Ŭ������ �ִ� ��Ʈ�� �����͸� ��ü�ؼ� ���ڿ��� ��ȯ
    const char* str = data.c_str();

    WriteFile(file, str, sizeof(char) * data.size(), &size, nullptr);
    // string�� c++���� ���� ����(char)�� �迭�̱� ������ 1�� ���� ũ��� ���� �ϳ�(char)
    // �׷��� �ۼ��� �����ʹ� string�̹Ƿ� 1�� ���ؿ� ���� ���̸�ŭ ���ؼ� ���� �������� ����ũ�⸦ ����
}

void BinaryWriter::Wstring(wstring data)
{
    UInt(data.size()); // ���� �̷� ȣ��� ���Ͽ����� ������ �ִ� ���� : ���� ���� ������

    const WCHAR* str = data.c_str();
    WriteFile(file, str, sizeof(WCHAR) * data.size(), &size, nullptr);
}

void BinaryWriter::Byte(void* data, UINT dataSize)
{
    //�������� �����ؾ� �ϹǷ� �ִ��� �ܼ��ϰ�
    // -> �� �Լ��� �θ� ���� �Ű����� �ִ� ����(=ȣ�� ����) ����ȯ���� �ʿ��� ������ �صξ�� �Ѵ�

    WriteFile(file, data, dataSize, &size, nullptr);
}