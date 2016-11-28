#ifndef _WORLDSETTINGS_H
#define _WORLDSETTINGS_H

#include "Helpers/Manager.h"

#include "ApplicationSettings.h"
#include "PhyxSettings.h"
#include "GameSettings.h"

class WorldSettings : public Manager
{
public:
	WorldSettings();
	virtual ~WorldSettings();
	
	virtual bool initialize();
	virtual bool shutdown();

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
