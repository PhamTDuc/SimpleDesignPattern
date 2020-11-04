#pragma once
#include "Sprite2D.h"
#include "ManagerUtil.h"
#include <array>
class Enemy : public Sprite2D
{
public:
	using Sprite2D::Sprite2D;
	void Enemy::Update(GLfloat deltatime) override;
	static std::shared_ptr<Enemy> clone();
};

