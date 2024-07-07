#pragma once

#include "targetver.h"
#define WIN32_LEAN_AND_MEAN

#define WIN_WIDTH 1280
#define WIN_HEIGHT 720

#define WIN_START_X 100
#define WIN_START_Y 100

#define CENTER_X (WIN_WIDTH * 0.5f)
#define CENTER_Y (WIN_HEIGHT * 0.5f)

#define DEVICE Device::Get()->GetDevice()
#define DC Device::Get()->GetDeviceContext()

#define KEY_DOWN(k) Keyboard::Get()->Down(k)
#define KEY_UP(k) Keyboard::Get()->Up(k)
#define KEY_PRESS(k) Keyboard::Get()->Press(k)

#define DELTA Timer::Get()->GetElapsedTime()

#define SCENE SceneManager::Get()
#define CAMERA Environment::Get()->GetMainCamera()

#define UIS UI_Scene::Get()
#define UISSA UI_Scene::Get()->Build_samples
#define UISBA UI_Scene::Get()->Badcs

#define FONT Font::Get()

#define MOUSE mouseOffset + (mousePos * mouseOscaleffset)
#define CM CommanderCCL::Get()

#define DB Default_Database::Get()

#include <windows.h>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <unordered_set>
#include <functional>

#include <d3d11.h>
#include <DirectXMath.h>
#include <d3dcompiler.h>

#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "d3dcompiler.lib")
#pragma comment(lib, "dxguid.lib")

//DirectXTex
#include <DirectXTex.h>
#pragma comment(lib, "DirectXTex.lib")

//DirectWrite
#include <d2d1_2.h>
#include <dwrite.h>

#include "Libraries/inc/fmod.hpp"
#pragma comment(lib, "Libraries/lib/fmod_vc.lib")

//ImGui
#include <ImGui.h>
#include <imgui_impl_dx11.h>
#include <imgui_impl_win32.h>

#pragma comment(lib, "ImGui.lib")

#pragma comment(lib, "d2d1.lib")
#pragma comment(lib, "dwrite.lib")

using namespace std;
using namespace DirectX;

typedef XMFLOAT4 Float4;
typedef XMFLOAT3 Float3;
typedef XMFLOAT2 Float2;
typedef XMMATRIX Matrix;

typedef function<void()> Event;
typedef function<void(void*)> ParamEvent;
typedef function<void(int)> IntParamEvent;

//Framework Header



#include "Framework/Utilities/Singleton.h"
#include "Framework/Utilities/Keyboard.h"
#include "Framework/Utilities/Timer.h"
#include "Framework/Utilities/Utility.h"
#include "Framework/Utilities/Observer.h"
#include "Framework/Utilities/tinyxml2.h"
#include "Framework/Utilities/Font.h"
#include "Framework/Utilities/Audio.h"
#include "Framework/Utilities/GlobalEvent.h"
#include "Framework/Utilities/BinaryWriter.h"
#include "Framework/Utilities/BinaryReader.h"

using namespace Utility;

#include "Framework/Math/Vector2.h"
#include "Framework/Math/GameMath.h"
#include "Framework/Math/Transform.h"

using namespace GameMath;

#include "Framework/System/Device.h"

#include "Framework/Shader/Shader.h"
#include "Framework/Shader/VertexShader.h"
#include "Framework/Shader/PixelShader.h"

#include "Framework/Buffer/VertexBuffer.h"
#include "Framework/Buffer/IndexBuffer.h"
#include "Framework/Buffer/ConstBuffer.h"
#include "Framework/Buffer/VertexLayouts.h"
#include "Framework/Buffer/GlobalBuffer.h"

#include "Framework/Render/Texture.h"
#include "Framework/Render/Frame.h"
#include "Framework/Render/Clip.h"
#include "Framework/Render/RenderTarget.h"

#include "Framework/Collision/Collider.h"
#include "Framework/Collision/RectCollider.h"
#include "Framework/Collision/CircleCollider.h"
#include "Framework/Collision/LineCollider.h"

#include "Framework/Environment/Camera.h"
#include "Framework/Environment/Environment.h"

//Algorithm Header
#include "Algorithm/Node.h"
#include "Algorithm/Heap.h"

#include "Libraries/Default_Database.h" // 가장 기본이 되는 데이터

//Object Header
#include "Objects/Basic/GameObject.h"
#include "Objects/Basic/Quad.h"
#include "Objects/Basic/Effect.h"

#include "Objects/UI/Button.h"
#include "Objects/UI/ProgressBar.h"
#include "Objects/UI/SelectTarget.h"
#include "Objects/UI/Schedule_CheckBox.h"
#include "Objects/UI/Marker.h"

#include "Objects/Rim/RimAI.h"
#include "Objects/Rim/RimCharacter.h"
#include "Objects/Rim/Soccer_Ball.h"

#include "Objects/UI/TIME_schedule.h"

#include "Objects/QuadTile/OBJTile.h"
#include "Objects/QuadTile/QTile.h"
#include "Objects/QuadTile/QTileEditMap.h"

#include "Scenes/UI_Scene.h"

#include "Objects/CommanderCCL.h"

//Scene Header
#include "Scenes/Scene.h"
#include "Manager/GameManager.h"
#include "Manager/EffectManager.h"
#include "Manager/BulletManager.h"
#include "Manager/CommandManager.h"
#include "Manager/SceneManager.h"


extern HWND hWnd;
extern Vector2 mousePos;
extern float mouseWheel;
extern Vector2 mouseOffset;
extern Vector2 mouseOscaleffset;