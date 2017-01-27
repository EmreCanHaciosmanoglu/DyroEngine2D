#include "Core\Data\Manager\TransitionManager.h"

#include "Core/Defines/deletemacros.h"

#include <algorithm>

TransitionManager::TransitionManager()
{}
TransitionManager::~TransitionManager()
{}

bool TransitionManager::initialize()
{
	return true;
}
void TransitionManager::update()
{
	std::vector<AbstractTrasition*> to_remove;

	std::vector<AbstractTrasition*> transitions;
	getObjects(transitions);

	for (AbstractTrasition* t : transitions)
	{
		t->update();
		if (t->isFinished() && t->canDestroy())
			to_remove.push_back(t);
	}

	for (AbstractTrasition* t : to_remove)
		removeObject(t);
}
bool TransitionManager::shutdown()
{
	std::vector<AbstractTrasition*> transitions;
	getObjects(transitions);
	for (AbstractTrasition* t : transitions)
		delete t;

	return true;
}

void TransitionManager::addTransition(AbstractTrasition* t)
{
	addObject(t->getID(), t);
}

void TransitionManager::removeTransition(AbstractTrasition* t)
{
	removeObject(t);
}
void TransitionManager::removeTransition(int id)
{
	removeObject(id);
}
void TransitionManager::removeTransition(const std::tstring& name)
{
	std::vector<AbstractTrasition*> transitions;
	getObjects(transitions);

	std::vector<AbstractTrasition*>::const_iterator it = std::find_if(transitions.begin(), transitions.end(), 
		[name](AbstractTrasition* t) -> bool
	{
		return name == t->getName();
	});

	removeObject(*it);
}