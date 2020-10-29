#include "FontManager.h"

void FontManager::setPath(const std::string& path)
{
	m_path = path;
}

void FontManager::addFont(const std::string& font_file)
{
	std::string path = m_path + font_file;
	std::shared_ptr<Font> font = std::make_shared<Font>(path);
	m_fonts.push_back(font);
}

std::shared_ptr<Font> FontManager::getFont(int index)
{
	return m_fonts[index];
}
