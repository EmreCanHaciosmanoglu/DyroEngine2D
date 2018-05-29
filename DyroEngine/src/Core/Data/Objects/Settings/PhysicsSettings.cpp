#include "Core/Data/Objects/Settings/PhysicsSettings.h"

#include "Core/Types/SettingsType.h"

PhysicsSettings::PhysicsSettings(const std::tstring& filePath)
	:Settings(filePath, SettingsType::PHYSICS_SETTINGS)
	, gravity(0.0f, 9.81f)
	, velocity_interpolation(8)
	, position_interpolation(3)
	, phyx_time_step(1.0f / 60.0f)
{
}
PhysicsSettings::~PhysicsSettings()
{
}

PhysicsSettings& PhysicsSettings::operator=(const PhysicsSettings& ref)
{
	this->gravity = ref.gravity;
	this->velocity_interpolation = ref.velocity_interpolation;
	this->position_interpolation = ref.position_interpolation;
	this->phyx_time_step = ref.phyx_time_step;

	return (*this);
}

void PhysicsSettings::setGravity(const Vector2D& gravity)
{
	this->gravity = gravity;
}
const Vector2D& PhysicsSettings::getGravity()
{
	return this->gravity;
}

void PhysicsSettings::setVelocityInterpolation(int interpolation)
{
	this->velocity_interpolation = interpolation;
}
int PhysicsSettings::getVelocityInterpolation() const
{
	return this->velocity_interpolation;
}
void PhysicsSettings::setPositionInterpolation(int interpolation)
{
	this->position_interpolation = interpolation;
}
int PhysicsSettings::getPositionInterpolation() const
{
	return this->position_interpolation;
}

void PhysicsSettings::setPhyxTimeStep(float step)
{
	this->phyx_time_step = step;
}
float PhysicsSettings::getPhyxTimeStep() const
{
	return this->phyx_time_step;
}

void PhysicsSettings::parseSettingsFile(const std::tstring& valueName, const std::tstring& valueData)
{
	if (valueName == _T("GRAVITY"))
		setGravity(Vector2D(0,(float)_tstof(valueData.c_str())));
	else if (valueName == _T("VELOCITYITERATION"))
		setVelocityInterpolation(_tstoi(valueData.c_str()));
	else if (valueName == _T("POSITIONITERATION"))
		setPositionInterpolation(_tstoi(valueData.c_str()));
	else if (valueName == _T("PHYXTIMESTEP"))
		setPhyxTimeStep((float)_tstof(valueData.c_str()));
}