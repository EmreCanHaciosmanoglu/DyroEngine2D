#ifndef _SETTINGSDATA_H
#define _SETTINGSDATA_H

class ApplicationSettings;
class GameSettings;
class PhysicsSettings;

struct SettingsData
{
	SettingsData(ApplicationSettings* appSettings, GameSettings* gameSettings, PhysicsSettings* pSettings)
		:app_settings(appSettings)
		, game_settings(gameSettings)
		, physics_settings(pSettings)
	{}

	ApplicationSettings* app_settings;
	GameSettings* game_settings;
	PhysicsSettings* physics_settings;
};

#endif