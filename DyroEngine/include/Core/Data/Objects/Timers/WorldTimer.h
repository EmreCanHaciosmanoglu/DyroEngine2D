#ifndef _WORLDTIMER_H
#define _WORLDTIMER_H

#include "Core\Data\Objects\Timers\Timer.h"

class WorldTimer : public Timer
{
public:
	WorldTimer();
	virtual ~WorldTimer();

	virtual void start();
	virtual void update();

	static float getWorldDeltaTime();
	static float getWorldTotalTime();

private:
	static float world_delta_time;
	static float world_total_time;
};

#endif