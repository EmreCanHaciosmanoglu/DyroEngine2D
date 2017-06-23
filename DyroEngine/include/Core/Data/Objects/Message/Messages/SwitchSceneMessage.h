#ifndef _SWITCHSCENEMESSAGE_H
#define _SWITCHSCENEMESSAGE_H

#include "Core/Data/Objects/Message/Messages/Message.h"

#ifndef _STRING_H
#include "Core/Defines/string.h"
#endif

class SwitchSceneMessage : public Message
{
public:
	SwitchSceneMessage(const std::tstring& nextSceneName);
	virtual ~SwitchSceneMessage();

	const std::tstring& getNextSceneName() const;

private:
	std::tstring next_scene_name;
};

#endif
