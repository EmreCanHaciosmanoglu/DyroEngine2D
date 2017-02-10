#ifndef _PLAYERCONTROLLERCOMPONENT_H
#define _PLAYERCONTROLLERCOMPONENT_H

#include "SceneGraph\Objects\Components\ControllerComponent.h"

class PlayerControllerComponent : public ControllerComponent
{
public:
	PlayerControllerComponent(const std::tstring& name = _T("PlayerControllerComponent"));
	virtual ~PlayerControllerComponent();
};

#endif
