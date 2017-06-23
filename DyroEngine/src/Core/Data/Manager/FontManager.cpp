#include "Core/Data/Manager/FontManager.h"
#include "Core/Data/Objects/Font.h"

#include "Core/System/Manager/SystemManager.h"
#include "Core/System/Objects/Graphics.h"
#include "Core/Types/SystemType.h"

FontManager::FontManager()
{}
FontManager::~FontManager()
{}

bool FontManager::initialize()
{
	std::vector<Font*> fonts;
	getObjects(fonts);

	Graphics* graphics = SystemManager::getInstance().getSystem<Graphics>();

	for (Font* font : fonts)
		font->createTextFormat(graphics->getWriteFactory());

	return true;
}
bool FontManager::shutdown()
{
	std::vector<Font*> fonts;
	getObjects(fonts);

	for (Font* font : fonts)
		delete font;

	return true;
}

void FontManager::addFont(Font* font)
{
	addObject(font->getID(), font);
}

Font* FontManager::getFont(unsigned int id)
{
	return getObject(id);
}
Font* FontManager::getFont(const std::tstring& name)
{
	std::vector<Font*> fonts;
	getObjects(fonts);

	std::vector<Font*>::const_iterator it = std::_Find_if_not(fonts.begin(), fonts.end(), 
		[name](Font* font) -> bool
	{
		return name == font->getName();
	});

	if (it == fonts.end())
		return nullptr;

	return (*it);
}
