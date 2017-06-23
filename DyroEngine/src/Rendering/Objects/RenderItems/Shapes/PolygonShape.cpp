#include "Rendering/Objects/RenderItems/Shapes/PolygonShape.h"
#include "Rendering/Objects/Visualization/Visualization.h"

#include "Core\Data/Manager/GeometryManager.h"

#include "Rendering/Renderer.h"

#include "Core/System/Objects/Graphics.h"

#include "Core/Defines/assert.h"
#include "Core/Defines/d2dutill.h"
#include "Core/Defines/deletemacros.h"

#include "SceneGraph\Objects\Scenes\Scene.h"

PolygonShape::PolygonShape(const std::tstring& name)
	:Shape(name)
{}
PolygonShape::PolygonShape(PolygonShapeDescription* description, Geometry* geometry, const std::tstring& name)
	: Shape(description, geometry, name)
{
}
PolygonShape::~PolygonShape()
{}

void PolygonShape::render(Renderer* renderer)
{
	//Renderer cannot be null
	assert(renderer != nullptr);

	PolygonShapeDescription* desc = getPolygonShapeDescription();

	renderer->setColor(desc->getColor());

	desc->getFill()
		? renderer->fillGeometry(this->geometry)
		: renderer->drawGeometry(this->geometry, desc->getLineWidth());
}

float PolygonShape::getWidth() const
{
	return this->description->getWidth();
}
float PolygonShape::getHeight() const
{
	return this->description->getHeight();
}

PolygonShapeDescription* PolygonShape::getPolygonShapeDescription() const
{
	return dynamic_cast<PolygonShapeDescription*>(getDescription());
}