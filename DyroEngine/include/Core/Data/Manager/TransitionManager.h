#ifndef _TRANSITIONMANAGER_H
#define _TRANSITIONMANAGER_H

#include "Core/Helpers/Patterns/Manager.h"
#include "Core/Helpers/Patterns/Singleton.h"

#ifndef _TRANSITION_H
#include "Core/Data/Objects/Transition.h"
#endif
#ifndef _STRING_H
#include "Core/Defines/string.h"
#endif

class TransitionManager : public Manager<AbstractTrasition> , public Singleton<TransitionManager>
{
public:
	TransitionManager();
	virtual ~TransitionManager();

	bool initialize();
	void update();
	bool shutdown();

	void addTransition(AbstractTrasition* t);

	void removeTransition(AbstractTrasition* t);
	void removeTransition(int id);
	void removeTransition(const std::tstring& name);

	template <typename T>
	Transition<T>* getTransition(int id);
	template <typename T>
	Transition<T>* getTransition(const std::tstring& name);
};

template <typename T>
Transition<T>* TransitionManager::getTransition(int id)
{

}
template <typename T>
Transition<T>* TransitionManager::getTransition(const std::tstring& name)
{

}

#endif