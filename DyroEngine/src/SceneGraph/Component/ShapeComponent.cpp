#include "SceneGraph/Component/ShapeComponent.h"

#include "SceneGraph/Object/Objects/Shapes/Shape.h"
#include "SceneGraph/Object/GameObjects/GameObject.h"
#include "SceneGraph/Scene/Scene.h"

#include "Core/Rendering/Renderer.h"

#include "Interfaces/IFillableShape.h"

#include "Defines/deletemacros.h"

ShapeComponent::ShapeComponent(Shape* shape)
	:shape(shape)
{}
ShapeComponent::~ShapeComponent()
{
	SafeDelete(this->shape);
}

bool ShapeComponent::initialize()
{
	return true;
}
void ShapeComponent::draw()
{
	this->shape->render(getParent()->getScene()->getRenderer());
}
void ShapeComponent::update()
{

}
bool ShapeComponent::shutdown()
{
	return true;
}

void ShapeComponent::setFill(bool fill)
{
	IFillableShape* fillable = dynamic_cast<IFillableShape*>(this->shape);
	if (fillable)
		fillable->setFill(fill);
}
bool ShapeComponent::getFill() const
{
	IFillableShape* fillable = dynamic_cast<IFillableShape*>(this->shape);
	if (fillable)
		return fillable->getFill();

	return false;
}

void ShapeComponent::setColor(const Color& c)
{
	this->shape->setColor(c);
}
const Color& ShapeComponent::getColor() const
{
	return this->shape->getColor();
}