#include "Rendering\Objects\RenderItems\Shapes\TriangleShape.h"
#include "Rendering/Objects/Visualization/Visualization.h"

#include "Core\Data/Manager/GeometryManager.h"

TriangleShape::TriangleShape(const std::tstring& name)
	:PolygonShape(name)
{}
TriangleShape::TriangleShape(TriangleShapeDescription* desc, const std::tstring& name)
	:PolygonShape(desc, name)
{}
TriangleShape::~TriangleShape()
{}

void TriangleShape::create()
{
	this->geometry = GeometryManager::getInstance().getGeometry(getDescription());

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