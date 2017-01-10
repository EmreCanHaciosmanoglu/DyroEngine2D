#include "Core/Data/Objects/Descriptions/Particles/ParticleDescription.h"

ParticleDescription::ParticleDescription()
	: gravity_multiplier(0.0f)
	, life_time(10.0f)

	, velocity(Vector2D(10.0f, 10.0f))
	, scale_velocity(Vector2D(0.0f, 0.0f))
	, angular_velocity(10.0f)

	, position(Vector2D(0.0f,0.0f))
	, scale(Vector2D(1.0f, 1.0f))
	, rotation(0.0f)

	, fade(false)
	, fade_start(0.0f)
	, fade_end(1.0f)
	, fade_speed(1.0f)
{}
ParticleDescription::~ParticleDescription()
{}

void ParticleDescription::destroy()
{
	this->destroyed = true;
}

void ParticleDescription::setGravityMultiplier(float multiplier)
{
	this->gravity_multiplier = multiplier;
}
void ParticleDescription::setLifeTime(float time)
{
	this->life_time = time;
}

void ParticleDescription::setVelocity(const Vector2D& velocity)
{
	this->velocity = velocity;
}
void ParticleDescription::setScaleVelocity(const Vector2D& velocity)
{
	this->scale_velocity = velocity;
}
void ParticleDescription::setAngularVelocity(float velocity)
{
	this->angular_velocity = velocity;
}

void ParticleDescription::setPosition(const Vector2D& position)
{
	this->position = position;
}
void ParticleDescription::setScale(const Vector2D& scale)
{
	this->scale = scale;
}
void ParticleDescription::setRotation(float rotation)
{
	this->rotation = rotation;
}

void ParticleDescription::enableFade(bool fade)
{
	this->fade = fade;
}
void ParticleDescription::setFadeStart(float start)
{
	this->fade_start = start;
}
void ParticleDescription::setFadeEnd(float end)
{
	this->fade_end = end;
}
void ParticleDescription::setFadeSpeed(float speed)
{
	this->fade_speed = speed;
}

void ParticleDescription::setTexture(Texture* texture)
{
	this->texture = texture;
}

bool ParticleDescription::isDestroyed() const
{
	return destroyed;
}

float ParticleDescription::getGravityMultiplier() const
{
	return this->gravity_multiplier;
}
float ParticleDescription::getLifeTime() const
{
	return this->life_time;
}

const Vector2D& ParticleDescription::getVelocity() const
{
	return this->velocity;
}
const Vector2D& ParticleDescription::getScaleVelocity() const
{
	return this->scale_velocity;
}
float ParticleDescription::getAngularVelocity() const
{
	return this->angular_velocity;
}

const Vector2D& ParticleDescription::getPosition() const
{
	return this->position;
}
const Vector2D& ParticleDescription::getScale() const
{
	return this->scale;
}
float ParticleDescription::getRotation() const
{
	return this->rotation;
}

bool ParticleDescription::canFade() const
{
	return this->fade;
}
float ParticleDescription::getFadeStart() const
{
	return this->fade_start;
}
float ParticleDescription::getFadeEnd() const
{
	return this->fade_end;
}
float ParticleDescription::getFadeSpeed() const
{
	return this->fade_speed;
}

Texture* ParticleDescription::getTexture() const
{
	return this->texture;
}