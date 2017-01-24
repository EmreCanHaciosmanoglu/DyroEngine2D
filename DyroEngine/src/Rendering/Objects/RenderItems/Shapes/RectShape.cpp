#include "Rendering/Objects/RenderItems/Shapes/RectShape.h"
#include "Rendering/Objects/Visualization/Visualization.h"

#include "Core\Data/Manager/GeometryManager.h"

#include "Rendering/Renderer.h"

#include "Core/System/Objects/Graphics.h"

#include "Core/Defines/assert.h"
#include "Core/Defines/d2dutill.h"

#include "SceneGraph\Objects\Scenes\Scene.h"

RectShape::RectShape(const std::tstring& name)
	:Shape(name)
{}
RectShape::RectShape(RectShapeDescription* desc, const std::tstring& name)
	: Shape(desc, name)
{
}
RectShape::~RectShape()
{}

void RectShape::create()
{
	this->geometry = GeometryManager::getInstance().getGeometry(getDescription());

	//Geometry cannot be null
	assert(this->geometry != nullptr);
}
void RectShape::render(Renderer* renderer)
{
	//Renderer cannot be null
	assert(renderer != nullptr);

	RectShapeDescription* desc = getRectShapeDescription();

	renderer->setColor(desc->getColor());

	desc->getFill()
		? renderer->fillGeometry(this->geometry)
		: renderer->drawGeometry(this->geometry, desc->getLineWidth());
}

float RectShape::getWidth() const
{
	return (float)getRectShapeDescription()->getRect().getWidth();
}
float RectShape::getHeight() const
{
	return (float)getRectShapeDescription()->getRect().getHeight();
}

RectShapeDescription* RectShape::getRectShapeDescription() const
{
	return dynamic_cast<RectShapeDescription*>(getDescription());
}