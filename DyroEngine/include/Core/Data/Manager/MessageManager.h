#ifndef _MESSAGEMANAGER_H
#define _MESSAGEMANAGER_H

#include "Core/Helpers/Patterns/Manager.h"
#include "Core/Helpers/Patterns/Singleton.h"
#include "Core/Data/Objects/Message/Listener.h"

class Message;

class MessageManager : public Manager<Listener> , public Singleton<MessageManager>
{
public:
	MessageManager();
	virtual ~MessageManager();

	virtual bool initialize();
	void update();
	virtual bool shutdown();

	void subscribeListener(Listener* listener);

	void unsubscribeListener(unsigned int id);
	void unsubscribeListener(Listener* listener);

	void sendMessage(Message* message);
	void queueMessage(Message* message);

private:
	bool listenTo(Listener* listener, MessageType type);

	std::vector<Message*> queued_messages;
};

#endif
