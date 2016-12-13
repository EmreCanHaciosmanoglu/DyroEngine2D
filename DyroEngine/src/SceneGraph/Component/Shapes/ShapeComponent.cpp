#include "SceneGraph/Component/Shapes/ShapeComponent.h"
#include "SceneGraph\GameObjects\GameObject.h"
#include "SceneGraph\Scene\Scene.h"

#include "Core/Data/Shapes/Shape.h"

#include "Interfaces/IFillableShape.h"

#include "Defines/deletemacros.h"

ShapeComponent::ShapeComponent(Shape* shape, const std::tstring& name)
	:Component(name)
	,shape(shape)
{
	OBJECT_INIT(_T("ShapeComponent"));
}
ShapeComponent::~ShapeComponent()
{
	SafeDelete(this->shape);
}

bool ShapeComponent::initialize()
{
	return true;
}
void ShapeComponent::update()
{

}
bool ShapeComponent::shutdown()
{
	return true;
}

void ShapeComponent::setColor(const Color& c)
{
	this->shape->setColor(c);
}
const Color& ShapeComponent::getColor() const
{
	return this->shape->getColor();
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

Shape* ShapeComponent::getShape() const
{
	return this->shape;
}