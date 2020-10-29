#pragma once
#include "Models.h"
#include <vector>
#include <memory>

class ModelManager
{
public:
	explicit ModelManager() {}
	void setPath(const std::string& path);
	void addModel(const std::string& );
	std::shared_ptr<Models> getModel(int index);

private:
	std::vector<std::shared_ptr<Models>> m_models;
	std::string m_path;
};

