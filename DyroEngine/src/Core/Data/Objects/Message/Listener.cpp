#include "Core/Data/Objects/Message/Listener.h"

Listener::Listener()
	:listener_id(ObjectCounter<Listener>::getAmount())
{}
Listener::~Listener()
{}

unsigned int Listener::getListenerID() const
{
	return this->listener_id;
}