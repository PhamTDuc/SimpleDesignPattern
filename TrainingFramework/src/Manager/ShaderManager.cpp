#include "ShaderManager.h"

void ShaderManager::setPath(const std::string& path)
{
	m_path = path;
}

void ShaderManager::addShader(const std::string& vs_filename, const std::string& fs_filename)
{
	std::shared_ptr<Shaders> shader = std::make_shared<Shaders>();
	shader->Init(m_path + vs_filename, m_path + fs_filename);
	m_shaders.push_back(shader);
}

std::shared_ptr<Shaders> ShaderManager::getShader(int index)
{
	return m_shaders[index];
}


