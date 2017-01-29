#ifndef _TRANSITION_H
#define _TRANSITION_H

class AbstractTrasition
{
public:
	AbstractTrasition()
		: running(false)
		, finished(false)
	{}
	virtual ~AbstractTrasition()
	{}

	AbstractTrasition(const AbstractTrasition& t)
		:running(t.isRunning())
		,finished(t.isFinished())
	{}


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

protected:
	void setFinished(bool f)
	{
		this->finished = f;
	}

private:
	bool running;
	bool finished;
};

template <typename T>
class Transition : public AbstractTrasition
{
public:
	Transition(T from, T to)
		:AbstractTrasition()

		,from(from)
		,to(to)
		,speed()
	{
		current = from;
	}
	~Transition()
	{}

	Transition(const Transition<T>& t)
		:AbstractTrasition(t)
		,from(t.from)
		,to(t.to)
		,current(t.current)
		,speed(t.speed)
	{}

	void setSource(T from)
	{
		this->from = from;
	}
	void setDestination(T to)
	{
		this->to = to;
	}

	void reset()
	{
		from = 0;
		setFinished(false);
	}
	void update()
	{
		if (!isRunning())
			return;

		if(to - current >= (T)0)
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