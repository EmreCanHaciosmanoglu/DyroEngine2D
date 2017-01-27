#include "Core/Data/Manager/SettingsManager.h"

#include "Core/Types/SettingsType.h"

SettingsManager::SettingsManager()
{}
SettingsManager::~SettingsManager()
{}

bool SettingsManager::initialize()
{
	std::vector<Settings*> settings;
	getObjects(settings);

	for (Settings* setting : settings)
	{
		if (!setting->loadSettings())
			return false;
	}

	return true;
}
bool SettingsManager::shutdown()
{
	std::vector<Settings*> settings;
	getObjects(settings);

	for (Settings* setting : settings)
		delete setting;

	return true;
}

void SettingsManager::addSettings(Settings* setting)
{
	addObject((unsigned int)setting->getSettingsType(), setting);
}

Settings* SettingsManager::getSettings(SettingsType type)
{
	return getObject((unsigned int)type);
}