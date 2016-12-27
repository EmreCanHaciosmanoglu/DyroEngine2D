#ifndef _PHYXSETTINGS_H
#define _PHYXSETTINGS_H

#include "Settings.h"

#ifndef _STRING_H
#include "Defines/string.h"
#endif
#ifndef _VECTOR2D_H
#include "Helpers\Math\Vector2D.h"
#endif

class PhyxSettings : public Settings
{
public:
	PhyxSettings();
	virtual ~PhyxSettings();

	void setGravity(float gravity);
	const Vector2D& getGravity();

	void setVelocityInterpolation(int interpolation);
	int getVelocityInterpolation() const;
	void setPositionInterpolation(int interpolation);
	int getPositionInterpolation() const;

	void setPhyxTimeStep(float step);
	float getPhyxTimeStep() const;

protected:
	virtual void parseSettingsFile(const std::tstring& valueName, const std::tstring& valueData);

private:

	Vector2D gravity;

	int velocity_interpolation;
	int position_interpolation;

	float phyx_time_step;
};

#endif // _PHYSXSETTINGS_H
