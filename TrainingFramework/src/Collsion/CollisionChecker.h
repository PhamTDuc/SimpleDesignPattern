#pragma once
#include "Bullet.h"
#include "Enemy.h"
#include "Sprite2D.h"

class CollisionChecker
{
public:
	static bool checkBulletEnemy(const std::shared_ptr<Bullet> bullet, const std::shared_ptr<Enemy> enemy);
	static bool checkEnemyHorizontal(int screenHeight, std::shared_ptr<Enemy> enemy);
};

