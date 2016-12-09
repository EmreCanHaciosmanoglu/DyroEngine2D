#ifndef _ASTROID_H
#define _ASTROID_H

#include "SceneGraph\GameObjects\Obstacle.h"

#ifndef _VECTOR2D_H
#include "Helpers\Math\Vector2D.h"
#endif

class Astroid : public Obstacle
{
public:
	Astroid(float radius);
	virtual ~Astroid();

	virtual bool initialize();
	virtual bool postInitialize();
	virtual void update();
	virtual bool shutdown();

	void setDirection(const Vector2D& direction);

private:
	void generateVertices(std::vector<Vector2D>& vertices);

	float radius;
	Vector2D direction;
};

#endif