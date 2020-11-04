#pragma once
#include "esUtil.h"
#include "ResourceManager.h"
#include "MainContext.h"
class ShooterGame
{
private:
	static MainContext s_mainContext;
	static ResourceManager s_resourceManager;
	static void Draw(ESContext* esContext);
	static void Update(ESContext* esContext, GLfloat deltaTime);
	static void Key(ESContext* esContext, unsigned char key, bool bbIsPresseded);
	static void Mouse(ESContext* esContext, GLint x, GLint y, bool bbIsPresseded);
	static void MousePos(ESContext* esContext, GLint x, GLint y);
public:
	static GLint Run();
	static MainContext& getMainContext() { return s_mainContext; }
	//static ResourceManager& getResouceManager() { return s_resourceManager; }
};

