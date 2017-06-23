#include "Core/Data/Manager/MessageManager.h"
#include "Core/Data/Objects/Message/Messages/Message.h"

MessageManager::MessageManager()
{}
MessageManager::~MessageManager()
{}

bool MessageManager::initialize()
{
	return true;
}
void MessageManager::update()
{
	if ((unsigned int)this->queued_messages.size() == 0)
		return;

	for (Message* message : this->queued_messages)
		sendMessage(message);

	this->queued_messages.clear();
}
bool MessageManager::shutdown()
{
	this->queued_messages.clear();

	return true;
}

void MessageManager::subscribeListener(Listener* listener)
{
	addObject(listener->getListenerID(), listener);
}

void MessageManager::unsubscribeListener(unsigned int listenerID)
{
	removeObject(listenerID);
}
void MessageManager::unsubscribeListener(Listener* listener)
{
	removeObject(listener);
}

void MessageManager::sendMessage(Message* message)
{
	std::vector<Listener*> listeners;
	getObjects(listeners);

	for (Listener* listener : listeners)
	{
		if (listenTo(listener, message->getMessageType()))
			listener->handleMessage(message);
	}

	delete message;
}
void MessageManager::queueMessage(Message* message)
{
	this->queued_messages.push_back(message);
}

bool MessageManager::listenTo(Listener* listener, MessageType type)
{
	if ((unsigned int)listener->listenTo().size() == 0)
		return false;

	std::vector<MessageType> types = listener->listenTo();
	return std::find(types.begin(), types.end(), type) != types.end();

}