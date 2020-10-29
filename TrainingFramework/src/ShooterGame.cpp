#include "ShooterGame.h"
#include "IntroState.h"

MainContext ShooterGame::s_mainContext = MainContext(new IntroState());
ResourceManager ShooterGame::s_resourceManager = ResourceManager();

void ShooterGame::Draw(ESContext* esContext)
{
	s_mainContext.Draw(esContext);
}

void ShooterGame::Update(ESContext* esContext, GLfloat deltaTime)
{
	s_mainContext.Update(esContext, deltaTime);
}

void ShooterGame::Key(ESContext* esContext, unsigned char key, bool bbIsPresseded)
{
	s_mainContext.Key(esContext, key, bbIsPresseded);
}

void ShooterGame::Mouse(ESContext* esContext, GLint x, GLint y, bool bbIsPresseded)
{
	s_mainContext.Mouse(esContext, x, y, bbIsPresseded);
}

void ShooterGame::MousePos(ESContext* esContext, GLint x, GLint y)
{
	s_mainContext.MousePos(esContext, x, y);
}

GLint ShooterGame::Run()
{
	ESContext esContext;
	esInitContext(&esContext);
	esCreateWindow(&esContext, "Demo Game", screenWidth, screenHeight, ES_WINDOW_RGB | ES_WINDOW_DEPTH);

	s_resourceManager.Init();

	if (s_mainContext.Init(&esContext) !=0)
		return 0;

	esRegisterDrawFunc(&esContext,ShooterGame::Draw);
	esRegisterUpdateFunc(&esContext, ShooterGame::Update);
	esRegisterKeyFunc(&esContext, ShooterGame::Key);
	esRegisterMouseFunc(&esContext, ShooterGame::Mouse);
	esRegisterMousePositionFunc(&esContext, ShooterGame::MousePos);
	esMainLoop(&esContext);
}
