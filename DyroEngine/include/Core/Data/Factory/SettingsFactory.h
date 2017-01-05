#ifndef _SETTINGSFACTORY_H
#define _SETTINGSFACTORY_H

#ifndef _STRING_H
#include "Core/Defines/string.h"
#endif

class Settings;
enum class SettingsType;

class SettingsFactory
{
public:
	SettingsFactory();
	~SettingsFactory();

	Settings* createSettings(const std::tstring& filePath, SettingsType type);
};

#endif