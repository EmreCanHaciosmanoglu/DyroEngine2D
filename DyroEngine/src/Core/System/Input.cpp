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
{}
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

	//POINT mouse_delta = getMouseMovement();
	//if(mouse_delta.x != 0 || mouse_delta.y != 0)
		//Broadcast mouse movement

	for (InputBinding& binding : this->vec_bindings)
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
bool Input::shutdown()
{
	return true;
}

void Input::bindInput(const InputBinding& binding)
{
	vec_bindings.push_back(binding);
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