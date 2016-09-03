#ifndef _SCENE_H
#define _SCENE_H

#include "SceneGraph/Object.h"
#include "Interfaces\IDrawable.h"

#ifndef _VECTOR_
#include <vector>
#endif
#ifndef _STRING_H
#include "Defines\string.h"
#endif

class GameObject;
class Renderer;

class Scene : public Object, public IDrawable
{
public:
	Scene(const std::tstring& name);
	virtual ~Scene();

	virtual bool initialize();
	virtual void update();
	virtual void draw();
	virtual bool shutdown();

	virtual void activate();
	virtual void deactive();

	virtual void destroy();

	void setRenderer(Renderer* renderer);
	Renderer* getRenderer() const;

private:
	Renderer* renderer;
};

#endif //_SCENE_H

