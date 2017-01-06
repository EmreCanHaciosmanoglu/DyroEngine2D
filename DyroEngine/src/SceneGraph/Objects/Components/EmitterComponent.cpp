#include "SceneGraph/Objects/Components/EmitterComponent.h"

#include "Core/Data/Objects/Descriptions/Particles/EmitterComponentDescription.h"
#include "Core/Data/Objects/Descriptions/Particles/ParticleDescription.h"

#include "Core/Defines/deletemacros.h"

EmitterComponent::EmitterComponent(EmitterComponentDescription* description,const std::tstring& name)
	:Component(name)
	,description(description)
{
	OBJECT_INIT(_T("EmitterComponent"));

	//Init the particle description vector
	particle_descriptions.resize(this->description->getParticleAmount(), ParticleDescription());
}
EmitterComponent::~EmitterComponent()
{}

bool EmitterComponent::initialize()
{
	for (unsigned int i = 0; i < this->description->getParticleAmount(); ++i)
	{
		particle_descriptions[i].setGravityMultiplier(this->description->getGravityMultiplier());
		
		particle_descriptions[i].setLifeTime((float)fmod((float)rand(), this->description->getMaxLifetime()) + this->description->getMinLifeTime());

		particle_descriptions[i].setVelocity(Vector2D::randomVector(this->description->getMinVelocity(),this->description->getMaxVelocity()));
		particle_descriptions[i].setAngularVelocity((float)fmod((float)rand(), this->description->getMaxAngularVelocity()) + this->description->getMinAngularVelocity());

		particle_descriptions[i].setScale(Vector2D::randomVector(this->description->getMinScale(),this->description->getMaxScale()));
		particle_descriptions[i].setGrowSpeed((float)fmod((float)rand(), this->description->getMaxGrowSpeed()) + this->description->getMinGrowSpeed());

		particle_descriptions[i].enableFade(this->description->canFade());

		particle_descriptions[i].setFadeStart(this->description->getFadeStart());
		particle_descriptions[i].setFadeEnd(this->description->getFadeEnd());

		particle_descriptions[i].setFadeSpeed((float)fmod((float)rand(), this->description->getMaxFadeSpeed()) + this->description->getMinFadeSpeed());

		if((int)this->description->getTextures().size() > 0)
			particle_descriptions[i].setTexture(this->description->getTextures()[rand() % (int)this->description->getTextures().size()]);
	}

	return true;
}
void EmitterComponent::update()
{
	if (!this->description->getDirty())
		return;

	for (unsigned int i = 0; i < this->description->getParticleAmount(); ++i)
	{
		particle_descriptions[i].setGravityMultiplier(this->description->getGravityMultiplier());

		particle_descriptions[i].setLifeTime((float)fmod((float)rand(), this->description->getMaxLifetime()) + this->description->getMinLifeTime());

		particle_descriptions[i].setVelocity(Vector2D::randomVector(this->description->getMinVelocity(), this->description->getMaxVelocity()));
		particle_descriptions[i].setAngularVelocity((float)fmod((float)rand(), this->description->getMaxAngularVelocity()) + this->description->getMinAngularVelocity());

		particle_descriptions[i].setScale(Vector2D::randomVector(this->description->getMinScale(), this->description->getMaxScale()));
		particle_descriptions[i].setGrowSpeed((float)fmod((float)rand(), this->description->getMaxGrowSpeed()) + this->description->getMinGrowSpeed());

		particle_descriptions[i].enableFade(this->description->canFade());

		particle_descriptions[i].setFadeStart(this->description->getFadeStart());
		particle_descriptions[i].setFadeEnd(this->description->getFadeEnd());

		particle_descriptions[i].setFadeSpeed((float)fmod((float)rand(), this->description->getMaxFadeSpeed()) + this->description->getMinFadeSpeed());

		if ((int)this->description->getTextures().size() > 0)
			particle_descriptions[i].setTexture(this->description->getTextures()[rand() % (int)this->description->getTextures().size()]);
	}

	this->description->setDirty(false);
}
bool EmitterComponent::shutdown()
{
	particle_descriptions.clear();

	SafeDelete(this->description);

	return true;
}

EmitterComponentDescription* EmitterComponent::getEmitterDescription() const 
{
	return this->description;
}