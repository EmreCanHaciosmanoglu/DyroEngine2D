#ifndef _COMPONENTVISUALIZATION_H
#define _COMPONENTVISUALIZATION_H

#include "Rendering/Objects/Visualization/Visualization.h"

class Component;

class ComponentVisualization : public Visualization
{
public:
	ComponentVisualization(Component* component, const std::tstring& name = _T(""));
	virtual ~ComponentVisualization();

	virtual void getRenderItems(std::vector<RenderItem*>& items);
	virtual Rect2D getBoundingBox();

	Component* getComponent() const;

protected:

	virtual void generateRenderItems(std::vector<RenderItem*>& items) = 0;
};

#endif