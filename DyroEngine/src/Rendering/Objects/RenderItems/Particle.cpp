#include "Rendering/Objects/RenderItems/Particle.h"
#include "Rendering/Objects/RenderItems/Texture.h"
#include "Rendering/Renderer.h"

#include "Rendering/Manager/TextureManager.h"
#include "Rendering/Objects/RenderItems/Texture.h"

Particle::Particle(ParticleDescription* desc, const std::tstring name)
	:Texture(desc->getImage(), name)
	, description(desc)
{}
Particle::~Particle()
{}

void Particle::render(Renderer* renderer)
{
	if (!description->isDestroyed())
		renderer->drawBitmap(getImage(), this->description->getFadeAmount());
}

ParticleDescription* Particle::getParticleDescription() const
{
	return this->description;
}