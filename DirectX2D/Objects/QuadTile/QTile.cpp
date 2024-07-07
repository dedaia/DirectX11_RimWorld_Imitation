#include "Framework.h"

QTile::QTile(QTile::Data data) : Quad(data.textureFile), data(data)
{
	localPosition = data.pos;
	localRotation.z = data.angle;

	savetype = data.type;

	Touchme = new RectCollider(texture->GetSize());
	Touchme->SetParent(this);

	TileCHildren = new OBJTile();
	TileCHildren->Pos() = this->Pos();
	TileCHildren->SetActive(false);

	Floortile = new OBJTile(L"Textures/Tile/Tiles/NoTile/planks.png");
	Floortile->Pos() = this->Pos();
	Floortile->SetActive(false);
}
QTile::~QTile()
{
	delete Touchme;
	delete node1;
	delete TileCHildren;
	delete Floortile;
}

void QTile::SetTexture(wstring file)
{
	Quad::SetTexture(file); // 실제로 그림을 바꾸고
	data.textureFile = file; //타일의 정보에도 텍스처 파일 이름 반영
}

void QTile::SetAngle(float angle)
{
	localRotation.z = angle;
	data.angle = angle;
}

void QTile::Update()
{
	if (Touchme->IsCircleCollision((CircleCollider*)CM->rim1->cirlce))
	{
		data.type = OBJ;
		CM->rim1->Mytile = node1->index;
	}
	else if (Touchme->IsCircleCollision((CircleCollider*)CM->rim2->cirlce))
	{
		data.type = OBJ;
		CM->rim2->Mytile = node1->index;
	}
	else if (Touchme->IsCircleCollision((CircleCollider*)CM->rim3->cirlce))
	{
		data.type = OBJ;
		CM->rim3->Mytile = node1->index;
	}
	else if (Touchme->IsCircleCollision((CircleCollider*)CM->rim4->cirlce))
	{
		data.type = OBJ;
		CM->rim4->Mytile = node1->index;
	}
	else
	{
		data.type = savetype;
	}

	switch (TileCHildren->bbb)
	{
	case OBJTile::BAD:
		break;
	case OBJTile::FIRE:
		break;
	case OBJTile::CART:
		break;
	case OBJTile::CHAIR:
		break;
	case OBJTile::CHEST:
		break;
	case OBJTile::COFFIN:
		break;
	case OBJTile::DOOR:
		if (!OBJTTT && TileCHildren->Active())
		{
			if (Touchme->IsCircleCollision((CircleCollider*)CM->rim1->cirlce) || Touchme->IsCircleCollision((CircleCollider*)CM->rim2->cirlce)
				|| Touchme->IsCircleCollision((CircleCollider*)CM->rim3->cirlce) || Touchme->IsCircleCollision((CircleCollider*)CM->rim4->cirlce))
			{
				TileCHildren->SetTexture(L"Textures/Tile/Tiles/NoTile/SA/door_open.png");
			}
			else
			{
				TileCHildren->SetTexture(L"Textures/Tile/Tiles/NoTile/SA/door_closed.png");
			}
		}
		break;
	case OBJTile::TABLE:
		break;
	case OBJTile::WALL:
		savetype = OBJ;
		break;
	}

	if (!TileCHildren->Active())
	{
		savetype = BG;
	}

	TileCHildren->Update();
	Floortile->Update();
	ColliderMouse();
	Touchme->UpdateWorld();
	Quad::UpdateWorld();
}
void QTile::Render()
{
	Quad::Render();
	TileCHildren->Render();
	Floortile->Render();

	// Touchme->Render();
}

void QTile::ColliderMouse()
{
	if (Touchme->IsRectCollision((RectCollider*)UIS->haldng))
	{
		UIS->SELETCtileintDAta = node1->index;

		// 건물 철거 명령
		if (UIS->otherBTN[1]->GetDown001())
		{
			if (KEY_DOWN(VK_LBUTTON) && Touchme->IsRectCollision((RectCollider*)UIS->haldng))
			{
				if (!OBJTTT && TileCHildren->Active() && data.type != WOOD && data.type != FOOD)
				{
					UIS->SelectMarker.push_back(new Marker(node1->index, "BUILD"));
					UIS->SelectMarker[UIS->SelectMarker.size() - 1]->Pos() = this->Pos();

					chergun = true;
				}
			}
		}

		// 벌목 명령
		if (UIS->otherBTN[2]->GetDown001())
		{
			if (KEY_DOWN(VK_LBUTTON) && savetype == (QTile::Type)2)
			{
				UIS->SelectMarker.push_back(new Marker(node1->index, "WOOD"));
				UIS->SelectMarker[UIS->SelectMarker.size() - 1]->Pos() = this->Pos();
			}
		}
	}

	// 가구용
	if (!TileCHildren->Active())
	{
		if (KEY_PRESS(VK_LBUTTON))
		{
			if (Touchme->IsRectCollision((RectCollider*)UIS->haldng))
			{
				if (UIS->UI_BTN[9]->GetDown001() && UIS->ActiveData->Active())
				{
					TileCHildren->BuildOBJ(UIS->ActiveData->wwwsss);
					TileCHildren->SetActive(true);
					TileCHildren->bbb = UIS->ActiveData->bbb;
					TileCHildren->Rot() = UIS->ActiveData->Rot();
					savetype = (QTile::Type)UIS->ActiveData->settype;

					OBJTTT = true;

					pair<int, string> dlatl;
					pair<int, string> dlatl2;
					dlatl.first = node1->index;		// 건축 작업용
					dlatl2.first = node1->index;	// 상호작용
					string dlatl02;
					string dlatl03 = "BUILD";;
					switch (UIS->ActiveData->bbb)
					{
					case OBJTile::BAD:
						dlatl02 = "BAD";
						dlatl2.second = dlatl02;
						CM->TileInteractiondata.push_back(dlatl2);
						break;

					case OBJTile::FIRE:
						dlatl02 = "FIRE";
						dlatl2.second = dlatl02;
						CM->TileInteractiondata.push_back(dlatl2);
						break;

					case OBJTile::CART:
						dlatl02 = "CART";
						dlatl2.second = dlatl02;
						CM->TileInteractiondata.push_back(dlatl2);
						break;

					case OBJTile::CHAIR:
						dlatl02 = "CHAIR";
						dlatl2.second = dlatl02;
						CM->TileInteractiondata.push_back(dlatl2);
						break;

					case OBJTile::CHEST:
						dlatl02 = "CHEST";
						dlatl2.second = dlatl02;
						CM->TileInteractiondata.push_back(dlatl2);
						break;

					case OBJTile::COFFIN:
						dlatl02 = "COFFIN";
						dlatl2.second = dlatl02;
						CM->TileInteractiondata.push_back(dlatl2);
						break;

					case OBJTile::DOOR:
						dlatl02 = "DOOR";
						dlatl2.second = dlatl02;
						CM->TileInteractiondata.push_back(dlatl2);
						break;

					case OBJTile::TABLE:
						dlatl02 = "TABLE";
						dlatl2.second = dlatl02;
						CM->TileInteractiondata.push_back(dlatl2);
						break;

					case OBJTile::WALL:
						break;
					}
					dlatl.second = dlatl03;

					CM->Builddatas.push_back(dlatl);
				}
			}
		}
	}

	// 바닥 건축용
	if (!Floortile->Active())
	{
		if (Touchme->IsRectCollision((RectCollider*)UIS->haldng))
		{
			if (KEY_PRESS(VK_LBUTTON))
			{
				if (UIS->UI_BTN[11]->GetDown001() && UIS->ActiveData->Active())
				{
					BGTileBuildSet(UIS->ActiveData->wwwsss);
					Floortile->SetActive(true);
					this->TILE = true;

					pair<int, string> dlatl;

					dlatl.first = node1->index;
					dlatl.second = "BUILD";

					Floortile->stack = 1;

					CM->Builddatas.push_back(dlatl);
				}
			}
		}
	}

	// 작업 취소 버튼
	if (UIS->otherBTN[0]->GetDown001())
	{
		if (KEY_PRESS(VK_LBUTTON) && Touchme->IsRectCollision((RectCollider*)UIS->haldng))
		{
			if (OBJTTT)
			{
				OBJTTT = false;
				TileCHildren->SetActive(false);
			}
			
			if (TILE)
			{
				TILE = false;
				Floortile->SetActive(false);
			}
		}
	}
}

// 정보 세팅
void QTile::BGTileBuildSet(wstring data)
{
	apppci = data;
	Floortile->changebuild = true;
}
// 완성된 바닥타일
void QTile::BGTileBuildComplete()
{
	Floortile->SetActive(false);
	Quad::SetTexture(apppci);
	Floortile->changebuild = false;
}

void QTile::TileTEXChange()
{
	if (chergun)
	{
		TileCHildren->SetActive(false);

		for (int i = 0; i < UIS->SelectMarker.size(); ++i)
		{
			UIS->SelectMarker.erase(UIS->SelectMarker.begin() + i);
		}

		chergun = false;
	}
	else if (!chergun)
	{
		if (TILE)
		{
			BGTileBuildComplete();
			TILE = false;
		}
		if (OBJTTT)
		{
			TileCHildren->ChangeTTT();
			OBJTTT = false;
		}
	}	
}