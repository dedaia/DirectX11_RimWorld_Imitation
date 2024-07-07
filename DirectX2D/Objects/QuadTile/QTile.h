#pragma once
class QTile : public Quad
{
public:

    enum Type //이 타일의 현재 속성
    {
        BG, //=Background
        OBJ, //=Object
        WOOD, // 나무
        FOOD, // 음식
    };

    struct Data //이 타일의 세부 정보
    {
        wstring textureFile;
        Vector2 pos;
        float angle = 0.0f; //각도가 있으면 타일 하나로 최소 둘 이상의 다른 결과를 얻어낼 수도 있어서
        Type type = BG;     //기본 유형은 배경으로 (액션이나 RPG 같은 경우라면 OBJ가 더 적절할 수도)
    };

    QTile(Data data); //만들 때 이미 기본 정보가 필요한 만큼 들어가게...
    ~QTile();

    void SetTexture(wstring file);
    void SetAngle(float angle);

    void Update();
    void Render();

    void ColliderMouse();

    // 타일 변경용
    void BGTileBuildSet(wstring data);
    void BGTileBuildComplete();
    wstring apppci;

    void TileTEXChange();

    // 바닥 타일을 변경시키기 위한 변수 (true : 지금 건설중인 것이 바닥이라는 의미)
    bool TILE = false;
    // 오브젝트를 변경시키기 위한 변수 (true : 지금 건설중인 것이 오브젝트라는 의미)
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