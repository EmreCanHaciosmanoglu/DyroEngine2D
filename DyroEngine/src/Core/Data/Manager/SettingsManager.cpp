#include "Core/Data/Manager/SettingsManager.h"
#include "Core/Types/SettingsType.h"

#include "Core/Defines/deletemacros.h"

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

	bool result = true;
	for (Settings* setting : settings)
	{
		//if (!setting->shutdown())
		//	result = false;

		SafeDelete(setting);
	}

	return result;
}

bool SettingsManager::addSettings(SettingsType type)
{
	return addObject((unsigned int)type, this->factory.createSettings(type));
}

void SettingsManager::getSettings(std::vector<Settings*>& settings)
{
	getObjects(settings);
}