#ifndef _IINPUT_H
#define _IINPUT_H

class Input;

class IInput
{
public:
	IInput() {}
	virtual ~IInput() {}

	virtual void setupInput(Input* input) = 0;
};

#endif