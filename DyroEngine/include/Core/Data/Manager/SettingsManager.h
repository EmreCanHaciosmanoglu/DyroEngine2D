#ifndef _SETTINGSMANAGER_H
#define _SETTINGSMANAGER_H

#include "Core/Helpers/Patterns/Manager.h"

class Settings;
enum class SettingsType;

class SettingsManager : public Manager<Settings>
{
public:
	SettingsManager();
	virtual ~SettingsManager();

	bool initialize();
	bool shutdown();

	void addSettings(Settings* setting);
	
	Settings* getSettings(SettingsType type);
};

#endif