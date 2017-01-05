#ifndef _EMITTERCOMPONENTDESCRIPTION_H
#define _EMITTERCOMPONENTDESCRIPTION_H

#ifndef _VECTOR2D_H
#include "Math/Objects/Vector2D.h"
#endif
#ifndef _VECTOR_
#include <vector>
#endif

class Texture;

class EmitterComponentDescription
{
public:
	EmitterComponentDescription(unsigned int particleAmount);
	~EmitterComponentDescription();

	void setParticleAmount(unsigned int amount);

	void setGravityMultiplier(float multiplier);

	void setMinLifeTime(float time);
	void setMaxLifetime(float time);
	
	void setMinVelocity(const Vector2D& velocity);
	void setMaxVelocity(const Vector2D& velocity);
	void setMinAngularVelocity(float velocity);
	void setMaxAngularVelocity(float velocity);
	
	void setMinScale(const Vector2D& scale);
	void setMaxScale(const Vector2D& scale);
	void setMinGrowSpeed(float speed);
	void setMaxGrowSpeed(float speed);

	void enableFade(bool fade);

	void setFadeStart(float start);
	void setFadeEnd(float end);

	void setMinFadeSpeed(float speed);
	void setMaxFadeSpeed(float speed);

	void addTexture(Texture* texture);

	unsigned int getParticleAmount() const;

	float getGravityMultiplier() const;

	float getMinLifeTime() const;
	float getMaxLifetime() const;

	const Vector2D& getMinVelocity() const;
	const Vector2D& getMaxVelocity() const;
	float getMinAngularVelocity(const Vector2D& velocity) const;
	float getMaxAngularVelocity() const;

	const Vector2D& getMinScale() const;
	const Vector2D& getMaxScale() const;
	float getMinGrowSpeed() const;
	float getMaxGrowSpeed() const;

	bool canFade() const;

	float getFadeStart() const;
	float getFadeEnd() const;

	float getMinFadeSpeed() const;
	float getMaxFadeSpeed() const;

	const std::vector<Texture*>& getTextures() const;

private:
	unsigned int particle_amount;

	float gravity_multiplier;

	float min_life_time;
	float max_life_time;

	Vector2D min_velocity;
	Vector2D max_velocity;
	float min_angular_velocity;
	float max_angular_velocity;

	Vector2D min_scale;
	Vector2D max_scale;
	float min_grow_speed;
	float max_grow_speed;

	bool fade;

	float fade_start;
	float fade_end;

	float min_fade_speed;
	float max_fade_speed;

	std::vector<Texture*> textures;
};

#endif
