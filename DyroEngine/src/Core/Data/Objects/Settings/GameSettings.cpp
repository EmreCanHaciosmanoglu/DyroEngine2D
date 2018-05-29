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

GameSettings& GameSettings::operator=(const GameSettings& ref)
{
	this->default_scene_name = ref.default_scene_name;
	this->background_color = ref.background_color;

	Settings::operator=(ref);

	return (*this);
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