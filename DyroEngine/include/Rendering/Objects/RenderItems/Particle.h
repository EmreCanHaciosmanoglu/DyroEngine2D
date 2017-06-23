#ifndef _PARTICLE_H
#define _PARTICLE_H

#include "Rendering/Objects/RenderItems/Texture.h"

class Texture;
class ParticleDescription;

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