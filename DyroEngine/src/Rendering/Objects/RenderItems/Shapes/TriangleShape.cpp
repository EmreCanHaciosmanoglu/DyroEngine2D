#include "Rendering\Objects\RenderItems\Shapes\TriangleShape.h"
#include "Rendering/Objects/Visualization/Visualization.h"

#include "Core\Data/Manager/GeometryManager.h"

#include "SceneGraph\Objects\Scenes\Scene.h"

TriangleShape::TriangleShape(Visualization* parent, const std::tstring& name)
	:PolygonShape(parent, name)
{}
TriangleShape::TriangleShape(Visualization* parent, TriangleShapeDescription* desc, const std::tstring& name)
	:PolygonShape(parent, desc, name)
{}
TriangleShape::~TriangleShape()
{}

void TriangleShape::create()
{
	this->geometry = getParentVisualization()->getScene()->getManager<GeometryManager>()->getGeometry(getDescription());

	//Geometry cannot be null
	assert(this->geometry != nullptr);
}
void TriangleShape::render(Renderer* renderer)
{
	PolygonShape::render(renderer);
}

TriangleShapeDescription* TriangleShape::getTriangleShapeDescription() const
{
	return dynamic_cast<TriangleShapeDescription*>(getDescription());
}