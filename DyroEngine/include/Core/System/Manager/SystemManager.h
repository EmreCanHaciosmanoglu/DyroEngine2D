#ifndef _SYSTEMMANAGER_H
#define _SYSTEMMANAGER_H

#include "Core/Helpers/Patterns/Manager.h"
#include "Core/Helpers/Patterns/Singleton.h"

#include "Core/System/Objects/System.h"
#include "Core/System/Factory/SystemFactory.h"

enum class SystemType;

class SystemManager : public Manager<System>, public Singleton<SystemManager>
{
public:
	SystemManager();
	virtual ~SystemManager();

	virtual bool initialize();
	virtual bool shutdown();

	bool addSystem(SystemType type);

	template <typename T>
	T* getSystem();
	void getSystems(std::vector<System*>& systems);

private:
	SystemFactory factory;
};

template <typename T>
T* SystemManager::getSystem()
{
	std::vector<System*> systems;
	getSystems(systems);

	for (System* s : systems)
	{
		T* concrete_system = dynamic_cast<T*>(s);
		if (concrete_system != nullptr)
			return concrete_system;
	}

	return nullptr;
}

#endif //_SYSTEMMANAGER
