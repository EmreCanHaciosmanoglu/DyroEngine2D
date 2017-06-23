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
RectShape::RectShape(RectShapeDescription* desc, Geometry* geometry, const std::tstring& name)
	: Shape(desc, geometry, name)
{
}
RectShape::~RectShape()
{}

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
	return this->description->getWidth();
}
float RectShape::getHeight() const
{
	return this->description->getHeight();
}

RectShapeDescription* RectShape::getRectShapeDescription() const
{
	return dynamic_cast<RectShapeDescription*>(getDescription());
}