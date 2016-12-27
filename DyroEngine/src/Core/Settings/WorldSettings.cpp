#include "Core/Settings/WorldSettings.h"

WorldSettings::WorldSettings()
	:application_settings()
	, phyx_settings()
	, game_settings()
{
}
WorldSettings::~WorldSettings()
{
}

bool WorldSettings::loadSetttings()
{
	application_settings.loadSettings(_T("resources/INI/Engine.ini"));
	phyx_settings.loadSettings(_T("resources/INI/Engine.ini"));
	game_settings.loadSettings(_T("resources/INI/Engine.ini"));

	return true;
}

void WorldSettings::setApplicationSettings(const ApplicationSettings& settings)
{
	this->application_settings = settings;
}
ApplicationSettings* WorldSettings::getApplicationSettings()
{
	return &this->application_settings;
}
void WorldSettings::setPhyxSettings(const PhyxSettings& settings)
{
	this->phyx_settings = settings;
}
PhyxSettings* WorldSettings::getPhyxSettings()
{
	return &this->phyx_settings;
}
void WorldSettings::setGameSettings(const GameSettings& settings)
{
	this->game_settings = settings;
}
GameSettings* WorldSettings::getGameSettings()
{
	return &this->game_settings;
}