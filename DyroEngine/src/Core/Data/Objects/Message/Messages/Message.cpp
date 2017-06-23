#include "Core/Data/Objects/Message/Messages/Message.h"

Message::Message(MessageType type)
	:type(type)
{}
Message::~Message()
{}

MessageType Message::getMessageType() const
{
	return this->type;
}