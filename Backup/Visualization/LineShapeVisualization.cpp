#include "Core/Rendering/Visualization/Shapes/LineShapeVisualization.h"
#include "SceneGraph\Component\Shapes\LineShapeComponent.h"

#include "Core/Data/Shapes/Shape.h"

LineShapeVisualization::LineShapeVisualization(Object* object, const std::tstring& name)
	:ShapeVisualization(object, name)
{

}
LineShapeVisualization::~LineShapeVisualization()
{

}

void LineShapeVisualization::generateRenderItems(std::vector<RenderItem>& items)
{
	LineShapeComponent* component = dynamic_cast<LineShapeComponent*>(getObject());
	if (component == nullptr)
		return;
}