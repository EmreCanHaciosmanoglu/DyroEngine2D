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

	void setGravityScale(float scale);
	float getGravityScale() const;

	void setLinearDamping(float damping);
	float getLinearDamping() const;
	void setAngularDamping(float damping);
	float getAngularDamping() const;

	void setLinearVelocity(const Vector2D& velocity);
	Vector2D getLinearVelocity() const;
	void setAngularVelocity(float velocity);
	float getAngularVelocity() const;

	void ApplyForce(const Vector2D& force, const Vector2D& offsetPoint = Vector2D());
	void ApplyTorque(float torque);

	void ApplyLinearImpulse(const Vector2D& impulse, const Vector2D& offsetPoint = Vector2D());
	void ApplyAngularImpulse(float impulse);

private:
	bool createBody(const Vector2D& position, const float angle);

	TransformComponent* transform;

	b2Body* body;
	BodyType body_type;

	bool is_dirty;

	float gravity_scale;

	float linear_damping;
	float angular_damping;
};

#endif