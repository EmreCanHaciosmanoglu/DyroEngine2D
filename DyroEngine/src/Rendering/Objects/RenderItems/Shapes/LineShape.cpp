#include "Rendering/Objects/RenderItems/Shapes/LineShape.h"
#include "Rendering/Objects/Visualization/Visualization.h"

#include "Rendering/Manager/GeometryManager.h"

#include "Rendering/Renderer.h"

#include "Core/System/Objects/Graphics.h"

#include "Core/Defines/assert.h"
#include "Core/Defines/d2dutill.h"
#include "Core/Defines/deletemacros.h"

#include "SceneGraph\Objects\Scenes\Scene.h"

LineShape::LineShape(Visualization* parent, const std::tstring& name)
	:Shape(parent, name)
{}
LineShape::LineShape(Visualization* parent, LineShapeDescription* description, const std::tstring& name)
	:Shape(parent, description, name)
{}
LineShape::~LineShape()
{}

void LineShape::create()
{
	this->geometry = getParentVisualization()->getScene()->getManager<GeometryManager>()->getGeometry(getDescription());

	//Geometry cannot be null
	assert(this->geometry != nullptr);

}
void LineShape::render(Renderer* renderer)
{
	//Renderer cannot be null
	assert(renderer != nullptr);

	LineShapeDescription* desc = getLineShapeDescription();

	renderer->setColor(desc->getColor());
	renderer->drawGeometry(desc->getGeometry(), desc->getLineWidth());
}

float LineShape::getWidth() const
{
	return getLineShapeDescription()->getEndPosition().x - getLineShapeDescription()->getEndPosition().x;
}
float LineShape::getHeight() const
{
	return getLineShapeDescription()->getEndPosition().y - getLineShapeDescription()->getEndPosition().y;
}

LineShapeDescription* LineShape::getLineShapeDescription() const
{
	return dynamic_cast<LineShapeDescription*>(getDescription());
}