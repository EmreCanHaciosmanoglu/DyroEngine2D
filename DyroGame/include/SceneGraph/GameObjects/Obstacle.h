#ifndef _OBSTACLE_H
#define _OBSTACLE_H

#include "SceneGraph/GameObjects/PhysicsObject.h"

class Obstacle : public PhysicsObject
{
public:
	Obstacle(BodyType bodyType, const std::tstring& name = _T(""));
	virtual ~Obstacle();

	virtual bool initialize();
	virtual void update();
	virtual bool shutdown();

	void setVisible(bool visible);
	bool getVisible() const;

private:
};

#endif