#ifndef _INPUT_H
#define _INPUT_H

#include "Core\System\Objects\System.h"
#include "Core\Types\InputStateType.h"

#ifndef _WINDOWS_
#include <Windows.h>
#endif

#ifndef _VECTOR_
#include <vector>
#endif
#ifndef _FUNCTIONAL_
#include <functional>
#endif

class Window;

struct KeyBinding
{
	KeyBinding(unsigned int key, std::function<void()> fn, InputStateType type)
		:key(key)
		, callback_function(fn)
		, type(type)
	{}
	KeyBinding(const KeyBinding& ref)
		:key(ref.key)
		, callback_function(ref.callback_function)
		, type(ref.type)
	{}

	KeyBinding operator= (const KeyBinding& ref)
	{
		(*this).key = ref.key;
		(*this).callback_function = ref.callback_function;
		(*this).type = ref.type;
	}

	void execute()
	{
		callback_function();
	}

	unsigned int key;
	std::function<void()> callback_function;
	InputStateType type;
};
struct MouseMoveBinding
{
	MouseMoveBinding(std::function<void(const POINT&, const POINT&)> fn)
		:callback_function(fn)
	{}
	MouseMoveBinding(const MouseMoveBinding& ref)
		:callback_function(ref.callback_function)
	{}

	MouseMoveBinding operator= (const MouseMoveBinding& ref)
	{
		(*this).callback_function = ref.callback_function;
	}

	void execute(const POINT& mousePosition, const POINT& mouseDelta)
	{
		callback_function(mousePosition, mouseDelta);
	}

	std::function<void(const POINT&, const POINT&)> callback_function;
};
struct MouseClickBinding
{
	MouseClickBinding(Input::MouseButton button, std::function<void(const POINT&, const POINT&)> fn, InputStateType type)
		:mouse_button(button)
		, callback_function(fn)
		, type(type)
	{}
	MouseClickBinding(const MouseClickBinding& ref)
		:mouse_button(ref.mouse_button)
		, callback_function(ref.callback_function)
		, type(ref.type)
	{}

	MouseClickBinding operator= (const MouseClickBinding& ref)
	{
		(*this).mouse_button = ref.mouse_button;
		(*this).callback_function = ref.callback_function;
		(*this).type = ref.type;
	}

	void execute(const POINT& mousePosition, const POINT& mouseDelta)
	{
		callback_function(mousePosition, mouseDelta);
	}

	Input::MouseButton mouse_button;
	std::function<void(const POINT&, const POINT&)> callback_function;
	InputStateType type;
};

class Input : public System
{
public:
	enum class MouseButton
	{
		RIGHT,
		LEFT,
		MIDDLE
	};

	Input();
	virtual ~Input();

	virtual bool initialize();
	virtual void update();
	virtual bool shutdown();

	void bindKey(const KeyBinding& binding);
	void bindMouseMove(const MouseMoveBinding& binding);
	void bindMouseClick(const MouseClickBinding& binding);

	POINT getMousePosition(bool previousFrame = false);
	POINT getMouseMovement();

	void showMouseCursor(bool show);

private:
	bool isKeyDown(unsigned int key);
	bool isKeyUp(unsigned int key);
	bool isKeyPressed(unsigned int key);
	bool isKeyReleased(unsigned int key);

	void checkMouseBindings();
	void checkKeyBindings();

	unsigned char convertMouseButton(Input::MouseButton button);

	std::vector<MouseMoveBinding> vec_mousemove_bindings;
	std::vector<MouseClickBinding> vec_mouseclick_bindings;
	std::vector<KeyBinding> vec_key_bindings;

	BYTE* current_keyboard_state;
	BYTE* previous_keyboard_state;
	BYTE* keyboard_state_0;
	BYTE* keyboard_state_1;

	bool keyboard_state_0_active;

	POINT current_mouse_position;
	POINT old_mouse_position;

	Window* main_window;
};

#endif