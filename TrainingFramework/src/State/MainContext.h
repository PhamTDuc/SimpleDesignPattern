#pragma once
#include "GameBaseState.h"
class MainContext
{
private:
	GameBaseState* m_state;
public:
	MainContext(GameBaseState*);
	void changeState(GameBaseState* state);
	~MainContext() { delete m_state; }
	GLint Init(ESContext*);
	void Draw(ESContext*);
	void Update(ESContext*, GLfloat);
	void Key(ESContext*, unsigned char key, bool bbIsPressed);
	void Mouse(ESContext*, GLint x, GLint y, bool bbIsPressed);
	void MousePos(ESContext*, GLint x, GLint y);
};

