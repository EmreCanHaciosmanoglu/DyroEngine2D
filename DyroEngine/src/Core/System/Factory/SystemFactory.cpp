#include "Core/System/Factory/SystemFactory.h"

#include "Core\Types\SystemType.h"

#include "Core\System\Objects\System.h"
#include "Core\System\Objects\Window.h"
#include "Core\System\Objects\Graphics.h"
#include "Core\System\Objects\Logic.h"
#include "Core\System\Objects\Input.h"

SystemFactory::SystemFactory()
{
}
SystemFactory::~SystemFactory()
{
}

System* SystemFactory::createSystem(SystemType type)
{
	switch (type)
	{
	case SystemType::WINDOW_SYSTEM: return new Window();
	case SystemType::INPUT_SYSTEM: return new Input();
	case SystemType::LOGIC_SYSTEM: return new Logic();
	case SystemType::GRAPHICS_SYSTEM: return new Graphics();
	}

	return nullptr;
}