#ifndef _LOGIC_H
#define _LOGIC_H

#include "Core/System/Objects/System.h"

class Logic : public System
{
public:
	Logic();
	virtual ~Logic();

	virtual bool initialize();
	void update();
	virtual bool shutdown();

	virtual void handleMessage(Message* message);
	virtual std::vector<MessageType> listenTo() const;

private:
};

#endif