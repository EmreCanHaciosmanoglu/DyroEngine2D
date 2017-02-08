#ifndef _SCENEMANAGER_H
#define _SCENEMANAGER_H

#include "Core/Helpers/Patterns/Manager.h"
#include "Core/Helpers/Patterns/Singleton.h"

#ifndef _STRING_H
#include "Core/Defines/string.h"
#endif

#include "Core\Data\Manager\LayerManager.h"
#include "Core\Data\Manager\ResourceManager.h"
#include "Core\Data\Manager\GeometryManager.h"
#include "Core\Data\Manager\TimerManager.h"
#include "Rendering\Manager\TextureManager.h"
#include "SceneGraph\Manager\CameraManager.h"

#include "Core\Defines\debug.h"

#ifndef _VECTOR_
#include <vector>
#endif

#include "SceneGraph/Objects/Scenes/Scene.h"

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
	T* createManager()
	{
		T* manager = new T();
		manager->initialize();

		return manager;
	}

	Scene* active_scene;
};

#endif _SCENEMANAGER_H
