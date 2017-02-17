#include "Core/Data/Factory/SettingsFactory.h"

#include "Core/Data/Objects/Settings/ApplicationSettings.h"
#include "Core/Data/Objects/Settings/GameSettings.h"
#include "Core/Data/Objects/Settings/PhysicsSettings.h"

#include "Core/Types/SettingsType.h"

namespace
{
	const std::tstring APPLICATION_SETTINGS_PATH = _T("resources/INI/Engine.ini");
	const std::tstring GAME_SETTINGS_PATH = _T("resources/INI/Engine.ini");
	const std::tstring PHYSICS_SETTINGS_PATH = _T("resources/INI/Engine.ini");
}

SettingsFactory::SettingsFactory()
{}
SettingsFactory::~SettingsFactory()
{}

Settings* SettingsFactory::createSettings(SettingsType type)
{
	switch (type)
	{
	case SettingsType::APPLICATION_SETTINGS:
		return new ApplicationSettings(APPLICATION_SETTINGS_PATH);
		break;
	case SettingsType::GAME_SETTINGS:
		return new GameSettings(GAME_SETTINGS_PATH);
		break;
	case SettingsType::PHYSICS_SETTINGS:
		return new PhysicsSettings(PHYSICS_SETTINGS_PATH);
		break;
	}

	return nullptr;
}