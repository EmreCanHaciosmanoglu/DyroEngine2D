#ifndef _PARTICLE_H
#define _PARTICLE_H

#include "Rendering/Objects/RenderItems/Texture.h"

#ifndef _PARTICLEDESCRIPTION_H
#include "Core/Data/Objects/Descriptions/Particles/ParticleDescription.h"
#endif

class Texture;

class Particle : public RenderItem
{
public:
	Particle(Visualization* parent, const ParticleDescription& desc, const std::tstring name = _T("Particle"));
	virtual ~Particle();

	virtual void render(Renderer* renderer);

	virtual bool isTransparant() const;

	virtual float getWidth() const;
	virtual float getHeight() const;

	const ParticleDescription& getParticleDescription() const;

private:
	ParticleDescription description;
	Texture* texture;
};

#endif