#ifndef _EMITTERCOMPONENTDESCRIPTION_H
#define _EMITTERCOMPONENTDESCRIPTION_H

#ifndef _VECTOR2D_H
#include "Math/Objects/Vector2D.h"
#endif
#ifndef _RANGE_H
#include "Math/Objects/Range.h"
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

	void setDirty(bool dirty);
	bool getDirty() const;

	void setParticleAmount(unsigned int amount);
	void setGravityMultiplier(float multiplier);
	void setLifeTime(const RangeFloat& time);
	void setLoop(bool loop);
	
	void setVelocity(const RangeVector2D& velocity);
	void setScaleVelocity(const RangeVector2D& velocity);
	void setAngularVelocity(const RangeFloat& velocity);

	void enableFade(bool fade);
	void setFadeStart(float start);
	void setFadeEnd(float end);
	void setFadeSpeed(const RangeFloat& speed);

	void addTexture(Texture* texture);

	unsigned int getParticleAmount() const;
	float getGravityMultiplier() const;
	float getLifeTime() const;
	bool canLoop() const;

	const Vector2D& getVelocity() const;
	const Vector2D& getScaleVelocity() const;
	float getAngularVelocity() const;

	bool canFade() const;
	float getFadeStart() const;
	float getFadeEnd() const;
	float getFadeSpeed() const;

	const std::vector<Texture*>& getTextures() const;

private:
	unsigned int particle_amount;
	float gravity_multiplier;
	RangeFloat life_time;
	bool loop;

	RangeVector2D velocity;
	RangeVector2D scale_velocity;
	RangeFloat angular_velocity;

	bool fade;
	float fade_start;
	float fade_end;
	RangeFloat fade_speed;

	std::vector<Texture*> textures;

	bool dirty;
};

#endif
