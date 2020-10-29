#include "ResourceManager.h"

ShaderManager* ResourceManager::s_shaderManager = new ShaderManager();
TextureManager* ResourceManager::s_textureManager = new TextureManager();
FontManager* ResourceManager::s_fontManager = new FontManager();
ModelManager* ResourceManager::s_modelManager = new ModelManager();

ShaderManager* GetShaderManager()
{
	return ResourceManager::getShaderManager();
}

TextureManager* GetTextureManager()
{
	return ResourceManager::getTextureManager();
}

FontManager* GetFontManager()
{
	return ResourceManager::getFontManager();
}

ModelManager* GetModelManager()
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
	GetShaderManager()->setPath(shaderPath);
	GetShaderManager()->addShader("TextureShader.vs", "TextureShader.fs");
	GetShaderManager()->addShader("TextShader.vs", "TextShader.fs");

	// Texture Manager
	GetTextureManager()->setPath(texturePath);
	GetTextureManager()->addTexture("bg_main_menu.tga");
	GetTextureManager()->addTexture("button_play.tga");
	GetTextureManager()->addTexture("button_quit.tga");
	GetTextureManager()->addTexture("Player.tga");

	// Font Manager
	GetFontManager()->setPath(fontPath);
	GetFontManager()->addFont("arialbd.ttf");

	// Model Manager
	getModelManager()->setPath(modelPath);
	getModelManager()->addModel("Sprite2D.nfg");

}
