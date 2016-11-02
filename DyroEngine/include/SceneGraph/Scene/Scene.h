#ifndef _SCENE_H
#define _SCENE_H

#include "SceneGraph/Object.h"
#include "Interfaces\IDrawable.h"
#include "Interfaces\IInput.h"

#ifndef _VECTOR_
#include <vector>
#endif
#ifndef _STRING_H
#include "Defines\string.h"
#endif

class GameObject;
class Renderer;
class CameraManager;
class ResourceManager;
class Input;

class Scene : public Object, public IDrawable, public IInput
{
public:
	Scene(const std::tstring& name);
	virtual ~Scene();

	virtual bool initialize();
	virtual void update();
	virtual void draw();
	virtual bool shutdown();

	virtual void setupInput(Input* input);

	virtual void activate();
	virtual void deactive();

	virtual void destroy();

	void addGameObject(GameObject* object);
	void removeGameObject(GameObject* object);

	void setRenderer(Renderer* renderer);
	Renderer* getRenderer() const;
	void setCameraManager(CameraManager* manager);
	CameraManager* getCameraManager() const;
	void setResourceManager(ResourceManager* manager);
	ResourceManager* getResourceManager() const;

private:

	Renderer* renderer;
	CameraManager* camera_manager;
	ResourceManager* resource_manager;
	std::vector<GameObject*> vec_objects;
};

#endif //_SCENE_H

