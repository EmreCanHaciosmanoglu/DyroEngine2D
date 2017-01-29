#include "Core/Data/Objects/Descriptions/Particles/EmitterComponentDescription.h"

#ifndef _RANDOM_H
#include "Math/Objects/Random.h"
#endif

EmitterComponentDescription::EmitterComponentDescription(unsigned int particleAmount)
	:particle_amount(particleAmount)
	,emission_burst(5)
	,emission_rate(1.0f)
	,gravity_multiplier(0.0f)
	,life_time(10.0f, 10.0f)
	,loop(true)
	,spawn_at_start(true)

	,velocity(Vector2D(-50.0f, -50.0f), Vector2D(50.0f,50.0f))
	,scale_velocity(Vector2D(0.0f, 0.0f), Vector2D(0.0f, 0.0f))
	,angular_velocity(0.0f, 0.0f)

	,fade(true)
	,fade_start(0.1f)
	,fade_end(0.95f)
	,fade_speed(1.0f, 1.0f)

	,spawn_position_offset(Vector2D(-10.0f, -10.0f), Vector2D(10.0f, 10.0f))
	,spawn_scale_offset(Vector2D(0.0f, 0.0f), Vector2D(0.0f, 0.0f))
	,spawn_rotation_offset(0,0)

	,dirty(false)
{}
EmitterComponentDescription::~EmitterComponentDescription()
{}

void EmitterComponentDescription::setDirty(bool dirty)
{
	this->dirty = dirty;
}
bool EmitterComponentDescription::getDirty() const
{
	return this->dirty;
}

void EmitterComponentDescription::setParticleAmount(unsigned int amount)
{
	this->particle_amount = amount;
	setDirty(true);
}
void EmitterComponentDescription::setEmissionBurst(unsigned int burst)
{
	this->emission_burst = burst;
	setDirty(true);
}
void EmitterComponentDescription::setEmissionRate(float rate)
{
	this->emission_rate = rate;
	setDirty(true);
}
void EmitterComponentDescription::setGravityMultiplier(float multiplier)
{
	this->gravity_multiplier = multiplier;
	setDirty(true);
}
void EmitterComponentDescription::setLifeTime(const RangeFloat& time)
{
	this->life_time = time;
	setDirty(true);
}
void EmitterComponentDescription::setLoop(bool loop)
{
	this->loop = loop;
	setDirty(true);
}
void EmitterComponentDescription::setSpawnAtStart(bool spawn)
{
	this->spawn_at_start = spawn;
	setDirty(true);
}

void EmitterComponentDescription::setVelocity(const RangeVector2D& velocity)
{
	this->velocity = velocity;
	setDirty(true);
}
void EmitterComponentDescription::setScaleVelocity(const RangeVector2D& velocity)
{
	this->scale_velocity = velocity;
	setDirty(true);
}
void EmitterComponentDescription::setAngularVelocity(const RangeFloat& velocity)
{
	this->angular_velocity = velocity;
	setDirty(true);
}

void EmitterComponentDescription::enableFade(bool fade)
{
	this->fade = fade;
	setDirty(true);
}
void EmitterComponentDescription::setFadeStart(float start)
{
	this->fade_start = start;
	setDirty(true);
}
void EmitterComponentDescription::setFadeEnd(float end)
{
	this->fade_end = end;
	setDirty(true);
}
void EmitterComponentDescription::setFadeSpeed(const RangeFloat& speed)
{
	this->fade_speed = speed;
	setDirty(true);
}

void EmitterComponentDescription::setSpawnPositionOffset(const RangeVector2D& offset)
{
	this->spawn_position_offset = offset;
	setDirty(true);
}
void EmitterComponentDescription::setSpawnScaleOffset(const RangeVector2D& offset)
{
	this->spawn_scale_offset = offset;
	setDirty(true);
}
void EmitterComponentDescription::setSpawnRotationOffset(const RangeFloat& offset)
{
	this->spawn_rotation_offset = offset;
	setDirty(true);
}

void EmitterComponentDescription::addImage(Image* image)
{
	std::vector<Image*>::const_iterator it = std::find(this->images.begin(), this->images.end(), image);
	if (it == this->images.end())
		this->images.push_back(image);
	setDirty(true);
}

unsigned int EmitterComponentDescription::getParticleAmount() const
{
	return this->particle_amount;
}
unsigned int EmitterComponentDescription::getEmissionBurst() const
{
	return this->emission_burst;
}
float EmitterComponentDescription::getEmissionRate() const
{
	return this->emission_rate;
}
float EmitterComponentDescription::getGravityMultiplier() const
{
	return this->gravity_multiplier;
}
float EmitterComponentDescription::getLifeTime() const
{
	return RandomFloat::getValue(this->life_time);
}
bool EmitterComponentDescription::canLoop() const
{
	return this->loop;
}
bool EmitterComponentDescription::canSpawnAtStart() const
{
	return this->spawn_at_start;
}

const Vector2D EmitterComponentDescription::getVelocity() const
{
	return Vector2D::randomVector(this->velocity.min_value,this->velocity.max_value);
}
const Vector2D EmitterComponentDescription::getScaleVelocity() const
{
	return Vector2D::randomVector(this->scale_velocity.min_value,this->scale_velocity.max_value);
}
float EmitterComponentDescription::getAngularVelocity() const
{
	return RandomFloat::getValue(this->angular_velocity);
}

bool EmitterComponentDescription::canFade() const
{
	return this->fade;
}
float EmitterComponentDescription::getFadeStart() const
{
	return this->fade_start;
}
float EmitterComponentDescription::getFadeEnd() const
{
	return this->fade_end;
}
float EmitterComponentDescription::getFadeSpeed() const
{
	return RandomFloat::getValue(this->fade_speed);
}

const Vector2D EmitterComponentDescription::getSpawnPositionOffset()
{
	return Vector2D::randomVector(this->spawn_position_offset.min_value, this->spawn_position_offset.max_value);
}
const Vector2D EmitterComponentDescription::getSpawnScaleOffset()
{
	return Vector2D::randomVector(this->spawn_scale_offset.min_value, this->spawn_scale_offset.max_value);
}
float EmitterComponentDescription::getSpawnRotationOffset()
{
	return RandomFloat::getValue(this->spawn_rotation_offset);
}

const std::vector<Image*>& EmitterComponentDescription::getImages() const
{
	return this->images;
}