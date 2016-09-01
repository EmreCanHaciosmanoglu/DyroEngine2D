#ifndef _MAINTIMER_H
#define _MAINTIMER_H

#include "Core/System/System.h"

#ifndef _STRING_H
#include "Defines/string.h"
#endif

#ifndef _VECTOR_
#include <vector>
#endif

class Timer;

class MainTimer : public System
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

	static float delta_time;

private:
	Timer* world_timer;
	std::vector<Timer*> vec_timers;
};

#endif //_GAMETIMER_H