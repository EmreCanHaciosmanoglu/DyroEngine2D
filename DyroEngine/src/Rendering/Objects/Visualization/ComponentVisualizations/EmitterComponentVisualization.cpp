#include "Rendering/Objects/Visualization/ComponentVisualizations/EmitterComponentVisualization.h"
#include "Rendering/Objects/RenderItems/Particle.h"
#include "Rendering/Objects/Visualization/GameObjectVisualizations/GameObjectVisualization.h"

#include "SceneGraph\Objects\GameObjects\SceneObject.h"

#include "Core/Data/Objects/Descriptions/Particles/ParticleDescription.h"
#include "Core/Data/Objects/Descriptions/Particles/EmitterComponentDescription.h"
#include "Core/Defines/deletemacros.h"

#include "SceneGraph/Objects/Components/EmitterComponent.h"

EmitterComponentVisualization::EmitterComponentVisualization(Component* component, const std::tstring& name)
	:ConcreteComponentVisualization(component, name)
{
	EmitterComponent* emitter_component = dynamic_cast<EmitterComponent*>(component);
	if (emitter_component != nullptr)
	{
		for (const ParticleDescription& desc : emitter_component->getParticleDescriptions())
			this->particles.push_back(new Particle(this, desc));
	}
}
EmitterComponentVisualization::~EmitterComponentVisualization()
{
	for (Particle* particle : this->particles)
		SafeDelete(particle);
}

void EmitterComponentVisualization::generateRenderItems(std::vector<RenderItem*>& items)
{
	GameObjectVisualization* parent = dynamic_cast<GameObjectVisualization*>(getParent());
	if (parent == nullptr)
		return;

	SceneObject* parent_object = dynamic_cast<SceneObject*>(parent->getObject());

	EmitterComponent* emitter_component = getConcreteComponent();
	if (emitter_component->getEmitterDescription()->getDirty())
	{
		for (Particle* particle : this->particles)
			SafeDelete(particle);

		for (const ParticleDescription& desc : emitter_component->getParticleDescriptions())
		{
			Particle* particle = new Particle(this, desc);
			this->particles.push_back(particle);

			particle->setLayer(parent_object->getLayer());
			particle->setTransform(particle->getPosition(), particle->getScale(), particle->getRotation());

			items.push_back(particle);
		}
	}
	else
	{
		for (Particle* particle : this->particles)
		{
			particle->setLayer(parent_object->getLayer());
			particle->setTransform(particle->getPosition(), particle->getScale(), particle->getRotation());

			items.push_back(particle);
		}
	}
}