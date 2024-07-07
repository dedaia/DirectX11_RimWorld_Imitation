#pragma once

class Node
{
    // ��ã��(A*)���� ����ϱ� ���� ���� �⺻ ����(Ȥ�� ��ǥ) ���� Ŭ����
    
public:
    // ...�׷��Ƿ� ��ã�� �˰���� ������ ����
    friend class AStar;
    friend class QTileEditMap;
    friend class QTile;
    friend class RimCharacter;

    struct Edge //���. ���ͽ�Ʈ�� ���� ����ϴ� (�ᱹ A*�� D �˰����� ������)
    {
        int index;
        float cost;
        LineCollider* line;

        Edge(Vector2 start, Vector2 end)
        {
            line = new LineCollider(start, end);
            line->GetColor() = { 1, 1, 0, 1 }; // �����
        }
        ~Edge() { delete line; }
    };

    enum State // �� ��� ��ü�� ���� ��λ��� ����
    {
        //���� ��꿡�� ���� �� ����, �̷л� ��޵Ǵ� ����� ������
        NONE, // "�ش� ����" = ������ �ƴ� = �� ������
        OPEN, // "�� �� �ִ� ��" = Ž�� ���
        CLOSED, // "���� ��" = ���� Open�̾����� Ž���� ����Ǿ� ����� ������ ������ ��
        USING, // "Ž�� ���� ��" = ���Ǻ� Ž�� ���
        OBSTACLE, // "��ֹ�" = �������� �Ϻ�����, ��δ� �ƴ� �� = Ž�� ��� �ƴ�
    };

    Node(Vector2 pos, int index); //��ġ�� ���Ҿ� ���� ������ �ε������� �̸�
    Node(Vector2 pos, int index, Collider* collider);
    ~Node();

    void Render();

    void AddEdge(Node* node);

    float GetCost() { return f; }
    void SetState(State state) { this->state = state; }

    void Getupdate(class QTile* tile);

    vector<Edge*> edges; //�������
public:

    Vector2 pos;

    int index = 0;
    int via = -1;

    //����� ��� (������ ��)
    float f = 0;
    float g = 0;
    float h = 0;

    State state = NONE; //����� �Ӽ�. �⺻���� "�ϴ� ��� �ƴ�"


    Collider* collider; // ��ã�� ��/�Ŀ� ������ ���� ���� �浹ü
};

