#pragma once
class QTile : public Quad
{
public:

    enum Type //�� Ÿ���� ���� �Ӽ�
    {
        BG, //=Background
        OBJ, //=Object
        WOOD, // ����
        FOOD, // ����
    };

    struct Data //�� Ÿ���� ���� ����
    {
        wstring textureFile;
        Vector2 pos;
        float angle = 0.0f; //������ ������ Ÿ�� �ϳ��� �ּ� �� �̻��� �ٸ� ����� �� ���� �־
        Type type = BG;     //�⺻ ������ ������� (�׼��̳� RPG ���� ����� OBJ�� �� ������ ����)
    };

    QTile(Data data); //���� �� �̹� �⺻ ������ �ʿ��� ��ŭ ����...
    ~QTile();

    void SetTexture(wstring file);
    void SetAngle(float angle);

    void Update();
    void Render();

    void ColliderMouse();

    // Ÿ�� �����
    void BGTileBuildSet(wstring data);
    void BGTileBuildComplete();
    wstring apppci;

    void TileTEXChange();

    // �ٴ� Ÿ���� �����Ű�� ���� ���� (true : ���� �Ǽ����� ���� �ٴ��̶�� �ǹ�)
    bool TILE = false;
    // ������Ʈ�� �����Ű�� ���� ���� (true : ���� �Ǽ����� ���� ������Ʈ��� �ǹ�)
    bool OBJTTT = false;
    bool chergun = false;

    OBJTile* TileCHildren;
    OBJTile* Floortile;

    Collider* GetCollider() { return Touchme; }

    Data GetData() { return data; }
    void Getnod(Node* nod) { this->node1 = nod; }

    Collider* Touchme;
    int aasdgasdfb = 0;
    Node* node1;
    Type savetype;

    pair<int, int> myXY;
private:
    Data data;
};