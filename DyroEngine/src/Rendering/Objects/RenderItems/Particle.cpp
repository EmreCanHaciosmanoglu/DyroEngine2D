#include "Rendering/Objects/RenderItems/Particle.h"
#include "Rendering/Objects/RenderItems/Texture.h"
#include "Rendering/Renderer.h"

Particle::Particle(Visualization* parent, const ParticleDescription& desc, const std::tstring name)
	:RenderItem(parent, name)
	,description(description)
{}
Particle::~Particle()
{}

void Particle::render(Renderer* renderer)
{
	if(!description.isDestroyed())
		renderer->drawBitmap(this->description.getTexture()->getImage(), Vector2D(0,0));
}

bool Particle::isTransparant() const
{
	return this->description.getTexture()->isTransparant();
}

float Particle::getWidth() const
{
	return getParticleDescription().getTexture()->getWidth();
}
float Particle::getHeight() const
{
	return getParticleDescription().getTexture()->getHeight();
}

const ParticleDescription& Particle::getParticleDescription() const
{
	return this->description;
}