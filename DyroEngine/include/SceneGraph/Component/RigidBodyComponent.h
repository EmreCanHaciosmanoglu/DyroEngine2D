#ifndef _RIGIDBODYCOMPONENT_H
#define _RIGIDBODYCOMPONENT_H

#include "SceneGraph\Component\Component.h"

#ifndef _VECTOR2D_H
	#include "Helpers\Math\Vector2D.h"
#endif
#ifndef _BODYTYPE_H
	#include "Defines\Types\BodyType.h"
#endif

class b2Body;
class TransformComponent;

class RigidBodyComponent : public Component
{
public:
	RigidBodyComponent(BodyType bodyType, const std::tstring& name = _T(""));
	virtual ~RigidBodyComponent();

	virtual bool initialize();
	virtual void update();
	virtual bool shutdown();

	b2Body* getBody() const;

private:
	bool createBody(const Vector2D& position, const float angle);

	TransformComponent* transform;

	b2Body* body;
	BodyType body_type;
};

#endif