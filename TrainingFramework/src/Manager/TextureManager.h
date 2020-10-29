#pragma once
#include "Texture.h"
class TextureManager
{
public:
	explicit TextureManager(){}
	void setPath(const std::string& path);
	void addTexture(const std::string& texture_file);
	std::shared_ptr<Texture> getTexture(int index);

private:
	std::vector<std::shared_ptr<Texture>> m_textures;
	std::string m_path;
};
