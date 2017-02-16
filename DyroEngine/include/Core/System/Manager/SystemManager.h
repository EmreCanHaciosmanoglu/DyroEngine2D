#ifndef _SYSTEMMANAGER_H
#define _SYSTEMMANAGER_H

#include "Core/Helpers/Patterns/Manager.h"
#include "Core/Helpers/Patterns/Singleton.h"

#ifndef _VECTOR_
#include <vector>
#endif

#ifndef _SYSTEM_H
#include "Core\System\Objects\System.h"
#endif
#ifndef _SYSTEMTYPE_H
#include "Core/Types/SystemType.h"
#endif

class SystemFactory;

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
	SystemFactory* factory;
};

template <typename T>
T* SystemManager::getSystem()
{
	std::vector<System*> systems;
	getSystems(systems);

	for (System* s : systems)
	{
		T* concrete_system = dynamic_cast<T*>(s);
		if (s != nullptr)
			return concrete_system;
	}

	return nullptr;
}

#endif //_SYSTEMMANAGER
