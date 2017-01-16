#ifndef _SCENEMANAGER_H
#define _SCENEMANAGER_H

#include "Core/Helpers/Patterns/Manager.h"
#include "Core/Helpers/Patterns/Singleton.h"

#ifndef _STRING_H
#include "Core/Defines/string.h"
#endif

#include "Core\Data\Manager\LayerManager.h"
#include "Core\Data\Manager\ResourceManager.h"
#include "SceneGraph\Manager\CameraManager.h"

#include "Core\Defines\debug.h"

#ifndef _VECTOR_
#include <vector>
#endif

class Scene;

class SceneManager : public Manager<Scene>, public Singleton<SceneManager>
{
public:
	SceneManager();
	virtual ~SceneManager();

	virtual bool initialize();
	void update();
	virtual bool shutdown();

	void addScene(Scene* scene);

	void setActiveScene(unsigned int id);
	void setActiveScene(const std::tstring& name);

	Scene* getActiveScene() const;

private:
	template<typename T>
	void setupManager()
	{
		if (Singleton<T>::hasInstance())
		{
			LogManager::getInstance().log(new InfoLog(_T("Check if we can keep data that will be used in a different scene aswell, so not all data need to be unloaded."), LOG_INFO));
			Singleton<T>::getInstance().shutdown();
		}
		else Singleton<T>::createInstance();

		Singleton<T>::getInstance().initialize();
	}
	template<typename T>
	void destroyManager()
	{
		Singleton<T>::getInstance().shutdown();
		Singleton<T>::destroyInstance();
	}

	Scene* active_scene;
};

#endif _SCENEMANAGER_H
