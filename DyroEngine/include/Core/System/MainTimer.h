#ifndef _MAINTIMER_H
#define _MAINTIMER_H

#include "Core/System/System.h"
#include "Helpers\Manager.h"

#ifndef _STRING_H
#include "Defines/string.h"
#endif

class Timer;

class MainTimer : public System, public Manager<Timer>
{
public:
	MainTimer();
	virtual ~MainTimer();

	virtual bool initialize();
	virtual void update();
	virtual bool shutdown();

	Timer* getWorldTimer() const;

	void addTimer(Timer* timer);
	Timer* getTimer(const std::tstring& name) const;

	static double delta_time;

private:
	Timer* world_timer;
};

#endif //_GAMETIMER_H