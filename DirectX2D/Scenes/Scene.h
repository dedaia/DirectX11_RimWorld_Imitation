#pragma once

class Scene
{
public:
    virtual ~Scene() = default;

    //�ʼ�
    virtual void Update() = 0;
    virtual void Render() = 0;

    //�ɼ�
    virtual void Init() {}
    virtual void Quit() {}

    virtual void PreRender() {}
    virtual void PostRender() {}
};