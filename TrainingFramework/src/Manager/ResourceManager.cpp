#include "ResourceManager.h"

ShaderManager ResourceManager::s_shaderManager =  ShaderManager();
TextureManager ResourceManager::s_textureManager =  TextureManager();
FontManager ResourceManager::s_fontManager = FontManager();
ModelManager ResourceManager::s_modelManager =  ModelManager();

ShaderManager& GetShaderManager()
{
	return ResourceManager::getShaderManager();
}

TextureManager& GetTextureManager()
{
	return ResourceManager::getTextureManager();
}

FontManager& GetFontManager()
{
	return ResourceManager::getFontManager();
}

ModelManager& GetModelManager()
{
	return ResourceManager::getModelManager();
}

void ResourceManager::Init()
{
	std::string path = "..\\Data\\";
	std::string shaderPath = path + "Shaders\\";
	std::string texturePath = path + "Textures\\";
	std::string fontPath = path + "fonts\\";
	std::string modelPath = path + "Model\\";
	
	// Shader Manager
	GetShaderManager().setPath(shaderPath);
	GetShaderManager().addShader("TextureShader.vs", "TextureShader.fs");
	GetShaderManager().addShader("TextShader.vs", "TextShader.fs");

	// Texture Manager
	GetTextureManager().setPath(texturePath);
	GetTextureManager().addTexture("bg_main_menu.tga");
	GetTextureManager().addTexture("bg_play.tga");
	GetTextureManager().addTexture("bullet.tga");
	GetTextureManager().addTexture("button_back.tga");
	GetTextureManager().addTexture("button_exit_game.tga");
	GetTextureManager().addTexture("button_play.tga");
	GetTextureManager().addTexture("button_quit.tga");
	GetTextureManager().addTexture("button_resume.tga");
	GetTextureManager().addTexture("button_setting.tga");
	GetTextureManager().addTexture("Enemy_01.tga");
	GetTextureManager().addTexture("Enemy_02.tga");
	GetTextureManager().addTexture("Enemy_03.tga");
	GetTextureManager().addTexture("explosive.tga");
	GetTextureManager().addTexture("player.tga");

	// Font Manager
	GetFontManager().setPath(fontPath);
	GetFontManager().addFont("arialbd.ttf");

	// Model Manager
	getModelManager().setPath(modelPath);
	getModelManager().addModel("Sprite2D.nfg");
}
