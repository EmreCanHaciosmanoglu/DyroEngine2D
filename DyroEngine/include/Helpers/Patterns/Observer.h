#ifndef _OBSERVER_H
#define _OBSERVER_H

#ifndef _VECTOR_
#include <vector>
#endif

template <typename T>
class Observer
{
public:
	Observer();
	virtual ~Observer();

	virtual void notify() = 0;
};

template <typename T>
Observer<T>::Observer()
{}
template <typename T>
Observer<T>::~Observer()
{}

template <typename T>
class Observee
{
public:
	Observee();
	virtual ~Observee();

	void addObserver(Observer<T>* observer);
	void removeObserver(Observer<T>* observer);

protected:
	std::vector<Observer<T>*>& getObservers();

	virtual void notifyObservers() = 0;

private:
	std::vector<Observer<T>*> vec_observers;
};

template <typename T>
Observee<T>::Observee()
{}
template <typename T>
Observee<T>::~Observee()
{
	vec_observers.clear();
}

template <typename T>
void Observee<T>::addObserver(Observer<T>* observer)
{
	assert(observer != nullptr);

	std::vector<Observer<T>*>::const_iterator it = std::find_if(this->vec_observers.begin(), this->vec_observers.end(),
		[observer](Observer<T>* o)
	{
		return o == observer;
	});

	if (it != this->vec_observers.end())
		return;

	this->vec_observers.push_back(observer);
}
template <typename T>
void Observee<T>::removeObserver(Observer<T>* observer)
{
	std::vector<Observer<T>*>::const_iterator it = std::find_if(this->vec_observers.begin(), this->vec_observers.end(),
		[observer](Observer<T>* o)
	{
		return o == observer;
	});

	if (it == this->vec_observers.end())
		return;

	this->vec_observers.erase(it);
}

template <typename T>
std::vector<Observer<T>*>& Observee<T>::getObservers()
{
	return this->vec_observers;
}

#endif