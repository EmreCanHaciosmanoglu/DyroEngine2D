#include "SceneGraph\Objects\GameObjects\UI\Button.h"
#include "SceneGraph\Objects\Components\Shapes\CircleShapeComponent.h"
#include "SceneGraph\Objects\Components\Shapes\LineShapeComponent.h"
#include "SceneGraph\Objects\Components\Shapes\PolygonShapeComponent.h"
#include "SceneGraph\Objects\Components\Shapes\RectShapeComponent.h"
#include "SceneGraph\Objects\Components\ImageComponent.h"

#include "Core/Data/Objects/Descriptions/UI/ButtonDescription.h"
#include "Core/Data/Objects/Descriptions/Shapes/CircleShapeDescription.h"
#include "Core/Data/Objects/Descriptions/Shapes/LineShapeDescription.h"
#include "Core/Data/Objects/Descriptions/Shapes/PolygonShapeDescription.h"
#include "Core/Data/Objects/Descriptions/Shapes/RectShapeDescription.h"

#include "Core/System/Objects/Input.h"

#include "Core/Types/GeometryType.h"
#include "Core/Types/MouseButtonType.h"

#include "Math\Objects\Rect2D.h"

#ifndef _FUNCTIONAL_
#include <functional>
#endif

Button::Button(ButtonDescription* desc, const std::tstring& name)
	:UIObject(name)
	, description(desc)
	, selected(false)
	, hovered(false)
{
	switch (this->description->getShape()->getGeometryType())
	{
	case GeometryType::CIRCLE_GEOMETRY:
		addComponent(new CircleShapeComponent(dynamic_cast<CircleShapeDescription*>(this->description->getShape())));
		break;
	case GeometryType::LINE_GEOMETRY:
		addComponent(new LineShapeComponent(dynamic_cast<LineShapeDescription*>(this->description->getShape())));
		break;
	case GeometryType::POLYGON_GEOMETRY:
		addComponent(new PolygonShapeComponent(dynamic_cast<PolygonShapeDescription*>(this->description->getShape())));
		break;
	case GeometryType::RECTANGLE_GEOMETRY:
		addComponent(new RectShapeComponent(dynamic_cast<RectShapeDescription*>(this->description->getShape())));
		break;
	}

	if (this->description->getImage() != nullptr)
		addComponent(new ImageComponent(this->description->getImage()));
}
Button::~Button()
{
	delete this->description;
}

bool Button::initialize()
{
	onHoverEnter(std::bind(&Button::updateBackgroundColor, this));
	onHoverEnter(std::bind(&Button::updateBorderColor, this));
	onHoverLeave(std::bind(&Button::updateBackgroundColor, this));
	onHoverLeave(std::bind(&Button::updateBorderColor, this));

	return UIObject::initialize();
}
void Button::update()
{
	UIObject::update();
}
bool Button::shutdown()
{
	return UIObject::shutdown();
}

void Button::setupInput(Input* input)
{
	//Place holders of mouse move will be filled up by the input system
	input->bindMouseMove(MouseMoveBinding(std::bind(&Button::checkMouseMove, this, std::placeholders::_1, std::placeholders::_2)));

	//Place holders of mouse click will be filled up by the input system
	input->bindMouseClick(MouseClickBinding(MouseButton::LEFT, std::bind(&Button::checkMousePress, this, std::placeholders::_1, std::placeholders::_2), InputStateType::PRESSED));
	input->bindMouseClick(MouseClickBinding(MouseButton::LEFT, std::bind(&Button::checkMouseRelease, this, std::placeholders::_1, std::placeholders::_2), InputStateType::RELEASD));
}

bool Button::isSelected() const
{
	return this->selected;
}
bool Button::isHovered() const
{
	return this->hovered;
}

void Button::onClicked(std::function<void()> fn)
{
	this->on_clicked_bindings.push_back(fn);
}
void Button::onHoverEnter(std::function<void()> fn)
{
	this->on_hover_enter_bindings.push_back(fn);
}
void Button::onHoverLeave(std::function<void()> fn)
{
	this->on_hover_leave_bindings.push_back(fn);
}

void Button::updateBackgroundColor()
{
	if (isHovered())
		this->description->getShape()->setColor(this->description->getBackgroundHoverColor());
	else this->description->getShape()->setColor(this->description->getBackgroundIdleColor());
}
void Button::updateBorderColor()
{
	//if (isHovered())
	//	this->description->getShape()->setColor(this->description->getBorderHoverColor());
	//else this->description->getShape()->setColor(this->description->getBorderIdleColor());
}

void Button::checkMouseMove(const POINT& mousePosition, const POINT& mouseDelta)
{
	Rect2D bounds = getBounds();

	if (bounds.contains(Vector2D((float)mousePosition.x, (float)mousePosition.y)) && !this->hovered)
	{
		this->hovered = true;
		for (std::function<void()>& fn : this->on_hover_enter_bindings)
			fn();
	}
	else if (!bounds.contains(Vector2D((float)mousePosition.x, (float)mousePosition.y)) && this->hovered)
	{
		this->hovered = false;
		for (std::function<void()>& fn : this->on_hover_leave_bindings)
			fn();
	}
}

void Button::checkMousePress(const POINT& mousePosition, const POINT& mouseDelta)
{
	Rect2D bounds = getBounds();

	if (bounds.contains(Vector2D((float)mousePosition.x, (float)mousePosition.y)))
		this->selected = true;
	else this->selected = false;
}
void Button::checkMouseRelease(const POINT& mousePosition, const POINT& mouseDelta)
{
	Rect2D bounds = getBounds();

	this->selected = false;
	if (bounds.contains(Vector2D((float)mousePosition.x, (float)mousePosition.y)) && this->selected)
	{
		for (std::function<void()>& fn : this->on_clicked_bindings)
			fn();
	}
}