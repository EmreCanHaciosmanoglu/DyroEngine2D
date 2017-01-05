#include "SceneGraph/Objects/Components/EmitterComponent.h"

EmitterComponent::EmitterComponent(EmitterComponentDescription* description,const std::tstring& name = _T("EmitterComponent"))
	:Component(name)
	,description(description)
{}
EmitterComponent::~EmitterComponent()
{}

bool EmitterComponent::initialize()
{
	return true;
}
void EmitterComponent::update()
{}
bool EmitterComponent::shutdown()
{
	return true;
}