#ifndef _SETTINGS_H
#define _SETTINGS_H

#ifndef _STRING_H
#include "Core/Defines/string.h"
#endif

enum class SettingsType;

class Settings
{
public:
	Settings(const std::tstring& filePath, SettingsType type);
	virtual ~Settings();

	virtual bool loadSettings();
	SettingsType getSettingsType() const;

protected:

	virtual void parseSettingsFile(const std::tstring& valueName, const std::tstring& valueData) = 0;

private:
	bool loadFile(const std::tstring& filePath);

	const std::tstring file_path;
	SettingsType settings_type;
};

#endif
