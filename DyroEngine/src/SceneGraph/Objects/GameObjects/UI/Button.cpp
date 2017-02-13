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

#include "Math\Objects\Rect2D.h"

Button::Button(ButtonDescription* desc, const std::tstring& name = _T("Button"))
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
	input->bindMouseMove(MouseMoveBinding(std::bind(&Button::checkMouseMove, this)));

	input->bindMouseClick(MouseClickBinding(Input::MouseButton::LEFT, std::bind(&Button::checkMousePress, this), InputStateType::PRESSED));
	input->bindMouseClick(MouseClickBinding(Input::MouseButton::LEFT, std::bind(&Button::checkMouseRelease, this), InputStateType::RELEASD));
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
void Button::onHover(std::function<void()> fn)
{
	this->on_hover_bindings.push_back(fn);
}

void Button::checkMouseMove(const POINT& mousePosition, const POINT& mouseDelta)
{
	Rect2D bounds = getBounds();

	if (bounds.contains(Vector2D(mousePosition.x, mousePosition.y)))
	{
		this->hovered = true;
		for (std::function<void()>& fn : this->on_hover_bindings)
			fn();
	}
	else this->hovered = false;
}

void Button::checkMousePress(const POINT& mousePosition, const POINT& mouseDelta)
{
	Rect2D bounds = getBounds();

	if (bounds.contains(Vector2D(mousePosition.x, mousePosition.y)))
		this->selected = true;
	else this->selected = false;
}
void Button::checkMouseRelease(const POINT& mousePosition, const POINT& mouseDelta)
{
	Rect2D bounds = getBounds();

	this->selected = false;
	if (bounds.contains(Vector2D(mousePosition.x, mousePosition.y)) && this->selected)
	{
		for (std::function<void()>& fn : this->on_clicked_bindings)
			fn();
	}
}