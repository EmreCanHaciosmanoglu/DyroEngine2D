#include "Core/System/Objects/Logic.h"

#include "Core/Data/Objects/Message/Messages/SwitchSceneMessage.h"

#include "Core/Types/SystemType.h"
#include "Core/Types/MessageType.h"

#include "Core/Defines/assert.h"
#include "Core/Defines/deletemacros.h"

#include "SceneGraph/Manager/SceneManager.h"

Logic::Logic()
	:System(SystemType::LOGIC_SYSTEM)
{
	SceneManager::createInstance();
}
Logic::~Logic()
{
	SceneManager::destroyInstance();
}

bool Logic::initialize()
{
	if (!SceneManager::getInstance().initialize())
		return false;

	return true;
}
void Logic::update()
{
	if (!getIsActive())
		return;

	SceneManager::getInstance().update();
}
bool Logic::shutdown()
{
	if (!SceneManager::getInstance().shutdown())
		return false;

	return true;
}

void Logic::handleMessage(Message* message)
{
	switch (message->getMessageType())
	{
		case MessageType::SWITCH_SCENE_MESSAGE:
		{
			SwitchSceneMessage* switch_scene_message = dynamic_cast<SwitchSceneMessage*>(message);

			SceneManager::getInstance().setActiveScene(switch_scene_message->getNextSceneName());
		}
	}
}
std::vector<MessageType> Logic::listenTo() const
{
	return std::vector<MessageType> { MessageType::SWITCH_SCENE_MESSAGE };
}