#ifndef _INPUT_H
#define _INPUT_H

#include "Core\System\System.h"
#include "Defines\Types\InputStateType.h"

#ifndef _WINDOWS_
#include <Windows.h>
#endif

#ifndef _VECTOR_
#include <vector>
#endif
#ifndef _FUNCTIONAL_
#include <functional>
#endif

class MainWindow;

struct InputBinding
{
	InputBinding(unsigned int key, std::function<void()> fn, InputStateType type)
		:key(key)
		,callback_function(fn)
		,type(type)
	{}
	InputBinding(const InputBinding& ref)
		:key(ref.key)
		,callback_function(ref.callback_function)
		,type(ref.type)
	{}

	InputBinding operator= (const InputBinding& ref)
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

class Input : public System
{
public:
	Input();
	virtual ~Input();

	virtual bool initialize();
	virtual void update();
	virtual bool shutdown();

	void bindInput(const InputBinding& binding);

	POINT getMousePosition(bool previousFrame = false);
	POINT getMouseMovement();

	void showMouseCursor(bool show);

private:
	bool isKeyDown(unsigned int key);
	bool isKeyUp(unsigned int key);
	bool isKeyPressed(unsigned int key);
	bool isKeyReleased(unsigned int key);

	std::vector<InputBinding> vec_bindings;

	BYTE* current_keyboard_state;
	BYTE* previous_keyboard_state;
	BYTE* keyboard_state_0;
	BYTE* keyboard_state_1;

	bool keyboard_state_0_active;

	POINT current_mouse_position;
	POINT old_mouse_position;

	MainWindow* main_window;
};

#endif