#ifndef _UIOBJECT_H
#define _UIOBJECT_H

#include "SceneGraph/GameObjects/GameObject.h"

class TransformComponent;

class UIObject : public GameObject
{
	/**
	\note Must be present in every subclass definition.
	*/
	OBJECT_STATICS("UIObject")

public:
	UIObject(const std::tstring& name = _T(""));
	virtual ~UIObject();

	virtual bool initialize();
	virtual void upddate();
	virtual bool shutdown();

	TransformComponent* getTransform() const;

private:
	TransformComponent* transform;
};

#endif