#ifndef _PARTICLE_H
#define _PARTICLE_H

#include "Rendering/Objects/RenderItems/Texture.h"

#ifndef _PARTICLEDESCRIPTION_H
#include "Core/Data/Objects/Descriptions/Particles/ParticleDescription.h"
#endif

class Texture;

class Particle : public Texture
{
public:
	Particle(ParticleDescription* desc, const std::tstring name = _T("Particle"));
	virtual ~Particle();

	virtual void render(Renderer* renderer);

	ParticleDescription* getParticleDescription() const;

private:
	ParticleDescription* description;
};

#endif