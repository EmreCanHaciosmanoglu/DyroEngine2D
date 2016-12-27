#include "SceneGraph/Component/Shapes/ShapeComponent.h"
#include "SceneGraph\GameObjects\GameObject.h"
#include "SceneGraph\Scene\Scene.h"

#include "Core/Data/Objects/Descriptions/Shapes/ShapeDescription.h"

#include "Interfaces/IFillableShape.h"

#include "Defines/deletemacros.h"

ShapeComponent::ShapeComponent(ShapeDescription* description, const std::tstring& name)
	:Component(name)
	, description(description)
{
	OBJECT_INIT(_T("ShapeComponent"));
}
ShapeComponent::~ShapeComponent()
{
	SafeDelete(this->description);
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
	this->description->setColor(c);
}
void ShapeComponent::setLineWidth(float lineWidth)
{
	this->description->setLineWidth(lineWidth);
}

const Color& ShapeComponent::getColor() const
{
	return this->description->getColor();
}
float ShapeComponent::getLineWidth() const
{
	return this->description->getLineWidth();
}

ShapeDescription* ShapeComponent::getDescription() const
{
	return this->description;
}