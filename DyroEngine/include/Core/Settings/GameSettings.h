#ifndef _GAMESETTINGS_H
#define _GAMESETTINGS_H

#include "Settings.h"

#ifndef _STRING_H
	#include "Defines/string.h"
#endif

class GameSettings : public Settings
{
public:
	GameSettings();
	virtual ~GameSettings();

	virtual void initialize(const std::tstring& filePath);

	void setDefaultSceneName(const std::tstring& name);
	const std::tstring& getDefaultSceneName() const;

protected:
	virtual void parseSettingsFile(const std::tstring& valueName, const std::tstring& valueData);

private:

	std::tstring default_scene_name;
};

#endif // _GAMESETTINGS_H
