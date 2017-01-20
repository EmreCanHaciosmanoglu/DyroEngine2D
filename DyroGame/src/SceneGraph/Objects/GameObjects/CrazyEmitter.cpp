#include "SceneGraph\Objects\GameObjects\CrazyEmitter.h"
#include "SceneGraph\Objects\Components\EmitterComponent.h"

#include "SceneGraph/Objects/Scenes/Scene.h"

CrazyEmitter::CrazyEmitter(EmitterComponentDescription* desc)
	:emitter(new EmitterComponent(desc))
{
	addComponent(emitter);
}
CrazyEmitter::~CrazyEmitter()
{}

bool CrazyEmitter::initialize()
{
	return SceneObject::initialize();
}
void CrazyEmitter::update()
{
	SceneObject::update();
}
bool CrazyEmitter::shutdown()
{
	return SceneObject::shutdown();
}

void CrazyEmitter::setupInput(Input* input)
{

}