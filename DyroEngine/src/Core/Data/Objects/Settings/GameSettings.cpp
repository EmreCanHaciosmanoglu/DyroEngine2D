#include "Core/Data/Objects/Settings/GameSettings.h"

#include "Core/Types/SettingsType.h"

GameSettings::GameSettings(const std::tstring& filePath)
	:Settings(filePath, SettingsType::GAME_SETTINGS)
	, default_scene_name(_T(""))
	, background_color(Color(0.0f, 1.0f, 1.0f))
{
}
GameSettings::~GameSettings()
{
}

void GameSettings::setDefaultSceneName(const std::tstring& name)
{
	this->default_scene_name = name;
}
const std::tstring& GameSettings::getDefaultSceneName() const
{
	return this->default_scene_name;
}
void GameSettings::setBackgroundColor(const Color& color)
{
	this->background_color = color;
}
const Color& GameSettings::getBackgroundColor()
{
	return this->background_color;
}

void GameSettings::parseSettingsFile(const std::tstring& valueName, const std::tstring& valueData)
{
	if (valueName == _T("STARTSCENE"))
		setDefaultSceneName(valueData);
	else if (valueName == _T("BACKGROUNDCOLOR"))
	{
	}
}