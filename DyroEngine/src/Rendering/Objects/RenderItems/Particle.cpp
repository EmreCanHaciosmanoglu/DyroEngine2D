#include "Rendering/Objects/RenderItems/Particle.h"
#include "Rendering/Objects/RenderItems/Texture.h"
#include "Rendering/Renderer.h"

#include "Rendering/Manager/TextureManager.h"
#include "Rendering/Objects/RenderItems/Texture.h"

#include "Rendering/Objects/Visualization/Visualization.h"

#include "SceneGraph/Objects/Scenes/Scene.h"

Particle::Particle(Visualization* parent, const ParticleDescription& desc, const std::tstring name)
	:RenderItem(parent, name)
	,description(desc)
	,texture(nullptr)
{
	this->texture = parent->getScene()->getManager<TextureManager>()->getTexture(desc.getImage());
	if (this->texture == nullptr)
	{
		this->texture = new Texture(parent, desc.getImage());
		parent->getScene()->getManager<TextureManager>()->addTexture(this->texture);
	}
}
Particle::~Particle()
{}

void Particle::render(Renderer* renderer)
{
	if(!description.isDestroyed())
		renderer->drawBitmap(this->texture->getImage(), Vector2D(0,0));
}

bool Particle::isTransparant() const
{
	return this->texture->isTransparant();
}

float Particle::getWidth() const
{
	return this->texture->getWidth();
}
float Particle::getHeight() const
{
	return this->texture->getHeight();
}

const ParticleDescription& Particle::getParticleDescription() const
{
	return this->description;
}