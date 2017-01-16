#include "SceneGraph/Objects/Components/EmitterComponent.h"
#include "SceneGraph/Objects/Components/TransformComponent.h"

#include "SceneGraph/Objects/GameObjects/GameObject.h"

#include "Core/Data/Objects/Descriptions/Particles/EmitterComponentDescription.h"
#include "Core/Data/Objects/Descriptions/Particles/ParticleDescription.h"
#include "Core/Data/Objects/Timers/WorldTimer.h"

#include "Core/Data/Manager/SettingsManager.h"

#include "Core/Defines/deletemacros.h"
#include "Core/Defines/debug.h"

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
		addParticle(particle_descriptions[i]);

	return true;
}
void EmitterComponent::update()
{
	for (unsigned int i = 0; i < (unsigned int)this->particle_descriptions.size(); ++i)
	{
		this->particle_descriptions[i].setLifeTime(this->particle_descriptions[i].getLifeTime() - WorldTimer::getWorldDeltaTime());
		if (this->particle_descriptions[i].getLifeTime() < 0.0f)
			this->particle_descriptions[i].destroy();

		this->particle_descriptions[i].setPosition(this->particle_descriptions[i].getPosition() + this->particle_descriptions[i].getVelocity() * WorldTimer::getWorldDeltaTime());
		this->particle_descriptions[i].setScale(this->particle_descriptions[i].getScale() + this->particle_descriptions[i].getScaleVelocity() * WorldTimer::getWorldDeltaTime());
		this->particle_descriptions[i].setRotation(this->particle_descriptions[i].getRotation() + this->particle_descriptions[i].getAngularVelocity() * WorldTimer::getWorldDeltaTime());

		LogManager::getInstance().log(new TodoLog(_T("Particle gravity"), LOG_INFO));
		LogManager::getInstance().log(new TodoLog(_T("Particle fade"), LOG_INFO));
	}

	//Remove destroyed particles
	this->particle_descriptions.erase(std::remove_if(this->particle_descriptions.begin(), this->particle_descriptions.end(),
		[](const ParticleDescription& desc) -> bool
	{
		return desc.isDestroyed();
	}));

	if (this->description->canLoop())
	{
		unsigned int current_particle_amount = (unsigned int)this->particle_descriptions.size();
		unsigned int desired_particle_amount = this->description->getParticleAmount();

		unsigned int diff = desired_particle_amount - current_particle_amount;
		if (diff > 0)
		{
			this->description->setDirty(true);

			for (unsigned int i = 0; i < diff; ++i)
			{
				ParticleDescription description;
				addParticle(description);

				particle_descriptions.push_back(description);
			}
		}
	}

	if (!this->description->getDirty())
		return;

	LogManager::getInstance().log(new TodoLog(_T("Apply particle emitter modifications"), LOG_INFO));

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
const std::vector<ParticleDescription>& EmitterComponent::getParticleDescriptions() const
{
	return this->particle_descriptions;
}

void EmitterComponent::addParticle(ParticleDescription& desc)
{
	TransformComponent* transform = getParent()->getComponent<TransformComponent>();
	if (transform == nullptr)
		return;

	desc.setPosition(transform->getPosition());
	desc.setScale(transform->getScale());
	desc.setRotation(transform->getRotation());

	desc.setGravityMultiplier(this->description->getGravityMultiplier());
	desc.setLifeTime(this->description->getLifeTime());

	desc.setVelocity(this->description->getVelocity());
	desc.setScaleVelocity(this->description->getScaleVelocity());
	desc.setAngularVelocity(this->description->getAngularVelocity());

	desc.enableFade(this->description->canFade());
	desc.setFadeStart(this->description->getFadeStart());
	desc.setFadeEnd(this->description->getFadeEnd());
	desc.setFadeSpeed(this->description->getFadeSpeed());

	if ((int)this->description->getTextures().size() > 0)
		desc.setTexture(this->description->getTextures()[rand() % (int)this->description->getTextures().size()]);
}