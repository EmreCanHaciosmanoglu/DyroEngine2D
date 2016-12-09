#ifndef _WORLDSETTINGS_H
#define _WORLDSETTINGS_H

#include "ApplicationSettings.h"
#include "PhyxSettings.h"
#include "GameSettings.h"

class WorldSettings
{
public:
	WorldSettings();
	virtual ~WorldSettings();
	
	bool loadSetttings();

	void setApplicationSettings(const ApplicationSettings& settings);
	ApplicationSettings* getApplicationSettings();
	void setPhyxSettings(const PhyxSettings& settings);
	PhyxSettings* getPhyxSettings();
	void setGameSettings(const GameSettings& settings);
	GameSettings* getGameSettings();

private:

	ApplicationSettings application_settings;
	PhyxSettings phyx_settings;
	GameSettings game_settings;
};

#endif //_WORLDSETIINGS_H
