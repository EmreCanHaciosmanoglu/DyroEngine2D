#include "SceneGraph\Object\Objects\Timer.h"

//Additional Include Files
#ifndef _WINDOWS_
#include <Windows.h>
#endif

#ifndef _CTIME_
#include <ctime>
#endif

//Class GameTimer
Timer::Timer(const std::tstring& name)
	:Object(name)
	, secondspercount(0.0)
	, delta_time(-1.0)

	, base_time(0)
	, pause_time(0)
	, prev_time(0)
	, curr_time(0)

	, stopped(false)
{
	_int64 countpersec;
	QueryPerformanceFrequency((LARGE_INTEGER*)&countpersec);
	this->secondspercount = 1.0 / (double)countpersec;
}
Timer::~Timer()
{
}

float Timer::getTotalTime()const
{
	if (this->stopped)
		return (float)((this->stop_time - this->base_time)*this->secondspercount);

	else return (float)(((this->curr_time - this->pause_time) - this->base_time)*this->secondspercount);
}
float Timer::getDeltaTime()const
{
	return (float)this->delta_time;
}

void Timer::reset()
{
	_int64 currTime;
	QueryPerformanceCounter((LARGE_INTEGER*)&currTime);

	this->base_time = currTime;
	this->prev_time = currTime;
	this->stop_time = 0;

	this->stopped = false;
}

void Timer::start()
{
	_int64 startTime;
	QueryPerformanceCounter((LARGE_INTEGER*)&startTime);
	this->prev_time = startTime;

	//if we are resuming tje timer from a stopped state ...
	if (this->stopped)
	{
		//then accumulate the paused time.
		this->pause_time += (startTime - this->stop_time);

		//Since we are starting the timer back up,
		//the current previous time is not valid,
		//as it occurred while paused.
		//So reset it to the current time.
		this->prev_time = startTime;

		//no longer stopped ...
		this->stop_time = 0;
		this->stopped = false;
	}
}
void Timer::stop()
{
	//if we are already stopped, then don't do anything
	if (!this->stopped)
	{
		_int64 currTime;
		QueryPerformanceCounter((LARGE_INTEGER*)&currTime);

		//Save the time we stopped at,
		//and set the boolean flag indiacting the timer stopped.
		this->stop_time = currTime;
		this->stopped = true;
	}
}

bool Timer::initialize()
{
	start();
	return true;
}
void Timer::update()
{
	if (this->stopped)
	{
		this->delta_time = 0.0;
	}

	//get the time this frame
	_int64 currTime;
	QueryPerformanceCounter((LARGE_INTEGER*)&currTime);
	this->curr_time = currTime;

	//Time diffrence between this frame and previous
	this->delta_time = (this->curr_time - this->prev_time)*this->secondspercount;

	//Prepare for next frame
	this->prev_time = this->curr_time;

	//Force nonnegative,
	//the DXSKS's CDXUTTimer metions that if the processor goes into power save mode or we get shuffled to another processor,
	//then this->delta_time can be negative.
	if (this->delta_time < 0.0)
		this->delta_time = 0.0;
}
bool Timer::shutdown()
{
	stop();
	return true;
}