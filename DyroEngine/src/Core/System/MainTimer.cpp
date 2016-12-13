#include "Core/System/MainTimer.h"

#include "Core/Data/Timer.h"

#include "Defines/Types/SystemType.h"
#include "Defines/deletemacros.h"

#include <algorithm>
#include <vector>

double MainTimer::delta_time = 0.0f;

MainTimer::MainTimer()
	:System(SystemType::TIMER_SYSTEM)
	, world_timer(nullptr)
{
}
MainTimer::~MainTimer()
{
}

bool MainTimer::initialize()
{
	this->world_timer = new Timer(_T("WorldTimer"));

	return true;
}
void MainTimer::update()
{
	if (!getIsActive())
		return;

	this->world_timer->update();
	this->delta_time = this->world_timer->getDeltaTime();

	std::vector<Timer*> timers;
	getObjects(timers);

	for (Timer* t : timers)
		t->update();
}
bool MainTimer::shutdown()
{
	SafeDelete(this->world_timer);

	std::vector<Timer*> timers;
	getObjects(timers);

	for (Timer* t : timers)
		SafeDelete(t);

	return true;
}

Timer* MainTimer::getWorldTimer() const
{
	return this->world_timer;
}

void MainTimer::addTimer(Timer* timer)
{
	addObject(timer->getID(), timer);
}
Timer* MainTimer::getTimer(const std::tstring& name) const
{
	std::vector<Timer*> timers;
	getObjects(timers);

	std::vector<Timer*>::const_iterator it = std::find_if(timers.begin(), timers.end(),
		[name](Timer* timer)
	{
		return timer->getName() == name;
	});

	if (it == timers.end())
		return nullptr;

	return (*it);
}