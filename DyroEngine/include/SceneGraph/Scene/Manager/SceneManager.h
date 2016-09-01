#ifndef _SCENEMANAGER_H
#define _SCENEMANAGER_H

#include "Helpers/Manager.h"
#include "Interfaces\IDrawable.h"

#ifndef _VECTOR_
#include <vector>
#endif

#ifndef _STRING_H
	#include "Defines/string.h"
#endif

class Scene;
class Renderer;

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

	Scene* active_scene;
	std::vector<Scene*> vec_scenes;
};

#endif _SCENEMANAGER_H
