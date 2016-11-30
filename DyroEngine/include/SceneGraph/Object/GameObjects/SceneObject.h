#ifndef _SCENEOBJECT_H
#define _SCENEOBJECT_H

#include "SceneGraph\Object\GameObjects\GameObject.h"
#include "Interfaces\IDrawable.h"
#include "Interfaces\IBoundingBox.h"

class TransformComponent;

class SceneObject :	public GameObject, public IDrawable, public IBoundingBox
{
public:
	SceneObject(const std::tstring& name = _T(""));
	virtual ~SceneObject();

	virtual bool initialize();
	virtual void update();
	virtual void draw();
	virtual bool shutdown();

	TransformComponent* getTransform() const;

	Rect2D getBoundingBox() const;

private:
	TransformComponent* transform;
};

#endif