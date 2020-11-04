#include "CollisionChecker.h"

bool CollisionChecker::checkBulletEnemy(const std::shared_ptr<Bullet> bullet, const std::shared_ptr<Enemy> enemy)
{
    if (bullet->getPos().x > enemy->Get2DPosition().x + enemy->GetSize().x || bullet->getPos().x + bullet->getSize().x <  enemy->Get2DPosition().x 
        || bullet->getPos().y > enemy->Get2DPosition().y + enemy->GetSize().y || bullet->getPos().y + bullet->getSize().y < enemy->Get2DPosition().y)
        return false;
    return true;
}

bool CollisionChecker::checkEnemyHorizontal(int screenHeight, std::shared_ptr<Enemy> enemy)
{
    if (enemy->GetSize().y + enemy->Get2DPosition().y >= screenHeight)
        return true;
    return false;
}
