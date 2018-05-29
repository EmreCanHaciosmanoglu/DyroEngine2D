#include "Core/Data/Objects/Settings/Settings.h"

#ifndef _WINDOWS_
#include <Windows.h>
#endif

#include "Core/Defines/fstream.h"
#include "Core\Defines\debug.h"

#include "Core/Types/SettingsType.h"

Settings::Settings(const std::tstring& filePath, SettingsType type)
	:file_path(filePath)
	, settings_type(type)
{
}
Settings::~Settings()
{
}

Settings& Settings::operator=(const Settings& ref)
{
	this->file_path = ref.file_path;
	this->settings_type = ref.settings_type;

	return (*this);
}

bool Settings::loadSettings()
{
	return loadFile(this->file_path);
}
SettingsType Settings::getSettingsType() const
{
	return this->settings_type;
}

bool Settings::loadFile(const std::tstring& filePath)
{
	std::tifstream file;
	file.open(filePath, std::ios::in);

	std::tstring line;
	if (file.is_open())
	{
		while (std::getline(file, line))
		{
			//The description of the data
			std::tstring value_name = line.substr(0, line.find_first_of(':'));
			//Store the data that we need
			std::tstring value_data = line.substr(line.find_first_of(':') + 1);

			parseSettingsFile(value_name, value_data);
		}
		file.close();
	}
	else
	{
		LogManager::getInstance().log(new InfoLog(_T("Could not open file: ") + filePath, LOG_DATA));

		return false;
	}

	return true;
}