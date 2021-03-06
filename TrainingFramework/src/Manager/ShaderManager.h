#pragma once
#include "Shaders.h"

class ShaderManager
{
public:
	explicit ShaderManager(){}
	void setPath(const std::string& path);
	void addShader(const std::string& vs_path, const std::string& fs_path);
	std::shared_ptr<Shaders> getShader(int index);

private:
	std::vector<std::shared_ptr<Shaders>> m_shaders;
	std::string m_path;
};
