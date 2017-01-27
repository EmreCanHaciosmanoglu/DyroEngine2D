#ifndef _SETTINGSMANAGER_H
#define _SETTINGSMANAGER_H

#include "Core/Helpers/Patterns/Manager.h"
#include "Core/Helpers/Patterns/Singleton.h"

#include "Core/Data//Objects/Settings/Settings.h"

enum class SettingsType;

class SettingsManager : public Manager<Settings>, public Singleton<SettingsManager>
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