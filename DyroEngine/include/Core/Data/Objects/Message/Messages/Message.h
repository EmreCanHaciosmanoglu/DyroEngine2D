#ifndef _MESSAGE_H
#define _MESSAGE_H

enum class MessageType;

class Message
{
public:
	Message(MessageType type);
	virtual ~Message();

	MessageType getMessageType() const;

private:
	MessageType type;
};

#endif