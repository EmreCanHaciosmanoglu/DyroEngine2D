#ifndef _SETTINGSMANAGER_H
#define _SETTINGSMANAGER_H

#include "Core/Helpers/Patterns/Manager.h"
#include "Core/Helpers/Patterns/Singleton.h"

#include "Core/Data/Objects/Settings/Settings.h"
#include "Core/Data/Factory/SettingsFactory.h"

enum class SettingsType;

class SettingsManager : public Manager<Settings>, public Singleton<SettingsManager>
{
public:
	SettingsManager();
	virtual ~SettingsManager();

	bool initialize();
	bool shutdown();

	bool addSettings(SettingsType type);

	template <typename T>
	T* getSettings();
	void getSettings(std::vector<Settings*>& settings);

private:
	SettingsFactory factory;
};

template <typename T>
T* SettingsManager::getSettings()
{
	std::vector<Settings*> settings;
	getObjects(settings);

	for (Settings* s : settings)
	{
		T* concrete_setting = dynamic_cast<T*>(s);
		if (concrete_setting != nullptr)
			return concrete_setting;
	}

	return nullptr;
}

#endif