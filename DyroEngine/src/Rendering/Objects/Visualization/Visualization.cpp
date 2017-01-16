#include "Rendering/Objects/Visualization/Visualization.h"
#include "Rendering/Manager/VisualizationManager.h"

Visualization::Visualization(Object* object, const std::tstring& name)
	:TaggedObject(name)
	, parent_visualization(nullptr)
	, scene(nullptr)
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

void Visualization::setScene(Scene* scene)
{
	this->scene = scene;
}
Scene* Visualization::getScene() const
{
	return this->scene;
}

Object* Visualization::getObject() const
{
	return this->object;
}