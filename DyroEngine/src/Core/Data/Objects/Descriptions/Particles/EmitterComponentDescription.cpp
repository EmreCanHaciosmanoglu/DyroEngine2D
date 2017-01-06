#include "Core/Data/Objects/Descriptions/Particles/EmitterComponentDescription.h"

EmitterComponentDescription::EmitterComponentDescription(unsigned int particleAmount)
	:particle_amount(particleAmount)

	,gravity_multiplier(0.0f)
	
	,min_life_time(10.0f)
	,max_life_time(10.0f)

	,min_velocity(Vector2D(10.0f,10.0f))
	,max_velocity(Vector2D(10.0f,10.0f))
	,min_angular_velocity(10.0f)
	,max_angular_velocity(10.0f)
	
	,min_scale(Vector2D(1.0f,1.0f))
	,max_scale(Vector2D(1.0f,1.0f))
	,min_grow_speed(0.0f)
	,max_grow_speed(0.0f)

	,fade(false)

	,fade_start(0.0f)
	,fade_end(1.0f)

	,min_fade_speed(1.0f)
	,max_fade_speed(1.0f)

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

void EmitterComponentDescription::setMinLifeTime(float time)
{
	this->min_life_time = time;
	setDirty(true);
}
void EmitterComponentDescription::setMaxLifetime(float time)
{
	this->max_life_time = time;
	setDirty(true);
}

void EmitterComponentDescription::setMinVelocity(const Vector2D& velocity)
{
	this->min_velocity = velocity;
	setDirty(true);
}
void EmitterComponentDescription::setMaxVelocity(const Vector2D& velocity)
{
	this->max_velocity = velocity;
	setDirty(true);
}
void EmitterComponentDescription::setMinAngularVelocity(float velocity)
{
	this->min_angular_velocity = velocity;
	setDirty(true);
}
void EmitterComponentDescription::setMaxAngularVelocity(float velocity)
{
	this->max_angular_velocity = velocity;
	setDirty(true);
}

void EmitterComponentDescription::setMinScale(const Vector2D& scale)
{
	this->min_scale = scale;
	setDirty(true);
}
void EmitterComponentDescription::setMaxScale(const Vector2D& scale)
{
	this->max_scale = scale;
	setDirty(true);
}
void EmitterComponentDescription::setMinGrowSpeed(float speed)
{
	this->min_grow_speed = speed;
	setDirty(true);
}
void EmitterComponentDescription::setMaxGrowSpeed(float speed)
{
	this->max_grow_speed = speed;
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

void EmitterComponentDescription::setMinFadeSpeed(float speed)
{
	this->min_fade_speed = speed;
	setDirty(true);
}
void EmitterComponentDescription::setMaxFadeSpeed(float speed)
{
	this->max_fade_speed = speed;
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

float EmitterComponentDescription::getMinLifeTime() const
{
	return this->min_life_time;
}
float EmitterComponentDescription::getMaxLifetime() const
{
	return this->max_life_time;
}

const Vector2D& EmitterComponentDescription::getMinVelocity() const
{
	return this->min_velocity;
}
const Vector2D& EmitterComponentDescription::getMaxVelocity() const
{
	return this->max_velocity;
}
float EmitterComponentDescription::getMinAngularVelocity() const
{
	return this->min_angular_velocity;
}
float EmitterComponentDescription::getMaxAngularVelocity() const
{
	return this->max_angular_velocity;
}

const Vector2D& EmitterComponentDescription::getMinScale() const
{
	return this->min_scale;
}
const Vector2D& EmitterComponentDescription::getMaxScale() const
{
	return this->max_scale;
}
float EmitterComponentDescription::getMinGrowSpeed() const
{
	return this->min_grow_speed;
}
float EmitterComponentDescription::getMaxGrowSpeed() const
{
	return this->max_grow_speed;
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

float EmitterComponentDescription::getMinFadeSpeed() const
{
	return this->min_fade_speed;
}
float EmitterComponentDescription::getMaxFadeSpeed() const
{
	return this->max_fade_speed;
}

const std::vector<Texture*>& EmitterComponentDescription::getTextures() const
{
	return this->textures;
}