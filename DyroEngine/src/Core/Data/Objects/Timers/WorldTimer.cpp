#include "Core\Data\Objects\Timers\WorldTimer.h"

float WorldTimer::world_delta_time = Timer::FRAME_SPEED;
float WorldTimer::world_total_time = 0.0f;

WorldTimer::WorldTimer()
	:Timer(_T("World Timer"))
{}
WorldTimer::~WorldTimer()
{}

void WorldTimer::start()
{
	Timer::start();
}
void WorldTimer::update()
{
	WorldTimer::world_delta_time = (float)getDeltaTime();
	WorldTimer::world_total_time = (float)getTotalTime();

	Timer::update();
}

float WorldTimer::getWorldDeltaTime()
{
	return WorldTimer::world_delta_time;
}
float WorldTimer::getWorldTotalTime()
{
	return WorldTimer::world_total_time;
}