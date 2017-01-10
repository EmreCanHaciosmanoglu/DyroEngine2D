#ifndef _CONCRETECOMPONENTVISUALIZATION_H
#define _CONCRETECOMPONENTVISUALIZATION_H

#include "Rendering/Objects/Visualization/ComponentVisualizations/ComponentVisualization.h"

template <typename T>
class ConcreteComponentVisualization : public ComponentVisualization
{
public:
	ConcreteComponentVisualization(Component* component, const std::tstring& name = _T(""))
		:ComponentVisualization(component, name)
	{}
	virtual ~ConcreteComponentVisualization()
	{}

	T* getConcreteComponent() const
	{
		return dynamic_cast<T*>(getObject());
	}
};

#endif