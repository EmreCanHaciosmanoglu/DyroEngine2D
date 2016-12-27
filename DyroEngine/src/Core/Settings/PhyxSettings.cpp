#include "Core/Settings/PhyxSettings.h"

PhyxSettings::PhyxSettings()
	:Settings()
	, gravity(0.0f, 9.81f)
	, velocity_interpolation(8)
	, position_interpolation(3)
	, phyx_time_step(1.0f / 60.0f)
{
}
PhyxSettings::~PhyxSettings()
{
}

void PhyxSettings::setGravity(float gravity)
{
	this->gravity = Vector2D(0.0f, gravity);
}
const Vector2D& PhyxSettings::getGravity()
{
	return this->gravity;
}

void PhyxSettings::setVelocityInterpolation(int interpolation)
{
	this->velocity_interpolation = interpolation;
}
int PhyxSettings::getVelocityInterpolation() const
{
	return this->velocity_interpolation;
}
void PhyxSettings::setPositionInterpolation(int interpolation)
{
	this->position_interpolation = interpolation;
}
int PhyxSettings::getPositionInterpolation() const
{
	return this->position_interpolation;
}

void PhyxSettings::setPhyxTimeStep(float step)
{
	this->phyx_time_step = step;
}
float PhyxSettings::getPhyxTimeStep() const
{
	return this->phyx_time_step;
}

void PhyxSettings::parseSettingsFile(const std::tstring& valueName, const std::tstring& valueData)
{
	if (valueName == _T("GRAVITY"))
		setGravity((float)_tstof(valueData.c_str()));
	else if (valueName == _T("VELOCITYITERATION"))
		setVelocityInterpolation(_tstoi(valueData.c_str()));
	else if (valueName == _T("POSITIONITERATION"))
		setPositionInterpolation(_tstoi(valueData.c_str()));
	else if (valueName == _T("PHYXTIMESTEP"))
		setPhyxTimeStep((float)_tstof(valueData.c_str()));
}