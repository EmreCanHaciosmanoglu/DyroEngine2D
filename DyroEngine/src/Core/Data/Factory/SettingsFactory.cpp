#include "Core/Data/Factory/SettingsFactory.h"

#include "Core/Data/Objects/Settings/ApplicationSettings.h"
#include "Core/Data/Objects/Settings/GameSettings.h"
#include "Core/Data/Objects/Settings/PhysicsSettings.h"

#include "Core/Types/SettingsType.h"

SettingsFactory::SettingsFactory()
{}
SettingsFactory::~SettingsFactory()
{}

Settings* SettingsFactory::createSettings(const std::tstring& filePath, SettingsType type)
{
	switch (type)
	{
	case SettingsType::APPLICATION_SETTINGS:
		return new ApplicationSettings(filePath);
		break;
	case SettingsType::GAME_SETTINGS:
		return new GameSettings(filePath);
		break;
	case SettingsType::PHYSICS_SETTINGS:
		return new PhysicsSettings(filePath);
		break;
	}

	return nullptr;
}