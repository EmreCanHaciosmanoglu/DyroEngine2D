#ifndef _PARTICLEDESCRIPTION_H
#define _PARTICLEDESCRIPTION_H

#ifndef _IDESTROYABLE_H
#include "Core/Helpers/Interfaces/IDestroyable.h"
#endif

#ifndef _VECTOR2D_H
#include "Math/Objects/Vector2D.h"
#endif

class Texture;

class ParticleDescription : public IDestroyable
{
public:
	ParticleDescription();
	ParticleDescription(const ParticleDescription& description) = default;
	~ParticleDescription();

	void destroy();

	void setGravityMultiplier(float multiplier);
	void setLifeTime(float time);

	void setVelocity(const Vector2D& velocity);
	void setScaleVelocity(const Vector2D& velocity);
	void setAngularVelocity(float velocity);

	void setPosition(const Vector2D& position);
	void setScale(const Vector2D& scale);
	void setRotation(float rotation);

	void enableFade(bool fade);
	void setFadeStart(float start);
	void setFadeEnd(float end);
	void setFadeSpeed(float speed);

	void setTexture(Texture* texture);

	bool isDestroyed() const;

	float getGravityMultiplier() const;
	float getLifeTime() const;

	const Vector2D& getVelocity() const;
	const Vector2D& getScaleVelocity() const;
	float getAngularVelocity() const;

	const Vector2D& getPosition() const;
	const Vector2D& getScale() const;
	float getRotation() const;

	bool canFade() const;
	float getFadeStart() const;
	float getFadeEnd() const;
	float getFadeSpeed() const;

	Texture* getTexture() const;

private:
	float gravity_multiplier;
	float life_time;

	Vector2D velocity;
	Vector2D scale_velocity;
	float angular_velocity;

	Vector2D position;
	Vector2D scale;
	float rotation;

	bool fade;
	float fade_start;
	float fade_end;
	float fade_speed;

	Texture* texture;
};

#endif
