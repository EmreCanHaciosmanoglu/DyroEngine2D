#include "Core/Rendering/Visualization/Shapes/TriangleShapeVisualization.h"
#include "SceneGraph\Component\Shapes\TriangleShapeComponent.h"

#include "Core/Data/Shapes/TriangleShape.h"

TriangleShapeVisualization::TriangleShapeVisualization(Object* object, const std::tstring& name)
	:PolygonShapeVisualization(object, name)
{

}
TriangleShapeVisualization::~TriangleShapeVisualization()
{

}

Rect2D TriangleShapeVisualization::getBoundingBox() const
{
	return Rect2D::empty;
}

void TriangleShapeVisualization::generateRenderItems(std::vector<RenderItem*>& items)
{
	TriangleShapeComponent* component = dynamic_cast<TriangleShapeComponent*>(getObject());
	if (component == nullptr)
		return;

	items.push_back(component->getTriangleShape());
}