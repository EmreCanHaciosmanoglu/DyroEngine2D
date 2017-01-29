#ifndef _TIMER_H
#define _TIMER_H

#include "Core/Helpers/TaggedObject.h"
#ifndef _STRING_H
#include "Core/Defines/string.h"
#endif

#ifndef _CTIME_
#include <ctime>
#endif

class Timer : public TaggedObject<Timer>
{
public:
	Timer(const std::tstring& name);
	virtual ~Timer();

	double getTotalTime() const;		//in seconds
	double getDeltaTime() const;		//in seconds

	virtual void start();
	virtual void update();

	void pause();
	void unpause();

	void reset();
protected:
	static const float FRAME_SPEED;

private:
	double delta_time;

	double current_time;
	double previous_time;

	std::clock_t timer_begin;
	std::clock_t timer_stop;

	bool paused;
};

#endif //_TIMER_H