#include "GamePlayState.h"
#include "ResumeState.h"
#include "GameOverState.h"
#include "GamePlayState.h"
#include "CollisionChecker.h"

GLint GamePlayState::Init()
{
    m_timesync.Register(0, .2);
    m_timesync.Register(1, 2.5);
    m_timesync.Register(2, m_level);
    m_timesync.Register(3, 10);

    // Initialize Background
    auto shader = GetShaderManager().getShader(0);
    auto texture = GetTextureManager().getTexture(1);
    auto model = GetModelManager().getModel(0);
    m_backGround = std::make_shared<Sprite2D>(model, shader, texture);
    m_backGround->Set2DPosition(screenWidth / 2, screenHeight / 2);
    m_backGround->SetSize(screenWidth, screenHeight);

    texture = GetTextureManager().getTexture(13);
    m_Player = std::make_shared<Sprite2D>(model, shader, texture);
    m_Player->Set2DPosition(screenWidth / 2, screenHeight - 100);
    m_Player->SetSize(50, 50);

    auto font = GetFontManager().getFont(0);

    shader = GetShaderManager().getShader(1);
    m_DisplayScore = std::make_shared<Text>(shader, font, "Score: 0", TEXT_COLOR::CYAN, 1.0);
    m_DisplayScore->Set2DPosition(Vector2(10, 40));

    m_DisplayHealth = std::make_shared<Text>(shader, font, "Health: " + std::to_string(m_health), TEXT_COLOR::RED, 0.8);
    m_DisplayHealth->Set2DPosition(Vector2(10, 60));
     
    // Generate Explosive 
    texture = GetTextureManager().getTexture(12);
    m_explosive = std::make_shared<ExplosiveEffect>(model, shader, texture, Vector2(960, 768), Vector2(192, 192),1,19,10.0);
    m_explosive->SetSize(100, 100);
    m_explosive->Set2DPosition(screenWidth / 2, screenHeight - 100);
    //m_explosive->StartAnimation();
    return 0;
}

void GamePlayState::Draw()
{
    m_backGround->Draw();
    m_Player->Draw();
    m_DisplayScore->Draw();
    m_DisplayHealth->Draw();
    for (auto bullet : m_bullets)
    {
        bullet->Draw();
    }
    for (auto enemy : m_enemies)
    {
        enemy->Draw();
    }

    m_explosive->Draw();
}

void GamePlayState::Update(GLfloat deltatime)
{
    Vector2 pos= m_Player->Get2DPosition();
    switch (m_playerState)
    {
    case PlayerState::MOVE_LEFT:
    {
        pos.x -= deltatime * 500;
        break;
    }
    case PlayerState::MOVE_RIGHT:
    {
        pos.x += deltatime * 500;
        break;
    }
    default:
        break;
    }

    for (auto enemy : m_enemies)
        enemy->Update(deltatime);
    for (auto bullet : m_bullets)
        bullet->Update(deltatime);
   
    m_timesync.Update(deltatime);

    // Add bullet after a certain time
    if (m_timesync.getStep(0))
        m_bullets.push_front(Bullet::clone(m_Player->Get2DPosition()));
    // Add enemy after a certain time
    if (m_timesync.getStep(2))
        m_enemies.push_back(Enemy::clone());
    // Remove bullet when exceeds 10
    if (m_timesync.getStep(1) && m_bullets.size() > 10)
        m_bullets.resize(10);
    // Update level after a certain time
    if (m_timesync.getStep(3))
    {
        m_level = (m_level > 0.2) ? m_level - 0.1 : 0.1;
        m_timesync.changeStep(2, m_level);
    }

    // Remove Dead enemy and bullet
    auto it_enemy_del = m_enemies.end();
    auto it_bullet_del = m_bullets.end();

    for (auto it_enemy = m_enemies.begin(); it_enemy != m_enemies.end(); ++it_enemy)
    {
        for (auto it_bullet = m_bullets.begin(); it_bullet != m_bullets.end(); ++it_bullet)
        {
            if (CollisionChecker::checkBulletEnemy(*it_bullet, *it_enemy))
            {
                it_enemy_del = it_enemy;
                it_bullet_del = it_bullet;
                ++m_currentScore;
                m_DisplayScore->setText(std::string("Score: ") + std::to_string(m_currentScore));
            }
        }

        if (CollisionChecker::checkEnemyHorizontal(screenHeight, *it_enemy))
        {
            --m_health;
            m_DisplayHealth->setText(std::string("Health: ") + std::to_string(m_health));
            it_enemy_del = it_enemy;
        }
    }

    if (it_enemy_del != m_enemies.end())
    {
        m_enemies.erase(it_enemy_del);
    }

    if (it_bullet_del != m_bullets.end())
    {
        m_bullets.erase(it_bullet_del);
    }

    if (m_health <= 0)
    {
        GetMainContext().popState();
        auto state = new GameOverState(m_currentScore);
        state->Init();
        GetMainContext().changeState(state);
    }
}

void GamePlayState::Key(unsigned char key, bool bbIsPressed)
{
    if (key == KEY_BACK && !bbIsPressed)
    {
        auto state = new ResumeState();
        state->Init();
        GetMainContext().changeState(state);
    }

   /* if (bbIsPressed)
    {
        switch (key)
        {
        case KEY_LEFT:
            m_playerState = PlayerState::MOVE_LEFT;
            break;
        case KEY_RIGHT:
            m_playerState = PlayerState::MOVE_RIGHT;
            break;
        default:
            break;
        }
    }
    else
    {
        m_playerState = PlayerState::STAND;
    }*/
}

void GamePlayState::Mouse(GLint x, GLint y, bool bbIsPressed){}

void GamePlayState::MousePos(GLint x, GLint y)
{
    auto pos = m_Player->Get2DPosition();
    pos.x = x;
    m_Player->Set2DPosition(pos);
}
