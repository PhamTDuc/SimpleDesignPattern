#pragma once
#include "ShaderManager.h"
#include "TextureManager.h"
#include "FontManager.h"
#include "ModelManager.h"

class ResourceManager
{
private:
	static ShaderManager* s_shaderManager;
	static TextureManager* s_textureManager;
	static FontManager* s_fontManager;
	static ModelManager* s_modelManager;
public:
	static ShaderManager* getShaderManager() { return s_shaderManager;}
	static TextureManager* getTextureManager() { return s_textureManager;}
	static FontManager* getFontManager() { return s_fontManager;}
	static ModelManager* getModelManager() { return s_modelManager;}
	static void Init();
};

