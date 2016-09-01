#include "Core/Settings/GameSettings.h"

GameSettings::GameSettings()
	:Settings()
	,default_scene_name(_T(""))
{
}
GameSettings::~GameSettings()
{
}

void GameSettings::initialize(const std::tstring& filePath)
{
	Settings::initialize(filePath);
}

void GameSettings::setDefaultSceneName(const std::tstring& name)
{
	this->default_scene_name = name;
}
const std::tstring& GameSettings::getDefaultSceneName() const
{
	return this->default_scene_name;
}

void GameSettings::parseSettingsFile(const std::tstring& valueName, const std::tstring& valueData)
{
	if (valueName == _T("STARTSCENE"))
		setDefaultSceneName(valueData);
}