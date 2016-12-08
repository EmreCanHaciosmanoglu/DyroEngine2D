#ifndef _TIMER_H
#define _TIMER_H

#include "SceneGraph\Object.h"

#ifndef _CTIME_
#include <ctime>
#endif


class Timer : public Object
{
public:

	Timer(const std::tstring& name);
	virtual ~Timer();

	virtual bool initialize();
	virtual bool postInitialize();
	void update();
	virtual bool shutdown();

	double getTotalTime() const;		//in seconds
	double getDeltaTime() const;		//in seconds

	void start();

	void pause();
	void unpause();

	void reset();
private:

	double delta_time;

	double current_time;
	double previous_time;

	std::clock_t timer_begin;
	std::clock_t timer_stop;

	bool paused;
};

#endif //_GAMETIMER_H