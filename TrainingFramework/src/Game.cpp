#include "targetver.h"
#include "Shaders.h"
#include "utilities.h" 


#include "GameButton.h"
#include "Text.h"
#include "Texture.h"
#include "Shaders.h"
#include "Models.h"
#include "Font.h"

#include "ManagerUtil.h"
#include "ResourceManager.h"
#include "ShooterGame.h"

int screenWidth = 480;
int screenHeight = 800;

GLint _tmain(GLint argc, _TCHAR* argv[])
{

	ShooterGame::Run();

	////releasing OpenGL resources
	//CleanUp();
	//identifying memory leaks
	//MemoryDump();
	//printf("Press any key...\n");
	//_getch();

	return 0;
}

//#endif