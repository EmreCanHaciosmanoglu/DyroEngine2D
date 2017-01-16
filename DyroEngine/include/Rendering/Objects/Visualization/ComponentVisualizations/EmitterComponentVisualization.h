#ifndef _EMITTERCOMPONENTVISUALIZATION_H
#define _EMITTERCOMPONENTVISUALIZATION_H

#include "Rendering/Objects/Visualization/ComponentVisualizations/ConcreteComponentVisualization.h"

class EmitterComponent;
class Particle;

class EmitterComponentVisualization : public ConcreteComponentVisualization<EmitterComponent>
{
public:
	EmitterComponentVisualization(Component* component, const std::tstring& name = _T(""));
	virtual ~EmitterComponentVisualization();

	virtual bool initialize();
	virtual bool shutdown();

protected:
	virtual void generateRenderItems(std::vector<RenderItem*>& items);

private:
	std::vector<Particle*> particles;
};

#endif