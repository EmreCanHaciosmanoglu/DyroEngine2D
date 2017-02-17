#include "SceneGraph/Objects/Components/EmitterComponent.h"
#include "SceneGraph/Objects/Components/TransformComponent.h"

#include "SceneGraph/Objects/GameObjects/GameObject.h"

#include "SceneGraph/Objects/Scenes/Scene.h"

#include "Core/Data/Objects/Descriptions/Particles/EmitterComponentDescription.h"
#include "Core/Data/Objects/Descriptions/Particles/ParticleDescription.h"
#include "Core/Data/Objects/Timers/WorldTimer.h"
#include "Core/Data/Objects/Transition.h"

#include "Core/Defines/deletemacros.h"
#include "Core/Defines/debug.h"

EmitterComponent::EmitterComponent(EmitterComponentDescription* description, const std::tstring& name)
	:Component(name)
	, description(description)
	, current_emission_rate(description->getEmissionRate())
{
	description->setGravityMultiplier(1);
	OBJECT_INIT(_T("EmitterComponent"));
}
EmitterComponent::~EmitterComponent()
{
}

bool EmitterComponent::initialize()
{
	if (this->description->canSpawnAtStart())
	{
		for (unsigned int i = 0; i < this->description->getEmissionBurst(); ++i)
			addParticle();

		this->current_emission_rate = description->getEmissionRate();
	}

	return true;
}
void EmitterComponent::update()
{
	this->current_emission_rate -= WorldTimer::getWorldDeltaTime();
	if (this->current_emission_rate < 0.0f)
	{
		if (this->particle_descriptions.size() < (this->description->getParticleAmount() - this->description->getEmissionBurst()))
		{
			for (unsigned int i = 0; i < this->description->getEmissionBurst(); ++i)
				addParticle();

			this->current_emission_rate = description->getEmissionRate();
		}
	}

	for (unsigned int i = 0; i < (unsigned int)this->particle_descriptions.size(); ++i)
	{
		this->particle_descriptions[i]->setLifeTime(this->particle_descriptions[i]->getLifeTime() - WorldTimer::getWorldDeltaTime());
		if (this->particle_descriptions[i]->getLifeTime() < 0.0f)
			this->particle_descriptions[i]->destroy();

		this->particle_descriptions[i]->setPosition(this->particle_descriptions[i]->getPosition() + (this->particle_descriptions[i]->getVelocity() * WorldTimer::getWorldDeltaTime()));
		this->particle_descriptions[i]->setScale(this->particle_descriptions[i]->getScale() + this->particle_descriptions[i]->getScaleVelocity() * WorldTimer::getWorldDeltaTime());
		this->particle_descriptions[i]->setRotation(this->particle_descriptions[i]->getRotation() + this->particle_descriptions[i]->getAngularVelocity() * WorldTimer::getWorldDeltaTime());
	}

	//Remove destroyed particles
	for (std::vector<ParticleDescription*>::const_iterator it = this->particle_descriptions.begin(); it != this->particle_descriptions.end(); )
	{
		if ((*it)->isDestroyed())
		{
			delete * it;
			it = this->particle_descriptions.erase(it);
		}
		else ++it;
	}

	//LogManager::getInstance().log(new TodoLog(_T("Apply particle emitter modifications"), LOG_DATA));

	this->description->setDirty(false);
}
bool EmitterComponent::shutdown()
{
	for (ParticleDescription* desc : this->particle_descriptions)
		SafeDelete(desc);
	particle_descriptions.clear();

	SafeDelete(this->description);

	return true;
}

EmitterComponentDescription* EmitterComponent::getEmitterDescription() const
{
	return this->description;
}
const std::vector<ParticleDescription*>& EmitterComponent::getParticleDescriptions() const
{
	return this->particle_descriptions;
}

void EmitterComponent::addParticle()
{
	ParticleDescription* desc = new ParticleDescription();

	TransformComponent* transform = getParent()->getComponent<TransformComponent>();
	if (transform == nullptr)
		return;

	desc->setPosition(transform->getPosition() + this->description->getSpawnPositionOffset());
	desc->setScale(transform->getScale() + this->description->getSpawnScaleOffset());
	desc->setRotation(transform->getRotation() + this->description->getSpawnRotationOffset());

	desc->setGravityMultiplier(this->description->getGravityMultiplier());
	desc->setLifeTime(this->description->getLifeTime());

	desc->setVelocity(this->description->getVelocity());
	desc->setScaleVelocity(this->description->getScaleVelocity());
	desc->setAngularVelocity(this->description->getAngularVelocity());

	desc->enableFade(this->description->canFade());
	desc->setFadeStart(this->description->getFadeStart());
	desc->setFadeEnd(this->description->getFadeEnd());

	if ((int)this->description->getImages().size() > 0)
		desc->setImage(this->description->getImages()[rand() % (int)this->description->getImages().size()]);

	this->particle_descriptions.push_back(desc);
}