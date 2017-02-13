#include "Core\System\Objects\Input.h"
#include "Core\System\Objects\Window.h"
#include "Core\System\Manager\SystemManager.h"

Input::Input()
	:System(SystemType::INPUT_SYSTEM)
	, current_keyboard_state(nullptr)
	, previous_keyboard_state(nullptr)
	, keyboard_state_0(nullptr)
	, keyboard_state_1(nullptr)
	, main_window(nullptr)
{
	current_mouse_position.x = 0;
	current_mouse_position.y = 0;

	old_mouse_position.x = 0;
	old_mouse_position.y = 0;
}
Input::~Input()
{}

bool Input::initialize()
{
	keyboard_state_0 = new BYTE[256];
	keyboard_state_1 = new BYTE[256];

	GetKeyboardState(keyboard_state_0);
	GetKeyboardState(keyboard_state_1);

	main_window = dynamic_cast<Window*>(SystemManager::getInstance().getSystem(SystemType::WINDOW_SYSTEM));

	return true;
}
void Input::update()
{
	if (!getIsActive())
		return;

	BOOL getKeyboardResult;
	if (keyboard_state_0_active)
	{
		getKeyboardResult = GetKeyboardState(keyboard_state_1);
		previous_keyboard_state = keyboard_state_0;
		current_keyboard_state = keyboard_state_1;
	}
	else
	{
		getKeyboardResult = GetKeyboardState(keyboard_state_0);
		previous_keyboard_state = keyboard_state_1;
		current_keyboard_state = keyboard_state_0;
	}

	keyboard_state_0_active = !keyboard_state_0_active;

	old_mouse_position = current_mouse_position;
	if (GetCursorPos(&current_mouse_position))
		ScreenToClient(main_window->getWindowHandle(), &current_mouse_position);

	checkMouseBindings();
	checkKeyBindings();
}
bool Input::shutdown()
{
	return true;
}

void Input::bindKey(const KeyBinding& binding)
{
	this->vec_key_bindings.push_back(binding);
}
void Input::bindMouseMove(const MouseMoveBinding& binding)
{
	this->vec_mousemove_bindings.push_back(binding);
}
void Input::bindMouseClick(const MouseClickBinding& binding)
{
	this->vec_mouseclick_bindings.push_back(binding);
}

POINT Input::getMousePosition(bool previousFrame)
{
	return previousFrame ? old_mouse_position : current_mouse_position;
}
POINT Input::getMouseMovement()
{
	POINT delta_mouseposition;

	delta_mouseposition.x = abs(current_mouse_position.x - old_mouse_position.x);
	delta_mouseposition.y = abs(current_mouse_position.y - old_mouse_position.y);

	return delta_mouseposition;
}

void Input::showMouseCursor(bool show)
{
	ShowCursor(show);
}

bool Input::isKeyDown(unsigned int key)
{
	return ((previous_keyboard_state[key] & 0xF0) != 0 && (current_keyboard_state[key] & 0xF0) != 0);
}
bool Input::isKeyUp(unsigned int key)
{
	return ((previous_keyboard_state[key] & 0xF0) == 0 && (current_keyboard_state[key] & 0xF0) == 0);
}
bool Input::isKeyPressed(unsigned int key)
{
	return ((previous_keyboard_state[key] & 0xF0) == 0 && (current_keyboard_state[key] & 0xF0) != 0);
}
bool Input::isKeyReleased(unsigned int key)
{
	return ((previous_keyboard_state[key] & 0xF0) != 0 && (current_keyboard_state[key] & 0xF0) == 0);
}

void Input::checkMouseBindings()
{
	//Mouse move
	POINT mouse_delta = getMouseMovement();
	if (mouse_delta.x != 0 || mouse_delta.y != 0)
	{
		for (MouseMoveBinding& binding : this->vec_mousemove_bindings)
			binding.execute(getMousePosition(), mouse_delta);
	}

	//Mouse click
	for (MouseClickBinding& binding : this->vec_mouseclick_bindings)
	{
		switch (binding.type)
		{
		case InputStateType::PRESSED:
			if (isKeyPressed(convertMouseButton(binding.mouse_button)))
				binding.execute(getMousePosition(), getMouseMovement());
			break;
		case InputStateType::RELEASD:
			if (isKeyReleased(convertMouseButton(binding.mouse_button)))
				binding.execute(getMousePosition(), getMouseMovement());
			break;
		case InputStateType::DOWN:
			if (isKeyDown(convertMouseButton(binding.mouse_button)))
				binding.execute(getMousePosition(), getMouseMovement());
			break;
		case InputStateType::UP:
			if (isKeyUp(convertMouseButton(binding.mouse_button)))
				binding.execute(getMousePosition(), getMouseMovement());
			break;
		}
	}
}
void Input::checkKeyBindings()
{
	for (KeyBinding& binding : this->vec_key_bindings)
	{
		switch (binding.type)
		{
		case InputStateType::PRESSED:
			if (isKeyPressed(binding.key))
				binding.execute();
			break;
		case InputStateType::RELEASD:
			if (isKeyReleased(binding.key))
				binding.execute();
			break;
		case InputStateType::DOWN:
			if (isKeyDown(binding.key))
				binding.execute();
			break;
		case InputStateType::UP:
			if (isKeyUp(binding.key))
				binding.execute();
			break;
		}
	}
}

unsigned char Input::convertMouseButton(MouseButton button)
{
	switch (button)
	{
	case MouseButton::RIGHT: return VK_LBUTTON;
	case MouseButton::LEFT: return VK_RBUTTON;
	case MouseButton::MIDDLE: return VK_MBUTTON;
	}

	return 0;
}