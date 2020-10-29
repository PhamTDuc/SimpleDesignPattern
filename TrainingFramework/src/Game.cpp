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


std::string m_ShaderPath;
std::string m_TexturePath;
std::string m_ModelsPath;
std::string m_FontPath;


std::shared_ptr<Sprite2D> m_BackGround;
std::list<std::shared_ptr<GameButton>>	m_listButton;
std::shared_ptr<Text>  m_Text_gameName;

std::shared_ptr<Sprite2D> m_Player;



GLint Init(ESContext* esContext)
{
	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);

	// data path
	std::string dataPath = "..\\Data\\";
	m_ShaderPath = dataPath + "Shaders\\";
	m_TexturePath = dataPath + "Textures\\";
	m_ModelsPath = dataPath + "Model\\";
	m_FontPath = dataPath + "fonts\\";

	ResourceManager::Init();
	// Shader Manager
	// GetShaderManager()->setPath(m_ShaderPath);
	// GetShaderManager()->addShader("TextureShader.vs", "TextureShader.fs");
	// GetShaderManager()->addShader("TextShader.vs", "TextShader.fs");

	// Texture Manager
	// GetTextureManager()->setPath(m_TexturePath);
	// GetTextureManager()->addTexture("bg_main_menu.tga");
	// GetTextureManager()->addTexture("button_play.tga");
	// GetTextureManager()->addTexture("button_quit.tga");
	// GetTextureManager()->addTexture("Player.tga");

	// Font Manager
	// GetFontManager()->setPath(m_FontPath);
	// GetFontManager()->addFont("arialbd.ttf");

	//model
	// std::string path = m_ModelsPath + "Sprite2D.nfg";
	// std::shared_ptr<Models> model = std::make_shared<Models>(path, NFG);

	//texture
	/*std::shared_ptr<Texture> texture1 = std::make_shared<Texture>();
	std::string file = m_TexturePath + "bg_main_menu.tga";
	texture1->Init(file.c_str(), GL_CLAMP_TO_EDGE, GL_LINEAR_MIPMAP_LINEAR);*/

	//shader
	/*std::shared_ptr<Shaders>  shader;
	shader = std::make_shared<Shaders>();
	std::string vs = m_ShaderPath + "TextureShader.vs";
	std::string fs = m_ShaderPath + "TextureShader.fs";
	shader->Init(vs, fs);*/

	//game object
	//BackGround
	auto shader = GetShaderManager()->getShader(0);
	auto texture = GetTextureManager()->getTexture(0);
	auto model = GetModelManager()->getModel(0);
	m_BackGround = std::make_shared<Sprite2D>(model, shader, texture);
	m_BackGround->Set2DPosition(screenWidth / 2, screenHeight / 2);
	m_BackGround->SetSize(screenWidth, screenHeight);

	//play button
	//texture
	//std::shared_ptr<Texture> texture2 = std::make_shared<Texture>();
	//std::string file1 = m_TexturePath + "button_play.tga";
	//texture2->Init(file1.c_str(), GL_CLAMP_TO_EDGE, GL_LINEAR_MIPMAP_LINEAR);
	auto texture1 = GetTextureManager()->getTexture(1);
	std::shared_ptr<GameButton> button = std::make_shared<GameButton>(model, shader, texture1);
	button->Set2DPosition(screenWidth / 2, 400);
	button->SetSize(200, 50);
	button->SetOnClick([]() {
		//playgame
	});
	m_listButton.push_back(button);

	//exit button
	/*std::shared_ptr<Texture> texture3 = std::make_shared<Texture>();
	std::string file2 = m_TexturePath + "button_quit.tga";
	texture3->Init(file2.c_str(), GL_CLAMP_TO_EDGE, GL_LINEAR_MIPMAP_LINEAR);*/
	auto texture2 = GetTextureManager()->getTexture(2);
	button = std::make_shared<GameButton>(model, shader, texture2);
	button->Set2DPosition(screenWidth / 2, 500);
	button->SetSize(200, 50);
	button->SetOnClick([]() {
		exit(0);
	});
	m_listButton.push_back(button);


	//text game title
	/*std::shared_ptr<Shaders>  shader1;
	shader1 = std::make_shared<Shaders>();
	std::string vs1 = m_ShaderPath + "TextShader.vs";
	std::string fs1 = m_ShaderPath + "TextShader.fs";
	shader1->Init(vs1, fs1);*/
	//font
	/*std::string path1 = m_FontPath + "arialbd.ttf";
	std::shared_ptr<Font> font = std::make_shared<Font>(path1);*/
	auto font = GetFontManager()->getFont(0);

	std::string Text_str = "SAMPLE NAME";
	auto shader1 = GetShaderManager()->getShader(1);
	m_Text_gameName = std::make_shared< Text>(shader1, font, Text_str, TEXT_COLOR::GREEN, 1.0);
	m_Text_gameName->Set2DPosition(Vector2(screenWidth / 2 - 80, 300));




	// sample player
	/*std::shared_ptr<Texture> texture5 = std::make_shared<Texture>();
	std::string file4 = m_TexturePath + "Player.tga";
	texture5->Init(file4.c_str(), GL_CLAMP_TO_EDGE, GL_LINEAR_MIPMAP_LINEAR);*/

	auto texture3 = GetTextureManager()->getTexture(3);
	m_Player = std::make_shared<Sprite2D >(model, shader, texture3);
	m_Player->Set2DPosition(screenWidth / 2, screenHeight - 100);
	m_Player->SetSize(50, 50);
	return 0;
}

void Draw(ESContext* esContext)
{
	//clear screen
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//draw game object
	m_BackGround->Draw();
	for (auto& obj : m_listButton)
		obj->Draw();
	m_Text_gameName->Draw();

	m_Player->Draw();

	eglSwapBuffers(esContext->eglDisplay, esContext->eglSurface);
}

void Update(ESContext* esContext, GLfloat deltaTime)
{
	//update game object
	m_BackGround->Update(deltaTime);
	for (auto& obj : m_listButton)
		obj->Update(deltaTime);
	m_Text_gameName->Update(deltaTime);

	m_Player->Update(deltaTime);
}

void Key(ESContext* esContext, unsigned char key, bool bbIsPresseded)
{
	//handle key Event
	if (key == KEY_BACK) // key ESC
		exit(0);
}

void Mouse(ESContext* esContext, GLint x, GLint y, bool bbIsPresseded)
{
	//handle Mouse Event
	for (auto it : m_listButton)
	{
		(it)->HandleTouchEvents(x, y, bbIsPresseded);
		if ((it)->IsHandle()) break;
	}
}


void MousePos(ESContext* esContext, GLint x, GLint y)
{
	//handle Mouse Event
}

void CleanUp()
{
	//free resource
}

GLint _tmain(GLint argc, _TCHAR* argv[])
{

	//ESContext esContext;
	//esInitContext(&esContext);
	//esCreateWindow(&esContext, "Demo Game", screenWidth, screenHeight, ES_WINDOW_RGB | ES_WINDOW_DEPTH);

	//if (Init(&esContext) != 0)
	//	return 0;

	//esRegisterDrawFunc(&esContext, Draw);
	//esRegisterUpdateFunc(&esContext, Update);
	//esRegisterKeyFunc(&esContext, Key);
	//esRegisterMouseFunc(&esContext, Mouse);
	//esRegisterMousePositionFunc(&esContext, MousePos);
	//esMainLoop(&esContext);

	////releasing OpenGL resources
	//CleanUp();
	ShooterGame::Run();
	//identifying memory leaks
	//MemoryDump();
	//printf("Press any key...\n");
	//_getch();

	return 0;
}

//#endif