#include "Core/Settings/ApplicationSettings.h"

#ifndef _PROGRAMDEFAULTS_H
	#include "Defines/programdefaults.h"
#endif

ApplicationSettings::ApplicationSettings()
	:Settings()
	,window_width(1280)
	,window_height(720)
	,window_bits_per_pixel(constants::BITS_PER_PIXEL_16)
	,fullscreen(false)
	,window_title(_T(""))
	,content_root_path(_T("./Resources/"))
{
}
ApplicationSettings::~ApplicationSettings()
{
}

void ApplicationSettings::setWindowWidth(int width)
{
	this->window_width = width;
}
int ApplicationSettings::getWindowWidth() const
{
	return this->window_width;
}
void ApplicationSettings::setWindowHeight(int height)
{
	this->window_height = height;
}
int ApplicationSettings::getWindowHeight() const
{
	return this->window_height;
}
void ApplicationSettings::setBitsPerPixel(unsigned char bits)
{
	this->window_bits_per_pixel = bits;
}
unsigned char ApplicationSettings::getBitsPerPixel() const
{
	return this->window_bits_per_pixel;
}

void ApplicationSettings::setFullscreen(int fullscreen)
{
	this->fullscreen = fullscreen == constants::TRUE;
}
bool ApplicationSettings::getFullscreen() const
{
	return this->fullscreen;
}

void ApplicationSettings::setWindowTitle(const std::tstring& title)
{
	this->window_title = title;
}
const std::tstring& ApplicationSettings::getWindowTitle() const
{
	return this->window_title;
}
void ApplicationSettings::setContentRootPath(const std::tstring& path)
{
	this->content_root_path = path;
}
const std::tstring& ApplicationSettings::getContentRootPath() const
{
	return this->content_root_path;
}

void ApplicationSettings::parseSettingsFile(const std::tstring& valueName, const std::tstring& valueData)
{
	if (valueName == _T("WINDOWWIDTH"))
		setWindowWidth(_tstoi(valueData.c_str()));
	else if (valueName == _T("WINDOWHEIGHT"))
		setWindowHeight(_tstoi(valueData.c_str()));
	else if (valueName == _T("BITSPERPIXEL"))
		setBitsPerPixel(_tstoi(valueData.c_str()));
	else if (valueName == _T("FULLSCREEN"))
		setFullscreen(_tstoi(valueData.c_str()));
	else if (valueName == _T("WINDOWTITLE"))
		setWindowTitle(valueData);
	else if (valueName == _T("ROOTPATH"))
		setContentRootPath(valueData);
}