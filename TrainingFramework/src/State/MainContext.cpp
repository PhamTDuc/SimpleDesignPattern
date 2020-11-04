#include "MainContext.h"
#include "Bullet.h"

MainContext::MainContext(GameBaseState* state)
{
	changeState(state);
}

void MainContext::changeState(GameBaseState* state)
{
	if (state) m_states.push(state);
}

void MainContext::popState()
{
	if (m_states.size() > 1)
		m_states.pop();
}

GLint MainContext::Init(ESContext* esContext)
{
	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);

	auto state = m_states.top();
	if (state) state->Init();
	return 0;
}

void MainContext::Draw(ESContext* esContext)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	auto state = m_states.top();
	if (state) state->Draw();
	eglSwapBuffers(esContext->eglDisplay, esContext->eglSurface);
}

void MainContext::Update(ESContext* esContext, GLfloat deltatime)
{
	auto state = m_states.top();
	if (state) state->Update(deltatime);
}

void MainContext::Key(ESContext*, unsigned char key, bool bbIsPressed)
{
	auto state = m_states.top();
	if (state) state->Key(key, bbIsPressed);
}

void MainContext::Mouse(ESContext*, GLint x, GLint y, bool bbIsPressed)
{
	if (!bbIsPressed)
	{
		auto state = m_states.top();
		if (state) state->Mouse(x, y, bbIsPressed);
	}
}

void MainContext::MousePos(ESContext*, GLint x, GLint y)
{
	auto state = m_states.top();
	if (state) state->MousePos(x, y);
}
