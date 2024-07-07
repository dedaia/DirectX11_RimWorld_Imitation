#include "Framework.h"

Heap::Heap()
{

}
Heap::~Heap()
{
    // Node�� ������ �ν��Ͻ��� ������, ���⼭ ���� ���� �ƴ϶�
    // �ٸ� ������ ���� ���� ���⿡ '��'���� ��� ���� ����
    // -> delete�� ���⼭ �����ϴ� ���� ū �ǹ� ���� (��쿡 ���󼭴� ������ ���ɼ���)
}



void Heap::Insert(Node* node)
{
    heap.push_back(node);
    UpdateUpper(heap.size() - 1); //���� �������� �������� ��� ������Ʈ �ٽ� �ϱ�
}

Node* Heap::DeleteRoot()
{
    Node* root = heap.front(); //���� �������
    
    //���Ϳ��� ���ϴ� ������ �� �ڷ� ������ �ش� ������ pop-back���� ����� (������ 0)
    Swap(0, heap.size() - 1); //���� �� ó���� �� �� ��ü
    heap.pop_back(); //�� �� ����

    UpdateLower(0); //���ο� ���� 0������ ������Ʈ �ٽ� �ϱ�

    return root; // �� ó���� ���ξ��� "���� �������"�� ��ǻ�Ϳ� ��ȯ
}

void Heap::UpdateUpper(int index)
{
    int curIndex = index;
    int parent = (curIndex - 1) / 2; //���� ���� �ε��� ������ ������ "�θ�"�� ��Ī

    while (curIndex != 0) // ���� �ε����� 0�� �� ������(������ ó������ �� ������)
    {
        if (heap[parent]->GetCost() <= heap[curIndex]->GetCost()) // �θ�(���� ���� ���) �̵� ����� ���� �߰��� ��������� �̵� ��뺸�� ������
            return; //�� ����� �ʿ� ����
        
        // �׷��� ����� �Դٴ� ����, ���� �߰��� ����� Cost�� ������ ��ϵ� ��庸�� �� ����
        Swap(curIndex, parent); // �ε����� ���� ���� ���� �ٲٱ�
        curIndex = parent; // �ε����� ���� �θ�� (�� �ܰ� ����)

        // �� ���꿡��, ������ ��������� �ε��� ���� �� "����"�� ���� �Ű�
        // �� ������ �ε��� ���� "�� ĭ ������" ���� �Ű�....

        //���ο� �з�Ʈ �� ���ϱ�
        parent = (curIndex - 1) / 2;
    }
}

void Heap::UpdateLower(int index)
{
    // ���� ������Ʈ : ������ ������ �ݴ��� �����ϸ� ���ϴ�

    int curIndex = index; // (������ ��) ���� �ε���
    int lChild = (index * 2) + 1; //�ڽ� 1�� = �� �ε����� 2��+1�� ���� �ο�
    int rChild = lChild + 1; //2�� �ڽ��� 1�� �ڽ� �ٷ� ��������
    int minNode = curIndex;

    while (true)
    {
        //�ڽ��� ������ ���� �ְ�, �ڽ��� ��λ� ����� �� ���� ���� �ε������� �۴ٸ�
        if (lChild < heap.size() && heap[lChild]->GetCost() < heap[minNode]->GetCost())
        {
            minNode = lChild; // �ּҺ�� �ε����� ���� �ε���(curIndex)���� �ڽ����� ����
        }

        //���� �񱳸� ������ �ڽĿ��Ե� �Ѵ�
        if (rChild < heap.size() && heap[rChild]->GetCost() < heap[minNode]->GetCost())
        {
            minNode = rChild; // �ּҺ�� �ε����� ���� �ε���(curIndex)���� �ڽ����� ����
        }

        //���࿡ �� �񱳿����� �ߴµ� �ּҳ�尡 ������ ���� �ε������ (���� �ε����� �̹� �ּҶ��)
        if (minNode == curIndex) // �� ������ ���� �ε��� = �ּҺ��
            //break; //�ݺ��� ����
            return;  //�ƿ� �Լ� ����

        //����� �ּҺ�� ���� ���� �ε����� ��ü
        Swap(curIndex, minNode);
        curIndex = minNode; //���ο� �ּ� ��带 ���� ���� �ε����� ����
        lChild = (curIndex * 2) + 1;
        rChild = lChild + 1;
    }
}

void Heap::Swap(int n1, int n2)
{
    //������ swap �ٷ� ���
    swap(heap[n1], heap[n2]);
}
