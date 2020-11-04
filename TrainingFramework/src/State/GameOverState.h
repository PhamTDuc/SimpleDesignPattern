#pragma once
#include "GameBaseState.h"
#include "MainContext.h"
#include "GameButton.h"
#include "Text.h"
class GameOverState : public GameBaseState
{
private:
    std::shared_ptr<Sprite2D> m_backGround;
    std::list<std::shared_ptr<GameButton>> m_listButtons;
    std::shared_ptr<Text> m_displayScore;
    int m_score;
public:
    GameOverState(int score = 0) : GameBaseState(), m_score(score){}
    GLint Init() override;
    void Draw() override;
    void Update(GLfloat) override;
    void Key(unsigned char key, bool bbIsPressed) override;
    void Mouse(GLint x, GLint y, bool bbIsPressed) override;
    void MousePos(GLint x, GLint y) override {}
    // void CleanUp() = 0;
};

