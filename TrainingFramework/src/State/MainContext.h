#pragma once
#include "GameBaseState.h"
#include <stack>
extern MainContext& GetMainContext();
class MainContext
{
private:
	std::stack<GameBaseState*> m_states;
public:
	MainContext(GameBaseState*);
	void changeState(GameBaseState* state);
	void popState();
	~MainContext() { while (!m_states.empty()) { m_states.pop(); } }
	GLint Init(ESContext*);
	void Draw(ESContext*);
	void Update(ESContext*, GLfloat);
	void Key(ESContext*, unsigned char key, bool bbIsPressed);
	void Mouse(ESContext*, GLint x, GLint y, bool bbIsPressed);
	void MousePos(ESContext*, GLint x, GLint y);
};

