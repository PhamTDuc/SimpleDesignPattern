#pragma once
#include "Font.h"
#include <vector>
#include <memory>

class FontManager
{
public:
	explicit FontManager() {}
	void setPath(const std::string& path);
	void addFont(const std::string& font_file);
	std::shared_ptr<Font> getFont(int index);

private:
	std::vector<std::shared_ptr<Font>> m_fonts;
	std::string m_path;
};

