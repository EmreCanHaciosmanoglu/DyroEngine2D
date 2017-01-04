#include "Core\Data\Manager\TimerManager.h"

#include "Core\Data\Objects\Timers\Timer.h"
#include "Core\Data\Objects\Timers\WorldTimer.h"

TimerManager::TimerManager()
	:Manager<Timer>()
	, world_timer(nullptr)
{}
TimerManager::~TimerManager()
{}

bool TimerManager::initialize()
{
	setWorldTimer(new WorldTimer());

	return true;
}
void TimerManager::update()
{
	std::map<unsigned int, Timer*> timers = getObjects();
	for (const std::pair<unsigned int, Timer*>& pair : timers)
		pair.second->update();
}
bool TimerManager::shutdown()
{
	std::vector<Timer*> timers;
	getObjects(timers);

	for (Timer* timer : timers)
		delete timer;

	this->world_timer = nullptr;

	return true;
}

void TimerManager::addTimer(Timer* timer)
{
	addObject(timer->getID(), timer);
}

void TimerManager::setWorldTimer(WorldTimer* timer)
{
	this->world_timer = timer;
}
WorldTimer* TimerManager::getWorldTimer()
{
	return this->world_timer;
}

Timer* TimerManager::getTimer(const std::tstring& name)
{
	std::vector<Timer*> timers;
	getObjects(timers);

	std::vector<Timer*>::const_iterator it = std::find_if(timers.begin(), timers.end(),
		[name](Timer* timer) -> bool
	{
		return timer->getName() == name;
	});

	return *it;
}
Timer* TimerManager::getTimer(unsigned int id)
{
	return getObject(id);
}

void TimerManager::removeTimer(const std::tstring& name)
{
	std::vector<Timer*> timers;
	getObjects(timers);

	std::vector<Timer*>::const_iterator it = std::find_if(timers.begin(), timers.end(),
		[name](Timer* timer) -> bool
	{
		return timer->getName() == name;
	});

	if (it == timers.end())
		return;

	removeObject((*it)->getID());
}
void TimerManager::removeTimer(unsigned int id)
{
	removeObject(id);
}
void TimerManager::removeTimer(Timer* timer)
{
	removeObject(timer);
}