#ifndef _UIOBJECT_H
#define _UIOBJECT_H

#include "SceneGraph/Objects/GameObjects/SceneObject.h"

class UIObject : public SceneObject
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
};

#endif