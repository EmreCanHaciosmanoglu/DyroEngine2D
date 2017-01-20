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

class Image;

class EmitterComponentDescription
{
public:
	EmitterComponentDescription(unsigned int particleAmount);
	~EmitterComponentDescription();

	void setDirty(bool dirty);
	bool getDirty() const;

	void setParticleAmount(unsigned int amount);
	void setEmissionBurst(unsigned int burst);
	void setEmissionRate(float rate);
	void setGravityMultiplier(float multiplier);
	void setLifeTime(const RangeFloat& time);
	void setLoop(bool loop);
	void setSpawnAtStart(bool spawn);
	
	void setVelocity(const RangeVector2D& velocity);
	void setScaleVelocity(const RangeVector2D& velocity);
	void setAngularVelocity(const RangeFloat& velocity);

	void enableFade(bool fade);
	void setFadeStart(float start);
	void setFadeEnd(float end);
	void setFadeSpeed(const RangeFloat& speed);

	void setSpawnPositionOffset(const RangeVector2D& offset);
	void setSpawnScaleOffset(const RangeVector2D& offset);
	void setSpawnRotationOffset(const RangeFloat& offset);

	void addImage(Image* texture);

	unsigned int getParticleAmount() const;
	unsigned int getEmissionBurst() const;
	float getEmissionRate() const;
	float getGravityMultiplier() const;
	float getLifeTime() const;
	bool canLoop() const;
	bool canSpawnAtStart() const;

	const Vector2D getVelocity() const;
	const Vector2D getScaleVelocity() const;
	float getAngularVelocity() const;

	bool canFade() const;
	float getFadeStart() const;
	float getFadeEnd() const;
	float getFadeSpeed() const;

	const Vector2D getSpawnPositionOffset();
	const Vector2D getSpawnScaleOffset();
	float getSpawnRotationOffset();

	const std::vector<Image*>& getImages() const;

private:
	unsigned int particle_amount;
	unsigned int emission_burst;
	float emission_rate;
	float gravity_multiplier;
	RangeFloat life_time;
	bool loop;
	bool spawn_at_start;

	RangeVector2D velocity;
	RangeVector2D scale_velocity;
	RangeFloat angular_velocity;

	bool fade;
	float fade_start;
	float fade_end;
	RangeFloat fade_speed;

	RangeVector2D spawn_position_offset;
	RangeVector2D spawn_scale_offset;
	RangeFloat spawn_rotation_offset;

	std::vector<Image*> images;

	bool dirty;
};

#endif
