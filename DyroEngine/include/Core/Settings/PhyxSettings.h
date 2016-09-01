#ifndef _PHYXSETTINGS_H
#define _PHYXSETTINGS_H

#include "Settings.h"

#ifndef _STRING_H
	#include "Defines/string.h"
#endif

class PhyxSettings : public Settings
{
public:
	PhyxSettings();
	virtual ~PhyxSettings();

	void setGravity(float gravity);
	float getGravity();

	void setVelocityInterpolation(int interpolation);
	int getVelocityInterpolation() const;
	void setPositionInterpolation(int interpolation);
	int getPositionInterpolation() const;

protected:
	virtual void parseSettingsFile(const std::tstring& valueName, const std::tstring& valueData);

private:

	float gravity;
	
	int velocity_interpolation;
	int position_interpolation;
};

#endif // _PHYSXSETTINGS_H
