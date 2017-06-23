#ifndef _LISTENER_H
#define _LISTENER_H

#include "Core\Helpers\ObjectCounter.h"

#ifndef _VECTOR_
#include <vector>
#endif

class Message;
enum class MessageType;

class Listener : public ObjectCounter<Listener>
{
public:
	virtual ~Listener();

	virtual void handleMessage(Message* message) = 0;
	virtual std::vector<MessageType> listenTo() const = 0;

	unsigned int getListenerID() const;

protected:
	unsigned int listener_id;

	Listener();
};

#endif
