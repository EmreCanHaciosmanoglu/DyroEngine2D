#include "Core/Data/Objects/Message/Messages/SwitchSceneMessage.h"

#include "Core/Types/MessageType.h"

SwitchSceneMessage::SwitchSceneMessage(const std::tstring& nextSceneName)
	:Message(MessageType::SWITCH_SCENE_MESSAGE)
	,next_scene_name(nextSceneName)
{}
SwitchSceneMessage::~SwitchSceneMessage()
{}

const std::tstring& SwitchSceneMessage::getNextSceneName() const
{
	return this->next_scene_name;
}