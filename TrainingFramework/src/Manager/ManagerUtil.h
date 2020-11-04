#pragma once
#include "ShaderManager.h"
#include "TextureManager.h"
#include "FontManager.h"
#include "ModelManager.h"

extern int screenWidth;
extern int screenHeight;
extern ShaderManager& GetShaderManager();
extern TextureManager& GetTextureManager();
extern FontManager& GetFontManager();
extern ModelManager& GetModelManager();