#ifndef _TIMER_H
#define _TIMER_H

#include "SceneGraph\Object.h"

class Timer : public Object
{
public:

	Timer(const std::tstring& name);
	virtual ~Timer();

	virtual bool initialize();
	void update();
	virtual bool shutdown();

	float getTotalTime() const;		//in seconds
	float getDeltaTime() const;		//in seconds

	void reset();
private:

	void start();
	void stop();

	double secondspercount;
	double delta_time;

	_int64 base_time;
	_int64 pause_time;
	_int64 stop_time;
	_int64 prev_time;
	_int64 curr_time;

	bool stopped;
};

#endif //_GAMETIMER_H