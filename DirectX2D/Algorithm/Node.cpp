#include "Framework.h"

Node::Node(Vector2 pos, int index)
    : pos(pos), index(index)
{
    //this->pos = pos;
    //this->index = index;

    collider = new CircleCollider(15); // ������ 15�� �� �׷��� ǥ��
    collider->Pos() = pos;
    collider->UpdateWorld();
}

Node::Node(Vector2 pos, int index, Collider* collider)
    : pos(pos), index(index)
{
    //this->pos = pos;
    //this->index = index;

    this->collider = collider; // ������ 15�� �� �׷��� ǥ��
    this->collider->Pos() = pos;
    this->collider->UpdateWorld();
}

Node::~Node()
{
    for (Edge* edge : edges)
        delete edge;

    //delete collider;
}

void Node::Render()
{
    //collider->Render(); //���� �Ƶ� �� ǥ�� (�⺻, �ʼ�)

    //State�� ����� ���� ���� �ݶ��̴� �� ǥ�ø� �ٸ��� �ϸ鼭 ����

    switch (state) // if�� �ص� ������, enum�� Ư���� �ߺ� ����, �ָ��� ��� ����. switch�� �� ��︰��
    {
    case Node::NONE:
        collider->GetColor() = { 0, 1, 1, 1 }; // û�ϻ�
        break;

    case Node::OPEN:
        collider->GetColor() = { 0, 0, 1, 1 }; // �Ķ���
        break;

    case Node::CLOSED:
        collider->GetColor() = { 0, 0, 0, 1 }; // ���
        break;

    case Node::USING:
        collider->GetColor() = { 0, 1, 0, 1 }; // �ʷϻ�
        break;

    case Node::OBSTACLE:
        collider->GetColor() = { 1, 0, 0, 1 }; // ������
        break;
    }

    //���� �� ������ �ٽ� ����
    //collider->Render();
}

void Node::AddEdge(Node* node)
{
    Edge* edge = new Edge(node->pos, pos); // ��ǥ�� ������ ��ġ�� ����, ������ ����
    edge->index = node->index; //��� �ε����� ��ǥ ���� �ݿ�
    edge->cost = Distance(node->pos, pos); // *�̹����� (�ǽ� ���̴ϱ�) ��λ��� ����� �Ÿ��� �����ϴٴ� �������� ����

    edges.push_back(edge);
}

void Node::Getupdate(class QTile* tile)
{
    switch (tile->GetData().type)
    {
    case QTile::BG:
        SetState(Node::NONE);
        break;
    case QTile::OBJ:
        SetState(Node::OBSTACLE);
        break;
    case QTile::WOOD:
        SetState(Node::OBSTACLE);
        break;
    case QTile::FOOD:
        SetState(Node::OBSTACLE);
        break;

    default:
        break;
    }

    //if (tile->aasdgasdfb == 1)
    //{
    //    state = OBSTACLE;
    //}
}
