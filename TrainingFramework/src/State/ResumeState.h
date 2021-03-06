#pragma once
#include "GameBaseState.h"
#include "GameButton.h"
class ResumeState : public GameBaseState
{
private:
    std::shared_ptr<Sprite2D> m_backGround;
    std::list<std::shared_ptr<GameButton>> m_listButtons;
public:
    GLint Init() override;
    void Draw() override;
    void Update(GLfloat) override;
    void Key(unsigned char key, bool bbIsPressed) override;
    void Mouse(GLint x, GLint y, bool bbIsPressed) override;
    void MousePos(GLint x, GLint y) override {}
    // void CleanUp() = 0;
};

