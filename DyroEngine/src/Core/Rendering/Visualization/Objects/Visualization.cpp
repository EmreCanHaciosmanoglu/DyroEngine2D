#include "Core/Rendering/Visualization/Objects/Visualization.h"
#include "Core/Rendering/Visualization/Manager/VisualizationManager.h"

Visualization::Visualization(Object* object, const std::tstring& name)
	:TaggedObject(name)
	, parent_visualization(nullptr)
	, object(object)
{
}
Visualization::~Visualization()
{
}

void Visualization::setParent(Visualization* visualization)
{
	this->parent_visualization = visualization;
}
Visualization* Visualization::Visualization::getParent() const
{
	return this->parent_visualization;
}

Object* Visualization::getObject() const
{
	return this->object;
}