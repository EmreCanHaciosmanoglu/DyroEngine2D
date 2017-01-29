#include "Core/Data/Objects/Descriptions/Particles/ParticleDescription.h"
#include "Core/Data/Objects/Timers/WorldTimer.h"

namespace
{
	const float INVALID_START_LIFE_TIME = -1.0f;
}

ParticleDescription::ParticleDescription()
	: gravity_multiplier(0.0f)
	, life_time(10.0f)
	, start_life_time(INVALID_START_LIFE_TIME)

	, velocity(Vector2D(10.0f, 10.0f))
	, scale_velocity(Vector2D(0.0f, 0.0f))
	, angular_velocity(10.0f)

	, position(Vector2D(0.0f,0.0f))
	, scale(Vector2D(1.0f, 1.0f))
	, rotation(0.0f)

	, fade(false)
	, fade_start(0.0f)
	, fade_end(1.0f)
	, fade_transition(fade_start, fade_end)
{}
ParticleDescription::ParticleDescription(const ParticleDescription& description)
	:gravity_multiplier(description.getGravityMultiplier())
	, life_time(description.getLifeTime())
	, start_life_time(description.getInitialLifeTime())

	, velocity(description.getVelocity())
	, scale_velocity(description.getScaleVelocity())
	, angular_velocity(description.getAngularVelocity())

	, position(description.getPosition())
	, scale(description.getScale())
	, rotation(description.getRotation())

	, fade(description.canFade())
	, fade_start(description.getFadeStart())
	, fade_end(description.getFadeEnd())

	, fade_transition(description.fade_transition)
	, image(description.image)
{

}
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
	if (this->start_life_time == INVALID_START_LIFE_TIME)
		this->start_life_time = life_time;
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
	this->fade_start = b2Clamp<float>(this->fade_start, 0, this->life_time);
	if (this->fade_start > this->fade_end)
		this->fade_start = this->fade_end;

	this->fade_transition.setSource(this->fade_start);
}
void ParticleDescription::setFadeEnd(float end)
{
	this->fade_end = end;
	this->fade_end = b2Clamp<float>(this->fade_end, 0, this->life_time);
	if (this->fade_end < this->fade_start)
		this->fade_end = this->fade_start;

	this->fade_transition.setDestination(this->fade_end);
}

void ParticleDescription::setImage(Image* image)
{
	this->image = image;
}

bool ParticleDescription::isDestroyed() const
{
	return destroyed;
}

float ParticleDescription::getGravityMultiplier() const
{
	return this->gravity_multiplier;
}
float ParticleDescription::getInitialLifeTime() const
{
	return this->start_life_time;
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
float ParticleDescription::getFadeAmount()
{
	//If we don't need to start fading yet just return the default opacity
	float normalized_lifetime = getLifeTime() / getInitialLifeTime();
	if (this->fade_start > 1.0f - normalized_lifetime)
		return 1.0f;

	//If fading is finished we just return 0
	if (this->fade_transition.isFinished())
		return 0.0f;

	if (!this->fade_transition.isRunning())
	{
		float fade_distance = this->fade_end - this->fade_start;
		if (fade_distance <= 0.0f)
			return 0.0f;

		this->fade_transition.setSpeed((1.0f / fade_distance) * WorldTimer::getWorldDeltaTime());
		this->fade_transition.start();
	}
	else this->fade_transition.update();

	return 1.0f - this->fade_transition.getValue();
}

Image* ParticleDescription::getImage() const
{
	return this->image;
}