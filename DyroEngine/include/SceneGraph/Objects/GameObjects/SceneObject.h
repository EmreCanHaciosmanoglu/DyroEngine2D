#ifndef _SCENEOBJECT_H
#define _SCENEOBJECT_H

#include "SceneGraph\Objects\GameObjects\GameObject.h"

#ifndef _IBOUNDINGBOX_H
#include "Core\Helpers\Interfaces\IBoundingBox.h"
#endif

class TransformComponent;
class VisualizationManager;

class SceneObject : public GameObject
{
	/**
	\note Must be present in every subclass definition.
	*/
	OBJECT_STATICS("SceneObject")

public:
	SceneObject(const std::tstring& name = _T(""));
	virtual ~SceneObject();

	virtual bool initialize();
	virtual void update();
	virtual bool shutdown();

	TransformComponent* getTransform() const;

private:
	TransformComponent* transform;
};

#endif