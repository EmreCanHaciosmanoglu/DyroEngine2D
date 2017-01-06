#ifndef _PARTICLEDESCRIPTION_H
#define _PARTICLEDESCRIPTION_H

#ifndef _VECTOR2D_H
#include "Math/Objects/Vector2D.h"
#endif

class Texture;

class ParticleDescription
{
public:
	ParticleDescription();
	~ParticleDescription();

	void setGravityMultiplier(float multiplier);

	void setLifeTime(float time);

	void setVelocity(const Vector2D& velocity);
	void setAngularVelocity(float velocity);

	void setScale(const Vector2D& scale);
	void setGrowSpeed(float speed);

	void enableFade(bool fade);

	void setFadeStart(float start);
	void setFadeEnd(float end);

	void setFadeSpeed(float speed);

	void setTexture(Texture* texture);

	float getGravityMultiplier() const;

	float getLifeTime() const;

	const Vector2D& getVelocity() const;
	float getAngularVelocity(const Vector2D& velocity) const;

	const Vector2D& getScale() const;
	float getGrowSpeed() const;

	bool canFade() const;

	float getFadeStart() const;
	float getFadeEnd() const;

	float getFadeSpeed() const;

	Texture* getTexture() const;

private:
	float gravity_multiplier;

	float life_time;

	Vector2D velocity;
	float angular_velocity;

	Vector2D scale;
	float grow_speed;

	bool fade;

	float fade_start;
	float fade_end;

	float fade_speed;

	Texture* texture;
};

#endif
