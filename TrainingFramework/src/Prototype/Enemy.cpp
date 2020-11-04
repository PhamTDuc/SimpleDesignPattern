#include "Enemy.h"
#include "Utils.h"

void Enemy::Update(GLfloat deltatime)
{
	Vector2 pos = Get2DPosition();
	pos.y += 98/2 * GetSize().x * deltatime * deltatime;
	Set2DPosition(pos);
}


std::shared_ptr<Enemy> Enemy::clone()
{
	auto shader = GetShaderManager().getShader(0);
	auto model = GetModelManager().getModel(0);
	auto texture = GetTextureManager().getTexture(9+ randRange(0,2));
	
	auto rand_size = randRange(35, 60);
	auto rand_pos = Vector2(randRange(0, screenWidth), randRange(0, screenHeight));

	std::shared_ptr<Enemy> enemy=std::make_shared<Enemy>(model, shader, texture);
	enemy->SetSize(rand_size, rand_size);
	rand_pos.x = (rand_pos.x < rand_size) ? rand_size : rand_pos.x;
	rand_pos.x = (rand_pos.x > screenWidth - rand_size) ? screenWidth - rand_size : rand_pos.x;
	/*rand_pos.y = (rand_pos.y < rand_size) ? rand_size : rand_pos.y;
	rand_pos.y = (rand_pos.y > screenWidth - rand_size) ? screenWidth - rand_size : rand_pos.y;*/
	rand_pos.y = 0;
	enemy->Set2DPosition(rand_pos);
	return enemy;
}
