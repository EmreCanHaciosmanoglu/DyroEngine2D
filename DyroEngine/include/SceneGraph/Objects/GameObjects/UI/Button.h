#ifndef _BUTTON_H
#define _BUTTON_H

#include "SceneGraph\Objects\GameObjects\UI\UIObject.h"

#ifndef _VECTOR_
#include <vector>
#endif
#ifndef _FUNCTIONAL_
#include <functional>
#endif

class ButtonDescription;
class Input;

class Button : public UIObject
{
public:
	Button(ButtonDescription* desc, const std::tstring& name = _T("Button"));
	virtual ~Button();

	virtual bool initialize();
	virtual void update();
	virtual bool shutdown();

	virtual void setupInput(Input* input);

	bool isSelected() const;
	bool isHovered() const;

	void onClicked(std::function<void()> fn);
	void onHoverEnter(std::function<void()> fn);
	void onHoverLeave(std::function<void()> fn);

private:
	void updateBackgroundColor();
	void updateBorderColor();

	void checkMouseMove(const POINT& mousePosition, const POINT& mouseMove);
	void checkMousePress(const POINT& mousePosition, const POINT& mouseMove);
	void checkMouseRelease(const POINT& mousePosition, const POINT& mouseDelta);

	std::vector<std::function<void()>> on_clicked_bindings;
	std::vector<std::function<void()>> on_hover_enter_bindings;
	std::vector<std::function<void()>> on_hover_leave_bindings;

	ButtonDescription* description;

	bool selected;
	bool hovered;
};

#endif