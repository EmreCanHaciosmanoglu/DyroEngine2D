#include "Core/System/MainTimer.h"

#include "SceneGraph/Object/Objects/Timer.h"

#include "Defines/Types/SystemType.h"
#include "Defines/deletemacros.h"

#include <algorithm>

double MainTimer::delta_time = 0.0f;

MainTimer::MainTimer()
	:System(SystemType::TIMER_SYSTEM)
{
}
MainTimer::~MainTimer()
{
}

bool MainTimer::initialize()
{
	this->world_timer = new Timer(_T("WorldTimer"));

	if (!this->world_timer->initialize())
		return false;
	this->world_timer->setInitialized();

	return true;
}
void MainTimer::update()
{
	if (!getIsActive())
		return;

	this->world_timer->update();
	this->delta_time = this->world_timer->getDeltaTime();

	for (Timer* t : this->vec_timers)
		t->update();
}
bool MainTimer::shutdown()
{
	SafeDelete(this->world_timer);

	for (Timer* t : this->vec_timers)
	{
		if (!t->shutdown())
			return false;

		SafeDelete(t);
	}

	return true;
}

Timer* MainTimer::getWorldTimer() const
{
	return this->world_timer;
}

void MainTimer::addTimer(Timer* timer)
{
	std::vector<Timer*>::const_iterator it = std::find(this->vec_timers.begin(), this->vec_timers.end(), timer);
	if (it != this->vec_timers.end())
		return;

	this->vec_timers.push_back(timer);
}
Timer* MainTimer::getTimer(const std::tstring& name) const
{
	std::vector<Timer*>::const_iterator it = std::find_if(this->vec_timers.begin(),this->vec_timers.end(),
		[name](Timer* timer)
	{
		return timer->getName() == name;
	});

	if (it != this->vec_timers.end())
		return *it;

	return nullptr;
}