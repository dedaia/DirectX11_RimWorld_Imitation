#pragma once

class RenderTarget
{
public:
    RenderTarget(UINT width = WIN_WIDTH, UINT height = WIN_HEIGHT);
    ~RenderTarget();

    void Set(Float4 clearColor = Float4(1, 1, 1, 1)); //���ų� ���� ���� �����ؼ� ���� �ϱ�

    //���̴� ���ҽ� �ְ�ޱ�
    ID3D11ShaderResourceView* GetSRV() { return srv; }

private:
    //ȭ�� ���� �����
    void CreateRTVTexture();
    void CreateRTV();
    void CreateSRV();

    //���� ������ ���� ����
    UINT width;
    UINT height;

    //���� Ÿ�� ȭ�� ���� (*���̷�Ʈ x�� �����Ǵ� �Լ��� �ִ�)
    ID3D11Texture2D* rtvTexture; // �ؽ�ó
    ID3D11RenderTargetView* rtv; // ���� Ÿ�� ��(��)
    ID3D11ShaderResourceView* srv; // ���̴� ���ҽ��� ���� ��� �� ��(��)
};

