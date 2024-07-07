#include "Framework.h"

BinaryReader::BinaryReader(string filePath)
{
    // ���Ͽ� ���� ����(���� ��ü��, ���Ͽ� ���� �޸� �� ������)
    // -> ������ �ٷ� ���� ���߸� �� ���� �κ�

    file = CreateFileA(filePath.c_str(),
        GENERIC_READ,            // �бⰡ ������ �� �б�
        FILE_SHARE_READ,         // ���ϰ� ������ ����ҿ��� �б� ������ �־�� �б�
        0,
        OPEN_EXISTING,           // ���� ���� ���ΰ�? (ALWAYS : ��� ���� �д´�! / EXISTING : ������ �д´�)
        FILE_ATTRIBUTE_NORMAL,
        nullptr);
}

BinaryReader::BinaryReader(wstring filePath)
{
    file = CreateFile(filePath.c_str(),
        GENERIC_READ,            
        FILE_SHARE_READ,         
        0,
        OPEN_EXISTING,           
        FILE_ATTRIBUTE_NORMAL,
        nullptr);
}

BinaryReader::~BinaryReader()
{
    CloseHandle(file);
}

// ������� ���� ���� �б�, �Ʒ��� ������ ġȯ

int BinaryReader::Int()
{
    int result;

    // ReadFile : WriteFile�� �����ϴ� ������ ���� �Լ�
    ReadFile(file, &result, sizeof(int), &size, nullptr);

    //�� �Լ� ȣ�� �� result�� ���� ���� ����
    return result;
}

float BinaryReader::Float()
{
    float result;

    ReadFile(file, &result, sizeof(float), &size, nullptr);

    return result;
}

UINT BinaryReader::UInt()
{
    UINT result;

    ReadFile(file, &result, sizeof(UINT), &size, nullptr);

    return result;
}

string BinaryReader::String()
{
    UINT strSize = UInt(); // ���Ͽ��� ���� ũ�� �б�

    //������ �迭�� ��� ���� temp ���ڿ�
    char* temp = new char[strSize + 1];

    ReadFile(file, temp, sizeof(char) * strSize, &size, nullptr);
    temp[strSize] = '\0';
    // ���ڿ��� ������ c�� cpp���� �ٷ������� ���ڿ��� ���� "���ڿ� ������"�� Ư�����ڿ��� �Ѵ�
    // �׷��� ������ �̷� ������ ���� �迭�� �Ųٷ� ���� �־��� ����, �迭�� ���� "\0(���� ��)"�̶�� �ۼ��ؼ� ���ڿ��μ� ���� �� �ֵ��� �ϴ� ��

    //�̷��� ���ڿ��ν� �� �� �ִ� �����Ͱ� �ϼ�
    return (string)temp;
}

wstring BinaryReader::Wstring()
{
    UINT strSize = UInt();

    WCHAR* temp = new WCHAR[strSize + 1];
    ReadFile(file, temp, sizeof(WCHAR) * strSize, &size, nullptr);
    temp[strSize] = '\0';

    return (wstring)temp;
}

void BinaryReader::Byte(void** data, UINT dataSize)
{
    ReadFile(file, *data, dataSize, &size, nullptr);
    //���޵� �Ű����� *data = void** data�� ���� ����� ���Ѵ�
    //=> *(&&data)�� �ٸ����� = &data, (void*) data��� ��
}