#include "Core/Settings/GameSettings.h"

GameSettings::GameSettings()
	:Settings()
	, default_scene_name(_T(""))
	, background_color(Color(0.0f, 1.0f, 1.0f))
{
}
GameSettings::~GameSettings()
{
}

void GameSettings::initialize(const std::tstring& filePath)
{
	Settings::loadSettings(filePath);
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