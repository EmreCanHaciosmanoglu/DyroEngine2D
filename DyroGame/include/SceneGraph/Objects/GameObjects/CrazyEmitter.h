#ifndef _CRAZYEMITTER_H
#define _CRAZYEMITTER_H

#include "SceneGraph\Objects\GameObjects\SceneObject.h"

class EmitterComponent;
class EmitterComponentDescription;

class Input;

class CrazyEmitter : public SceneObject
{
public:
	CrazyEmitter(EmitterComponentDescription* desc);
	virtual ~CrazyEmitter();

	virtual bool initialize();
	virtual void update();
	virtual bool shutdown();

	virtual void setupInput(Input* input);

private:
	EmitterComponent* emitter;
};

#endif