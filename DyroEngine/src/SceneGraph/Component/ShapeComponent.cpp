#include "SceneGraph/Component/ShapeComponent.h"

#include "Core/Data/DataObjects/Shapes/Shape.h"

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

Rect2D ShapeComponent::getBoundingBox() const
{
	Rect2D bounding_rect = Rect2D::empty;

	IBoundingBox* bounding_box = dynamic_cast<IBoundingBox*>(this->shape);
	if (bounding_box != nullptr)
		return bounding_box->getBoundingBox();

	return bounding_rect;
}