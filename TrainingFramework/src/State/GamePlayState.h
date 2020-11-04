#pragma once
#include <list>
#include "GameBaseState.h"
#include "MainContext.h"
#include "GameButton.h"
#include "Enemy.h"
#include "Bullet.h"
#include "Text.h"
#include "ExplosiveEffect.h"
#include "Utils.h"

class GamePlayState : public GameBaseState
{
private:
    std::shared_ptr<Sprite2D> m_backGround;
    std::shared_ptr<Sprite2D> m_Player;
    std::shared_ptr<Text> m_DisplayScore;
    std::shared_ptr<Text> m_DisplayHealth;
    std::list<std::shared_ptr<Enemy>> m_enemies;
    std::list<std::shared_ptr<Bullet>> m_bullets;
    std::shared_ptr<ExplosiveEffect> m_explosive;
    TimeSync m_timesync;
    enum class PlayerState{STAND = 0, MOVE_LEFT, MOVE_RIGHT};
    PlayerState m_playerState = PlayerState::STAND;
    int m_currentScore = 0;
    double m_level = 0.5;
    int m_health, m_nEnemies;
public:
    // TODO 
    // max_score is equal to number of enemies
    GamePlayState(int n_enemies = 10, int max_health = 5):GameBaseState(), m_nEnemies(n_enemies), m_health(max_health){} 
    GLint Init() override;
    void Draw() override;
    void Update(GLfloat) override;
    void Key(unsigned char key, bool bbIsPressed) override;
    void Mouse(GLint x, GLint y, bool bbIsPressed) override;
    void MousePos(GLint x, GLint y) override;
    // void CleanUp() = 0;
};

