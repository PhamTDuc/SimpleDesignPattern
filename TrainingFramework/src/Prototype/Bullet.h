#pragma once
#include "Sprite2D.h"
#include "ManagerUtil.h"

class Bullet
{
private:
	Vector2 m_pos;
	static std::unique_ptr<Sprite2D> s_bullet;
public:
	//using Sprite2D::Sprite2D;
	Bullet(const Vector2& pos = Vector2(0,0)): m_pos(pos){}
	void Update(GLfloat deltatime);
	void Draw();
	Vector2& getPos() {return m_pos;}
	static const Vector2& getSize() { return s_bullet->GetSize(); }
	static void Init();
	static std::shared_ptr<Bullet> clone(const Vector2&);
};

