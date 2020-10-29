#pragma once
#include "esUtil.h"
#include "Sprite2D.h"
#include "GameConfig.h"
#include "ManagerUtil.h"
class MainContext;
class GameBaseState
{
protected:
    MainContext* m_context;
public:
    void setContext(MainContext* context)
    {
        this->m_context = context;
    }
    MainContext* getContext() { return m_context; }
    virtual ~GameBaseState() {}
    virtual GLint Init() = 0;
    virtual void Draw() = 0;
    virtual void Update(GLfloat) = 0;
    virtual void Key(unsigned char key, bool bbIsPressed) = 0;
    virtual void Mouse(GLint x, GLint y, bool bbIsPressed) = 0;
    virtual void MousePos(GLint x, GLint y) = 0;
    // virtual void CleanUp() = 0;
};