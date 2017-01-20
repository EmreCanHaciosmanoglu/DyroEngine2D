#ifndef _EMMITTERCOMPONENT_H
#define _EMMITTERCOMPONENT_H

#include "SceneGraph/Objects/Components/Component.h"

class EmitterComponentDescription;
class ParticleDescription;

class EmitterComponent : public Component
{
	/**
	\note Must be present in every subclass definition.
	*/
	OBJECT_STATICS("EmitterComponent")

public:
	EmitterComponent(EmitterComponentDescription* description, const std::tstring& name = _T("EmitterComponent"));
	virtual ~EmitterComponent();

	virtual bool initialize();
	virtual void update();
	virtual bool shutdown();

	EmitterComponentDescription* getEmitterDescription() const;
	const std::vector<ParticleDescription>& getParticleDescriptions() const;

private:

	void addParticle();

	EmitterComponentDescription* description;
	std::vector<ParticleDescription> particle_descriptions;
	float current_emission_rate;
};

#endif