#ifndef _TIMERMANAGER_H
#define _TIMERMANAGER_H

#include "Core/Helpers/Patterns/Singleton.h"
#include "Core/Helpers/Patterns/Manager.h"

class Timer;
class WorldTimer;

class TimerManager : public Manager<Timer>, public Singleton<TimerManager>
{
public:
	TimerManager();
	virtual ~TimerManager();

	virtual bool initialize();
	void update();
	virtual bool shutdown();

	void addTimer(Timer* timer);

	void setWorldTimer(WorldTimer* timer);
	WorldTimer* getWorldTimer();

	Timer* getTimer(const std::tstring& name);
	Timer* getTimer(unsigned int id);

	void removeTimer(const std::tstring& name);
	void removeTimer(unsigned int id);
	void removeTimer(Timer* timer);

private:
	WorldTimer* world_timer;
};

#endif