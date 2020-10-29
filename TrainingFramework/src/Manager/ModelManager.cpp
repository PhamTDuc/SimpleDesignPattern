#include "ModelManager.h"

void ModelManager::setPath(const std::string& path)
{
	m_path = path;
}

void ModelManager::addModel(const std::string& model_file)
{
	std::shared_ptr<Models> model = std::make_shared<Models>(m_path + model_file, NFG);
	m_models.push_back(model);
}

std::shared_ptr<Models> ModelManager::getModel(int index)
{
	return m_models[index];
}
