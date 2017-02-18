#ifndef _FONTMANAGER_H
#define _FONTMANAGER_H

#include "Core/Helpers/Patterns/Singleton.h"
#include "Core/Helpers/Patterns/Manager.h"

#include "Core/Data/Objects/Font.h"

class FontManager : public Manager<Font>, public Singleton<FontManager>
{
public:
	FontManager();
	virtual ~FontManager();

	virtual bool initialize();
	virtual bool shutdown();

	void addFont(Font* font);

	Font* getFont(unsigned int id);
	Font* getFont(const std::tstring& name);

private:
};

#endif