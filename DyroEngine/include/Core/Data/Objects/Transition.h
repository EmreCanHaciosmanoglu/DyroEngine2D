#ifndef _TRANSITION_H
#define _TRANSITION_H

#ifndef _WORLDTIMER_H
#include "Core/Data/Objects/Timers/WorldTimer.h"
#endif
#ifndef _TAGGEDOBJECT_H
#include "Core/Helpers/TaggedObject.h"
#endif

class AbstractTrasition : public TaggedObject<AbstractTrasition>
{
public:
	AbstractTrasition(const std::tstring& name)
		:TaggedObject(name)

		, finished(false)
		, destroy_on_finish(true)
	{}
	virtual ~AbstractTrasition(){}

	virtual void update() = 0;

	bool isFinished() const
	{
		return this->finished;
	}

	void destroyOnFinish(bool destroy)
	{
		this->destroy_on_finish = destroy;
	}
	bool canDestroy() const
	{
		return this->destroy_on_finish;
	}
protected:
	void setFinished(bool f)
	{
		this->finished = f;
	}

private:
	bool finished;
	bool destroy_on_finish;
};

template <typename T>
class Transition : public AbstractTrasition
{
public:
	Transition(T from, T to, const std::tstring& name)
		:AbstractTrasition(name)

		,from(from)
		,to(to)
		,speed()
	{}
	~Transition()
	{}

	void reset()
	{
		from = 0;
		setFinished(false);
	}
	void update()
	{
		if(to - from > 0)
			from += speed * WorldTimer::getWorldDeltaTime();
		else setFinished(true)
	}

	void setSpeed(T speed)
	{
		this->speed = speed;
	}
	const T& getSpeed() const
	{
		return this->speed;
	}

private:
	T from;
	T to;

	T speed;
};

#endif