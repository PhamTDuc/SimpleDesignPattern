#include "TextureManager.h"

void TextureManager::setPath(const std::string& path)
{
	m_path = path;
}

void TextureManager::addTexture(const std::string& texture_file)
{
	std::shared_ptr<Texture> texture = std::make_shared<Texture>();
	std::string file = m_path + texture_file;
	texture->Init(file.c_str(), GL_CLAMP_TO_EDGE, GL_LINEAR_MIPMAP_LINEAR);
	m_textures.push_back(texture);
}

std::shared_ptr<Texture> TextureManager::getTexture(int index)
{
	return m_textures[index];
}
