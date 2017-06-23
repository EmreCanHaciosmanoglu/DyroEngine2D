#ifndef _SYSTEM_H
#define _SYSTEM_H

#include "Core/Data/Objects/Message/Listener.h"

enum class SystemType;
enum class MessageType;

class System : public Listener
{
public:
	System(SystemType type);
	virtual ~System();

	virtual bool initialize() = 0;
	virtual void update() = 0;
	virtual bool shutdown() = 0;

	virtual void handleMessage(Message* message) = 0;
	virtual std::vector<MessageType> listenTo() const = 0;

	void activate();
	void deactivate();

	bool getIsActive() const;

	SystemType getType() const;

private:
	SystemType system_type;
	bool active;
};

#endif // _SYSTEM_H
