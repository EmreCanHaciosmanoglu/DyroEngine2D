#ifndef _TRANSITION_H
#define _TRANSITION_H

#ifndef _TAGGEDOBJECT_H
#include "Core/Helpers/TaggedObject.h"
#endif

class AbstractTrasition : public TaggedObject<AbstractTrasition>
{
public:
	AbstractTrasition(const std::tstring& name)
		:TaggedObject(name)

		, running(false)
		, finished(false)
		, destroy_on_finish(true)
	{}
	virtual ~AbstractTrasition(){}


	void start()
	{
		this->running = true;
	}
	void stop()
	{
		this->running = false;
	}

	virtual void update() = 0;

	bool isRunning() const
	{
		return this->running;
	}
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
	bool running;
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
	{
		current = from;
	}
	~Transition()
	{}

	void reset()
	{
		from = 0;
		setFinished(false);
	}
	void update()
	{
		if (!isRunning())
			return;

		if(to - current > (T)0)
			current += speed;
		else setFinished(true);
	}

	void setSpeed(T speed)
	{
		this->speed = speed;
	}
	const T& getSpeed() const
	{
		return this->speed;
	}

	T getValue() const
	{
		return current;
	}

private:
	T from;
	T to;

	T current;

	T speed;
};

#endif