#ifndef _APPLICATIONSETTINGS_H
#define _APPLICATIONSETTINGS_H

#include "Settings.h"

#ifndef _STRING_H
#include "Core/Defines/string.h"
#endif

class ApplicationSettings : public Settings
{
public:
	ApplicationSettings(const std::tstring& filePath);
	virtual ~ApplicationSettings();

	ApplicationSettings& operator=(const ApplicationSettings& ref);

	void setWindowWidth(int width);
	int getWindowWidth() const;
	void setWindowHeight(int height);
	int getWindowHeight() const;
	void setBitsPerPixel(unsigned char bits);
	unsigned char getBitsPerPixel() const;
	void setFullscreen(int fullscreen);
	bool getFullscreen() const;

	void setWindowTitle(const std::tstring& title);
	const std::tstring& getWindowTitle() const;
	void setContentRootPath(const std::tstring& path);
	const std::tstring& getContentRootPath() const;

protected:
	virtual void parseSettingsFile(const std::tstring& valueName, const std::tstring& valueData);

private:

	int window_width;
	int window_height;
	unsigned char window_bits_per_pixel;

	bool fullscreen;

	std::tstring window_title;
	std::tstring content_root_path;
};

#endif // _APPLICATIONSETTING_H