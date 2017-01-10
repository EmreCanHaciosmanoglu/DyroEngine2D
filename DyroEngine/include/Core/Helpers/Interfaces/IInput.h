#ifndef _IINPUT_H
#define _IINPUT_H

class Input;

class IInput
{
public:
	virtual void setupInput(Input* input) = 0;

protected:
	IInput() {}
	virtual ~IInput() {}
};

#endif