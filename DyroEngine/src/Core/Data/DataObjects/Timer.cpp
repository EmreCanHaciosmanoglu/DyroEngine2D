#include "Core\Data\DataObjects\Timer.h"

//Additional Include Files
#ifndef _WINDOWS_
#include <Windows.h>
#endif

#include "Helpers\Singleton.h"

#include "Diagnostics\Logger.h"


//Class GameTimer
Timer::Timer(const std::tstring& name)
	:DataObject(name)
	, delta_time(-1.0)
	, current_time(0)
	, previous_time(0)
{
	this->timer_begin = clock();
}
Timer::~Timer()
{
}

double Timer::getTotalTime()const
{
	std::clock_t timer_end = clock();

	return double(timer_end - this->timer_begin) / CLOCKS_PER_SEC;
}
double Timer::getDeltaTime()const
{
	return this->delta_time;
}

void Timer::reset()
{
	this->timer_begin = clock();

	this->previous_time = getTotalTime();
	this->current_time = 0;
}

void Timer::start()
{
	this->previous_time = getTotalTime();
}

void Timer::pause()
{
	this->paused = true;
	Singleton<Logger>::getInstance().log(_T("Implement timer pause"), LOGTYPE_TODO);
}
void Timer::unpause()
{
	this->paused = false;
	Singleton<Logger>::getInstance().log(_T("Implement timer unpause"), LOGTYPE_TODO);
}

bool Timer::initialize()
{
	start();
	return true;
}
bool Timer::postInitialize()
{
	return true;
}
void Timer::update()
{

	this->previous_time = this->current_time;
	this->current_time = getTotalTime();

	this->delta_time = this->current_time - this->previous_time;

	//Force nonnegative,
	//the DXSKS's CDXUTTimer metions that if the processor goes into power save mode or we get shuffled to another processor,
	//then this->delta_time can be negative.
	if (this->delta_time < 0.0)
		this->delta_time = 0.0;
}
bool Timer::shutdown()
{
	return true;
}