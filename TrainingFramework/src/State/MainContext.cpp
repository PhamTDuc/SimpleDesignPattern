#include "MainContext.h"

MainContext::MainContext(GameBaseState* state)
{
	changeState(state);
}

void MainContext::changeState(GameBaseState* state)
{
	if (m_state) delete m_state;
	m_state = state;
	if (m_state) m_state->setContext(this);
}

GLint MainContext::Init(ESContext* esContext)
{
	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
	if (m_state) m_state->Init();
	return 0;
}

void MainContext::Draw(ESContext* esContext)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	if (m_state) m_state->Draw();
	eglSwapBuffers(esContext->eglDisplay, esContext->eglSurface);
}

void MainContext::Update(ESContext* esContext, GLfloat deltatime)
{
	if (m_state) m_state->Update(deltatime);
}

void MainContext::Key(ESContext*, unsigned char key, bool bbIsPressed)
{
	if (m_state) m_state->Key(key, bbIsPressed);
}

void MainContext::Mouse(ESContext*, GLint x, GLint y, bool bbIsPressed)
{
	if (m_state) m_state->Mouse(x, y, bbIsPressed);
}

void MainContext::MousePos(ESContext*, GLint x, GLint y)
{
	if (m_state) m_state->MousePos(x, y);
}
