#ifndef _GAMESETTINGS_H
#define _GAMESETTINGS_H

#include "Settings.h"

#ifndef _STRING_H
#include "Core/Defines/string.h"
#endif
#ifndef _COLOR_H
#include "Core\Defines\color.h"
#endif

class GameSettings : public Settings
{
public:
	GameSettings(const std::tstring& filePath);
	virtual ~GameSettings();

	void setDefaultSceneName(const std::tstring& name);
	const std::tstring& getDefaultSceneName() const;
	void setBackgroundColor(const Color& color);
	const Color& getBackgroundColor();

protected:
	virtual void parseSettingsFile(const std::tstring& valueName, const std::tstring& valueData);

private:

	std::tstring default_scene_name;
	Color background_color;
};

#endif // _GAMESETTINGS_H
