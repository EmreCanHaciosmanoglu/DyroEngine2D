#ifndef _IINPUT_H
#define _IINPUT_H

class Input;

class IInput
{
public:
	IInput(){}
	~IInput(){}

	virtual void setupInput(Input* input) = 0;
private:

};

#endif
