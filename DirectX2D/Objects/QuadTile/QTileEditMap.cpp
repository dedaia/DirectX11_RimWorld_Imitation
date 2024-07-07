#include "Framework.h"


QTileEditMap::QTileEditMap(UINT width, UINT height)
{
	srand(GetTickCount64());

	this->width = width;
	this->height = height;

	CreateTiles();

	GetNodes(nodes); //�ʿ��� ��� ���� �޾ƿ���
	SetEdge(GetWidth()); //���� ������ �����Ƿ� �ش� �ʿ� ���� ��� ������ �̸� �� �޾ƿ���

	int XXX = 1;
	int YYY = 1;
	for (int i = 0; i < nodes.size(); ++i)
	{
		bgTiles[i]->Getnod(nodes[i]);

		bgTiles[i]->myXY.first = XXX;
		bgTiles[i]->myXY.second = YYY;

		XXX++;
		if (XXX >= 32) 
		{
			YYY++;
			XXX = 1;
		}
	}

	heap = new Heap();
}
QTileEditMap::~QTileEditMap()
{
	for (QTile* tile : bgTiles)
		delete tile;

	for (Node* node : nodes)
		delete node;
	delete heap;
}

void QTileEditMap::Update()
{
	// for (QTile* tile : bgTiles)
	//     tile->Update();
	for (int i = 0; i < nodes.size(); ++i)
	{
		bgTiles[i]->Update();
		nodes[i]->Getupdate(bgTiles[i]);
	}

	Transform::UpdateWorld();
}
void QTileEditMap::Render()
{
	for (QTile* tile : bgTiles)
		tile->Render();

	for (Node* node : nodes)
		node->Render();
}

void QTileEditMap::Save(string file) // ���� �̸��� ���� ���̺� �ۼ�
{
	// ���̳ʸ� ���� ��¿� �����ͺ��� �����
	BinaryWriter* writer = new BinaryWriter(file);

	writer->UInt(width); //���θ� ������ ����
	writer->UInt(height); //���ε� ����

	writer->UInt(bgTiles.size());

	for (QTile* tile : bgTiles)
	{
		QTile::Data data = tile->GetData(); // ������ ���� �б�

		//�� ������(����ü) �� �� ������ �ڷ��� ���� �ϳ��� �����ϱ�
		writer->Wstring(data.textureFile);
		writer->Float(data.pos.x);
		writer->Float(data.pos.y);
		writer->Float(data.angle);
		writer->Int((int)data.type);

		// ������� ���� ���Ÿ�� ���� ��
	}

	// ������� ���� ��� Ÿ�� ������ �ϳ��� ���Ͽ� �̾ ������ ��
	// �� �ڷ��� ���� �Լ� ȣ�� ������� �߰��� �ڷ����� �޶����� ���̳ʸ� ��� ����

	delete writer; // �� �� ������ �ν��Ͻ� �����
}
void QTileEditMap::Load(string file)
{
	BinaryReader* reader = new BinaryReader(file);

	width = reader->UInt(); // ������ ù �����͸� int��ŭ �о U-int�� ���ο� ����
	height = reader->UInt(); // ���� �����͸� �� �о ���ο� ����. ���� �ݺ�

	UINT size = reader->UInt(); // �о�� �� ������ �����ϱ�

	for (QTile* tile : bgTiles)
	{
		QTile::Data data; // �� ����ü �ϴ� �����α�
		// * {} �ۿ��� ����� ȿ���� ����
		// ��� ���⼭ ����� {}�� ���� �� �������� �ڵ�����
		data.textureFile = reader->Wstring();
		data.pos.x = reader->Float();
		data.pos.y = reader->Float();
		data.angle = reader->Float();
		data.type = (QTile::Type)reader->Int();

		//�̾Ƴ� ������ ���� Ÿ�Ͽ� �����ϱ�
		tile->SetTexture(data.textureFile);
		tile->Pos() = data.pos;
		tile->Rot().z = data.angle;
	}

	delete reader;
}
void QTileEditMap::CreateTiles()
{
	//�⺻ (����) Ÿ�� ����
	wstring baseTile = L"Textures/Tile/Tiles/Floor Tile/tile.png";

	float value;
	float value2;

	Texture* texture = Texture::Add(baseTile);

	//�⺻ Ÿ�Ͽ��� ���� ũ�� ����
	tileSize = texture->GetSize();

	bgTiles.reserve(width * height); //���� ����

	for (UINT y = 0; y < height; ++y)
	{
		for (UINT x = 0; x < width; ++x)
		{
			QTile::Data data = {};
			value = Random(1, 31);
			value2 = Random(1, 100);

			// �ٴ� Ÿ�� ���ϱ�
			if (value >= 1 && value <= 15)
			{
				baseTile = L"Textures/Tile/Tiles/Floor Tile/tile.png";
			}
			else
			{
				baseTile = L"Textures/Tile/Tiles/Floor Tile/grass.png";
			}

			data.textureFile = baseTile;
			data.pos = Vector2(tileSize.x * x, tileSize.y * y);

			QTile* tile = new QTile(data);
			if (value2 >= 1 && value2 <= 5)
			{
				tile->TileCHildren->SetTexture(L"Textures/Tile/Tiles/NoTile/tree.png");
				tile->TileCHildren->SetActive(true);
				tile->savetype = QTile::WOOD;
			}
			else if (value2 == 50)
			{
				tile->TileCHildren->SetTexture(L"Textures/Tile/Tiles/NoTile/barrels_stacked.png");
				tile->TileCHildren->SetActive(true);
				tile->savetype = QTile::FOOD;
			}

			tile->SetParent(this);
			bgTiles.push_back(tile);
		}
	}
}

void QTileEditMap::GetNodes(vector<Node*>& nodes)
{
	for (QTile* tile : bgTiles)
	{
		//Vector2 tilePos = tile->GlobalPos();
		Vector2 tilePos = tile->Pos();
		Node* node = new Node(tilePos, nodes.size());

		nodes.push_back(node);
	}
}







void QTileEditMap::GetPath(IN int start, IN int end, OUT vector<Vector2>& path)
{
	if (start == -1 || end == -1) return;

	Reset();
	path.clear();

	float _g = 0;
	float _h = GetDiagonalManhattanDistance(start, end);

	nodes[start]->f = _g + _h;
	nodes[start]->g = _g;
	nodes[start]->h = _h;
	nodes[start]->via = start;
	nodes[start]->state = Node::OPEN;

	heap->Insert(nodes[start]);

	while (nodes[end]->state != Node::CLOSED)
	{

		if (heap->Empty())
			return;
		int curIndex = GetMinNode();


		Extend(curIndex, end);
		nodes[curIndex]->state = Node::CLOSED;
	}

	int curIndex = end;

	while (curIndex != start)
	{
		nodes[curIndex]->state = Node::USING;
		path.push_back(nodes[curIndex]->pos);
		curIndex = nodes[curIndex]->via;
	}

	path.push_back(nodes[start]->pos);
}

int QTileEditMap::FindCloseNode(Vector2 pos)
{
	float minDist = FLT_MAX;
	int result = -1;

	for (UINT i = 0; i < nodes.size(); ++i)
	{
		float distance = Distance(pos, nodes[i]->pos);
		if (distance < minDist)
		{
			//��� �ݿ�
			minDist = distance;
			result = i;
		}
	}

	//��� ��ȯ
	return result;
}

void QTileEditMap::SetEdge(UINT width)
{
	//��� ��忡 ���ؼ� �ݺ��� ������
	for (UINT i = 0; i < nodes.size(); ++i)
	{
		// �ڱ� �ֺ� ��, �Ʒ�, �Ʒ��� �� �� ��ǥ ������ ��η� �ձ�
		// �̴�� �ݺ����� ����Ǹ� ��� ��ǥ�� 8�������� ����ǵ��� �� �� �ִ�
		if (i % width != width - 1)
		{
			nodes[i]->AddEdge(nodes[i + 1]);
			nodes[i + 1]->AddEdge(nodes[i]);
		}

		if (i < nodes.size() - width)
		{
			nodes[i]->AddEdge(nodes[i + width]);
			nodes[i + width]->AddEdge(nodes[i]);
		}

		if (i < nodes.size() - width && i % width != width - 1)
		{
			nodes[i]->AddEdge(nodes[i + width + 1]);
			nodes[i + width + 1]->AddEdge(nodes[i]);
		}

		if (i < nodes.size() - width && i % width != 0)
		{
			nodes[i]->AddEdge(nodes[i + width - 1]);
			nodes[i + width - 1]->AddEdge(nodes[i]);
		}
	}
}

int QTileEditMap::GetMinNode()
{
	// ��ΰ� ���� ���� ��ǥ ���ϱ�

	// ��Ģ������ �ϴ� ���
	// 1. ��� ��带 ���������� �����ϴ�
	// 2. �� ��忡�� �ڱ� �ֺ� ��η� ���� ���� �ּ� ����� �����մϴ�
	// 3. �ּҰ��� ��� ������ ��(for �ݺ���), ���� ����� ��ȯ�޽��ϴ�.
	// (���� �ڷᱸ���� �ʿ���� ���ͽ�Ʈ�� �˰����̾��ٸ� ���⼭ �ڵ带 �� ����� ���� ��)

	// �� ��꿡�� "Ư���� ��ġ�� ���� �� ����, ���� ������ ���Ѵ�"��� ������ �߰��ϸ�?
	// "�ش� ��ġ�� ���� ������� ��� ������ ��� ������ �������� �����Ѵ�" �� �Ͱ� ����� �̾߱�

	// = '��' Ŭ������ ���� Ʈ������ ���� ���� �ִ� ��尡 ���� ���ŵ� �ּ� ��� ����!

	// ���� Ʈ���� �ֻ�� ��带 �����, �ش� ��带 ���� ���� �� ����� �ε����� ��ǻ�Ϳ��� �� �ش�
	return heap->DeleteRoot()->index;

	// * Ŭ������ �� ������ ���� �ʿ����� ������� ����� ȣ�⸸ �� �ص� �ȴ�
}
void QTileEditMap::Extend(int center, int end)
{
	for (Node::Edge* edge : nodes[center]->edges) //�Ű������� ���� �������� ��� ���� ������
	{
		int index = edge->index;

		//�� ���� �� ����
		if (nodes[index]->state == Node::CLOSED) continue; // �˻� �����ų� � �����ε� ���ܵ����� ����
		if (nodes[index]->state == Node::OBSTACLE) continue; //���� �ƴϾ ����

		float _g = nodes[center]->g + edge->cost; //��ǥ�� ������ 'g'�� ����� ����� ��ģ ��
		float _h = GetDiagonalManhattanDistance(index, end); // ���� ��ǥ���� ������������ "������ �Ÿ�" : �Ǵ��� �������� �ȴ�
		// ������ �밢���� ������ �ý� �Ÿ��� ��꿡 �ְ� ������, ���⿡ �׳� �ý� �Ÿ��� �� ���, �� �� ������ �񱳸� ������ �� �ִ�
		// _g�� ���� ����� ����� å��������, �������� ������ �ʹ� ũ�� �޴´�
		// _h�� ���� ����� ����� �ƴ�����, ���� �Ÿ��� å�����ָ鼭 _g�� �ʹ� ��ȸ�ϴ� ����� ���� �ʰ� �ϴ� �Ǵ� ������ �ȴ�

		float _f = _g + _h; // �� ���� ��ġ�� �񱳸� ���� ���� ����� �޾Ƴ� �� �ִ�

		//���⼭ �츮�� ����� ��� ��� ���� f, g, h�� �̸��� �����غ� �� �ִ� (*����� ���ι�������...)
		// f : Final, ���� ���
		// g : Geometric, ���� ���� ������ (��� ���)
		// h : Heuristic, "�޸���ƽ" ������ (������ ����ȭ, ���� ������ ����ġ�� ���ؼ� �Ǵ� ������ ����)

		// ���� ã�Ƴ� f ���� Ȱ��

		//�ϴ��� ��尡 "�� �� �ִ� ��"�̶�� ĥ ��
		if (nodes[index]->state == Node::OPEN)
		{
			// ��� ���� ����
			if (_f < nodes[index]->f)
			{
				nodes[index]->g = _g;
				nodes[index]->f = _f;
				// nodes[index]->h = _h; // <- ������ Ÿ���� ������ �� �ƴϴϱ� 1ȸ ��길���ε� ���. �ʿ��ϸ� ���߿� �� ����ϸ� �׸�
				nodes[index]->via = center; // ����� �������� ������ �������� �ǵ���
			}
		}
		//(�ɼ�) �����Ϳ� ���� �������� ���� �ʵ忡 �߰��Ǵ� ������ �ִٸ� (�ִٰ� �����ϰ� �ۼ�)
		else if (nodes[index]->state == Node::NONE)
		{
			//��忡 ��� ���� �� ����ֱ�
			nodes[index]->g = _g;
			nodes[index]->h = _h; // ���� ��� ���� ä���ֱ�
			nodes[index]->f = _f;
			nodes[index]->via = center;
			nodes[index]->state = Node::OPEN; // �� �� �ִ� ��� ǥ��

			heap->Insert(nodes[index]); // ��� ������ ���ο� ��� �ֱ�
		}
	}
}

void QTileEditMap::Reset()
{
	// ����� ó�� Ȥ�� ���� ������ ��� ���� ��ü �ʱ�ȭ

	for (Node* node : nodes)
	{
		if (node->state != Node::OBSTACLE)
			//node->state = Node::OPEN; //�� "�� �� ����"���� �����ϱ�
			node->state = Node::NONE; // �� Extend �Լ��� (���� �ۼ� ����) ���� �� ���, ��������� �� ������ ����� ������ ���� ����
	}

	//��尡 Open�� ���, �� ����� ������ �ϰ�/�����ؼ� heap�� �ָ� �ȴ�

	//���� �ۼ� ������ ���, �׳� heap�� ����� �ȴ� (�߰��� extend���� �� ���ִϱ�)
	heap->Clear();

	//�̷��� NONE ���µ� �� ����ϸ� ���� ���꿡 ������ �ȴ� (+������ Ȯ�强���� ������ �ȴ�)
	// -> ��� �� ��忡 ���� �κ� ������ ���� ���� �ִ� (�κ� ������ �ʿ��� ���� �ᱹ Open ��带 ���� �����ڰ� �����ؾ�)
}

float QTileEditMap::GetManhattanDistance(int start, int end)
{
	// �ý� �Ÿ� : X���� �Ÿ��� Y���� �Ÿ��� �ܼ��� ���ϱ⸸ �ϸ� �ȴ� (�⺻)

	Vector2 startPos = nodes[start]->pos; //(�������� ������) ���� ��ǥ�� ���� ��ġ
	Vector2 endPos = nodes[end]->pos;     // �������� ��ġ

	Vector2 distance = endPos - startPos; //���ͷμ��� ��

	// �Լ��� ��� : x ���� �Ÿ��� y ���� �Ÿ��� �״�� ��ġ��
	return abs(distance.x) + abs(distance.y);
}

float QTileEditMap::GetDiagonalManhattanDistance(int start, int end)
{
	// "�밢��" �ý� �Ÿ� ���ϱ� : �ϴ��� �밢���� ���Եǰ�, x, y ��ǥ���� ��꿡 �ִ� �Ÿ� ����
	// ��ü�����δ� ������ ����
	// 1. �������� ������ ���̿� ���簢�� ����� �ִٰ� ġ��, �ش� ���簢���� �밢�� ���̸� ����Ѵ�
	// 2. ���簢���� ���Ե��� �ʴ� ���� ���簢�� ������ "���� �ý� �Ÿ�"�� ����Ѵ�
	// 3. 1�� 2�� ��ģ��

	Vector2 startPos = nodes[start]->pos; //(�������� ������) ���� ��ǥ�� ���� ��ġ
	Vector2 endPos = nodes[end]->pos;     // �������� ��ġ

	Vector2 distance = endPos - startPos; //���ͷμ��� ��

	//��� ������ ������ ���밪����
	float x = abs(distance.x);
	float y = abs(distance.y);

	//�ִ� �ּ� ���ϱ�
	float maxDist = max(x, y);
	float minDist = min(x, y);

	//���� �Ÿ��� ���簢���� �밢�� ���̸� ���ļ� ���� ����� ���ϴ� ��
	return (maxDist - minDist) + sqrt(minDist * minDist * 2);

	// * ü���� ��� �����Ͻô� ���� ����Ʈ, ��, ���� �ึ�� ���÷�������. �װ� �밢�� �ý� �Ÿ��� �������� �����Դϴ�.
}