#ifndef _CONCRETEDATAOBJECTVISUALIZATION_H
#define _CONCRETEDATAOBJECTVISUALIZATION_H

#include "Rendering/Objects/Visualization/GameObjectVisualizations/GameObjectVisualization.h"

template <typename T>
class ConcreteDataObjectVisualization : public GameObjectVisualization
{
public:
	ConcreteDataObjectVisualization(GameObject* obj, const std::tstring& name = _T(""))
		:GameObjectVisualization(obj, name)
	{}
	virtual ~ConcreteDataObjectVisualization()
	{}

	T* getConcreteDataObject()
	{
		return dynamic_cast<T*>(getObject());
	}
};

#endif