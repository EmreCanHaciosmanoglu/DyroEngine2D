#include "Rendering/Objects/RenderItems/Shapes/CircleShape.h"
#include "Rendering/Objects/Visualization/Visualization.h"

#include "Core\Data/Manager/GeometryManager.h"

#include "Rendering/Renderer.h"

#include "Core/System/Objects/Graphics.h"

#include "Core/Defines/assert.h"
#include "Core/Defines/d2dutill.h"

#include "SceneGraph\Objects\Scenes\Scene.h"

CircleShape::CircleShape(const std::tstring& name)
	:Shape(name)
{}
CircleShape::CircleShape(CircleShapeDescription* descripion, const std::tstring& name)
	: Shape(descripion, name)
{
}
CircleShape::~CircleShape()
{}

void CircleShape::create()
{
	this->geometry = GeometryManager::getInstance().getGeometry(getDescription());

	//Geometry cannot be null
	assert(this->geometry != nullptr);
}
void CircleShape::render(Renderer* renderer)
{
	//Renderer cannot be null
	assert(renderer != nullptr);

	CircleShapeDescription* desc = getCirlceShapeDescription();

	renderer->setColor(desc->getColor());

	desc->getFill()
		? renderer->fillGeometry(this->geometry)
		: renderer->drawGeometry(this->geometry, desc->getLineWidth());
}

float CircleShape::getWidth() const
{
	return getCirlceShapeDescription()->getRadius() * 2;
}
float CircleShape::getHeight() const
{
	return getCirlceShapeDescription()->getRadius() * 2;
}

CircleShapeDescription* CircleShape::getCirlceShapeDescription() const
{
	return dynamic_cast<CircleShapeDescription*>(getDescription());
}