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

    //타일들의 벡터 (배경 따로 오브젝트 따로)

    Vector2 tileSize; //타일 크기 기준 (타일마다 크기가 100% 같으란 법은 없지만, 100% 같을 때 에디터의 효용이 극대화)

    void CreateTiles();

    void SetBGTiles(wstring file, float angle); // 텍스처 파일은 탐색기에서 바로 읽을 거라서 wstring
    void SetOBJTiles(wstring file, float angle);

public: // A* 이식
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