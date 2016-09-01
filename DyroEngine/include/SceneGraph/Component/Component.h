#ifndef _COMPONENT_H
#define _COMPONENT_H

#include "SceneGraph\Object.h"

#ifndef _STRING_H
#include "Defines\string.h"
#endif

class GameObject;

class Component : public Object
{
public:
	Component(const std::tstring& name = _T(""));
	virtual ~Component();

	virtual bool initialize() = 0;
	virtual void update() = 0;
	virtual bool shutdown() = 0;

	void setOrderValue(int value);
	int getOrderValue() const;

	void setParent(GameObject* parent);
	GameObject* getParent() const;

	static const int INVALID_ORDER_ID = -1;

private:
	GameObject* parent;

	int order_id;
};

#endif

