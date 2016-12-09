#ifndef _COMPONENT_H
#define _COMPONENT_H

#include "SceneGraph\Object.h"

#ifndef _STRING_H
#include "Defines\string.h"
#endif

class GameObject;
class DataObjectManager;

class Component : public Object
{
public:
	Component(const std::tstring& name = _T(""));
	virtual ~Component();

	virtual bool initialize() = 0;
	virtual bool postInitialize();
	virtual void update();
	virtual bool shutdown() = 0;

	void setExecutionOrder(int value);
	int getExecutionOrder() const;

	void setParent(GameObject* parent);
	GameObject* getParent() const;

	void setDataObjectManager(DataObjectManager* manager);
	DataObjectManager* getDataObjectManager() const;

	static const int INVALID_ORDER_ID = -1;

private:
	GameObject* parent;
	DataObjectManager* manager;

	int execution_order;
};

#endif

