#include "Core/Data/Objects/Descriptions/Particles/EmitterComponentDescription.h"

#ifndef _RANDOM_H
#include "Math/Objects/Random.h"
#endif

EmitterComponentDescription::EmitterComponentDescription(unsigned int particleAmount)
	:particle_amount(particleAmount)
	,gravity_multiplier(0.0f)
	,life_time(10.0f, 10.0f)
	,loop(true)

	,velocity(Vector2D(10.0f, 10.0f), Vector2D(10.0f,10.0f))
	,scale_velocity(Vector2D(0.0f, 0.0f), Vector2D(0.0f, 0.0f))
	,angular_velocity(10.0f, 10.0f)

	,fade(false)
	,fade_start(0.0f)
	,fade_end(1.0f)
	,fade_speed(1.0f, 1.0f)

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

void EmitterComponentDescription::addTexture(Texture* texture)
{
	std::vector<Texture*>::const_iterator it = std::find(this->textures.begin(), this->textures.end(), texture);
	if (it != this->textures.end())
		this->textures.push_back(texture);
	setDirty(true);
}

unsigned int EmitterComponentDescription::getParticleAmount() const
{
	return this->particle_amount;
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

const Vector2D& EmitterComponentDescription::getVelocity() const
{
	return Vector2D::randomVector(this->velocity.min_value,this->velocity.max_value);
}
const Vector2D& EmitterComponentDescription::getScaleVelocity() const
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

const std::vector<Texture*>& EmitterComponentDescription::getTextures() const
{
	return this->textures;
}