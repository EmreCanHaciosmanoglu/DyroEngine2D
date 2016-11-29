#ifndef _SCENEMANAGER_H
#define _SCENEMANAGER_H

#include "Helpers/Manager.h"
#include "Interfaces\IDrawable.h"

#ifndef _STRING_H
	#include "Defines/string.h"
#endif

#include "Diagnostics/Logger.h"

#include "Core/Rendering/Renderer.h"
#include "Core/Resources/Manager/ResourceManager.h"
#include "SceneGraph/Object/GameObjects/Camera/Manager/CameraManager.h"

#ifndef _VECTOR_
#include <vector>
#endif

class Scene;

class SceneManager : public Manager, public IDrawable
{
public:
	SceneManager();
	virtual ~SceneManager();

	virtual bool initialize();
	void update();
	virtual void draw();
	virtual bool shutdown();

	void addScene(Scene* scene);

	void setActiveScene(const std::tstring& name);
	Scene* getActiveScene() const;

private:
	template<typename T>
	void setupManager()
	{
		if (Singleton<T>::hasInstance())
		{
			Singleton<Logger>::getInstance().log(_T("Check if we can keep data that will be used in a different scene aswell, so not all data need to be unloaded."), LOGTYPE_TODO);
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
	std::vector<Scene*> vec_scenes;
};

#endif _SCENEMANAGER_H
