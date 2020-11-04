#include "Bullet.h"

std::unique_ptr<Sprite2D> Bullet::s_bullet;

void Bullet::Init()
{
    auto shader = GetShaderManager().getShader(0);
    auto texture = GetTextureManager().getTexture(2);
    auto model = GetModelManager().getModel(0);
    s_bullet = std::make_unique<Sprite2D>(model, shader, texture);
    s_bullet->SetSize(20, 40);
}

void Bullet::Update(GLfloat deltatime)
{
  
    m_pos.y -= 24000 * deltatime * deltatime;
}

void Bullet::Draw()
{
    s_bullet->Set2DPosition(m_pos);
    s_bullet->Draw();
}

std::shared_ptr<Bullet> Bullet::clone(const Vector2& pos)
{
    std::shared_ptr<Bullet> bullet = std::make_shared<Bullet>(pos);
    return bullet;
}
