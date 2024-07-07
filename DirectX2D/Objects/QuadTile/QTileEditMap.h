#pragma once
class QTileEditMap : public Transform
{
public:
    QTileEditMap(UINT width, UINT height);
    ~QTileEditMap();

    void Update();
    void Render();
    void Save(string file);
    void Load(string file);

    void GetNodes(vector<Node*>& nodes);
    UINT GetWidth() { return width; }

    vector<QTile*> bgTiles;
private:

    UINT width;
    UINT height;

    //Ÿ�ϵ��� ���� (��� ���� ������Ʈ ����)

    Vector2 tileSize; //Ÿ�� ũ�� ���� (Ÿ�ϸ��� ũ�Ⱑ 100% ������ ���� ������, 100% ���� �� �������� ȿ���� �ش�ȭ)

    void CreateTiles();

    void SetBGTiles(wstring file, float angle); // �ؽ�ó ������ Ž���⿡�� �ٷ� ���� �Ŷ� wstring
    void SetOBJTiles(wstring file, float angle);

public: // A* �̽�
    void GetPath(IN int start, IN int end, OUT vector<Vector2>& path);
    int FindCloseNode(Vector2 pos);

    

    QTileEditMap* attcs;

    vector<Node*> nodes;
    Heap* heap; 

    void SetEdge(UINT width);

    int GetMinNode();
    void Extend(int center, int end); 

    void Reset();

    float GetManhattanDistance(int start, int end);
    float GetDiagonalManhattanDistance(int start, int end);
};