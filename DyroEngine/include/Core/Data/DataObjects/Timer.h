#ifndef _TIMER_H
#define _TIMER_H

#include "Helpers/ObjectCounter.h"

#ifndef _STRING_H
#include "Defines/string.h"
#endif

#ifndef _CTIME_
#include <ctime>
#endif

class Timer : public ObjectCounter<Timer>
{
public:

	Timer(const std::tstring& name);
	virtual ~Timer();

	unsigned int getTimerID();

	void setName(const std::tstring& name);
	const std::tstring& getName() const;

	double getTotalTime() const;		//in seconds
	double getDeltaTime() const;		//in seconds

	void start();
	void update(); 

	void pause();
	void unpause();

	void reset();
private:
	unsigned int id;
	std::tstring name;

	double delta_time;

	double current_time;
	double previous_time;

	std::clock_t timer_begin;
	std::clock_t timer_stop;

	bool paused;
};

#endif //_GAMETIMER_H