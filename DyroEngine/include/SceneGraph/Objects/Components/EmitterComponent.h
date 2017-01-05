#ifndef _EMMITTERCOMPONENT_H
#define _EMMITTERCOMPONENT_H

#include "SceneGraph/Objects/Components/Component.h"

class EmitterComponentDescription;

class EmitterComponent : public Component
{
public:
	EmitterComponent(EmitterComponentDescription* description, const std::tstring& name = _T("EmitterComponent"));
	virtual ~EmitterComponent();

	virtual bool initialize();
	virtual void update();
	virtual bool shutdown();

private:

	EmitterComponentDescription* description;
};

#endif