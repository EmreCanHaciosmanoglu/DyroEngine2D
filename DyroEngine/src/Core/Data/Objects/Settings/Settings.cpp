#include "Core/Data/Objects/Settings/Settings.h"

#ifndef _WINDOWS_
#include <Windows.h>
#endif

#ifndef _FSTREAM_H
#include "Core/Defines/fstream.h"
#endif

#include "Core/Helpers/Patterns/Singleton.h"
#include "Core\Diagnostics\Logger.h"

#include "Core/Types/SettingsType.h"

Settings::Settings(const std::tstring& filePath, SettingsType type)
	:file_path(filePath)
	,settings_type(type)
{
}
Settings::~Settings()
{
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
		int value = GetLastError();
		Singleton<Logger>::getInstance().log(_T("Could not open file: ") + filePath, LOGTYPE_ERROR);

		return false;
	}

	return true;
}