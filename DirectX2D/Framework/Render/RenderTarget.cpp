#include "Framework.h"

// ���� ����(Ȥ�� ���߿� �ٸ� ������ �����Ѵٸ�, �װͱ���)�� ���ؼ� ���������
// ǥ�� ���� ���� ���� (Ư���� ��� Ư���� ������� ǥ���Ѵ�)

RenderTarget::RenderTarget(UINT width, UINT height)
    : width(width), height(height)
{
    // �ǵ��� �����ٸ� �Ʒ�(���� �Ҵ�), ȿ���� ���Ѵٸ� ��(�̴ϼȶ�����)
    // this->width = width;
    // this->height = height;

    CreateRTVTexture();
    CreateRTV();
    CreateSRV();
}

RenderTarget::~RenderTarget()
{
    rtvTexture->Release();
    rtv->Release();
}

void RenderTarget::Set(Float4 clearColor)
{
    DC->OMSetRenderTargets(1, &rtv, nullptr);
    DC->ClearRenderTargetView(rtv, (float*)&clearColor);
}

void RenderTarget::CreateRTVTexture()
{
    // �⺻ ������ ���ؼ��� ����� ���� ���� ���� ��, �ڷḦ �޴´�(���� ����)
    // ���� Ÿ���� ���ؼ��� �ڷḦ ���� ��, ���� ��� ������ �����Ѵ�

    D3D11_TEXTURE2D_DESC desc = {};
    desc.Width = width;
    desc.Height = height;
    desc.MipLevels = 1; // �� ���� ����, 1 = "�⺻ ���� = �⺻ ũ��"�� ���Ѵ�
    desc.ArraySize = 1;
    desc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
    desc.SampleDesc.Count = 1;
    desc.Usage = D3D11_USAGE_DEFAULT;
    desc.BindFlags = D3D11_BIND_SHADER_RESOURCE | D3D11_BIND_RENDER_TARGET;

    //���� ������ �������� 2D �ؽ�ó �簡�� �� rtv�ؽ�ó�� �ݿ�
    DEVICE->CreateTexture2D(&desc, nullptr, &rtvTexture);
}

// ���� Ÿ���� ���� �߰����� ���� ����, �ݿ�

void RenderTarget::CreateRTV()
{
    D3D11_RENDER_TARGET_VIEW_DESC desc = {};
    desc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
    desc.ViewDimension = D3D11_RTV_DIMENSION_TEXTURE2D;

    DEVICE->CreateRenderTargetView(rtvTexture, &desc, &rtv);
}

void RenderTarget::CreateSRV()
{
    D3D11_SHADER_RESOURCE_VIEW_DESC desc = {};
    desc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
    desc.ViewDimension = D3D11_SRV_DIMENSION_TEXTURE2D;
    desc.Texture2D.MipLevels = 1;

    DEVICE->CreateShaderResourceView(rtvTexture, &desc, &srv);
}