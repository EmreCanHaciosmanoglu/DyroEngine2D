#include "Rendering/Objects/RenderItems/Shapes/LineShape.h"
#include "Rendering/Objects/Visualization/Visualization.h"

#include "Core\Data/Manager/GeometryManager.h"

#include "Rendering/Renderer.h"

#include "Core/System/Objects/Graphics.h"

#include "Core/Defines/assert.h"
#include "Core/Defines/d2dutill.h"
#include "Core/Defines/deletemacros.h"

LineShape::LineShape(const std::tstring& name)
	:Shape(name)
{}
LineShape::LineShape(LineShapeDescription* description, const std::tstring& name)
	:Shape(description, name)
{}
LineShape::~LineShape()
{}

void LineShape::create()
{
	this->geometry = GeometryManager::getInstance().getGeometry(getDescription());

	//Geometry cannot be null
	assert(this->geometry != nullptr);

}
void LineShape::render(Renderer* renderer)
{
	//Renderer cannot be null
	assert(renderer != nullptr);

	LineShapeDescription* desc = getLineShapeDescription();

	renderer->setColor(desc->getColor());
	renderer->drawGeometry(this->geometry, desc->getLineWidth());
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