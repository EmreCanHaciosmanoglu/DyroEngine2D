#include "SceneGraph\GameObjects\Astroid.h"

#include "SceneGraph/Component/Shapes/ShapeComponent.h"
#include "SceneGraph/Component/RigidBodyComponent.h"
#include "SceneGraph/Component/Collision/PolygonCollisionComponent.h"

#include "Core/Data/Objects/Shapes/PolygonShape.h"

#include "Defines\programdefaults.h"

namespace
{
	const int MIN_ANGLE_STEP = 45;
	const int MAX_ANGLE_STEP = 60;

	const float FORCE = 300000.0f;

	const float LINEAR_DAMPING = 0.0f;
	const float ANGULAR_DAMPING = 0.0f;
}

Astroid::Astroid(float radius)
	:Obstacle(BodyType::DYNAMIC)
	, radius(radius)
{
	OBJECT_INIT(_T("Astroid"));
}
Astroid::~Astroid()
{}

bool Astroid::initialize()
{
	//std::vector<Vector2D> vertices;
	//generateVertices(vertices);

	//ShapeComponent* shape_component = new ShapeComponent(new PolygonShape(vertices));
	//shape_component->setColor(Color(0.5f, 0.5f, 0.0f));

	//addComponent(shape_component);
	//addComponent(new PolygonCollisionComponent(getRigidBody(), vertices));

	//getRigidBody()->setGravityScale(0.0f);

	//getRigidBody()->setLinearDamping(LINEAR_DAMPING);
	//getRigidBody()->setAngularDamping(ANGULAR_DAMPING);

	return Obstacle::initialize();
}
bool Astroid::postInitialize()
{
	Vector2D force = this->direction * FORCE;

	getRigidBody()->ApplyForce(force);

	return Obstacle::postInitialize();
}
void Astroid::update()
{
	Obstacle::update();
}
bool Astroid::shutdown()
{
	return Obstacle::shutdown();
}

void Astroid::setDirection(const Vector2D& direction)
{
	this->direction = direction;
}

void Astroid::generateVertices(std::vector<Vector2D>& vertices)
{
	float x = 0.0f;
	float y = 0.0f;

	for (float angle = 0.0f; angle < 2.0f * constants::PI;)
	{
		x = x + (this->radius * cos(angle));
		y = y + (this->radius * sin(angle));

		angle += ((rand() % MAX_ANGLE_STEP + MIN_ANGLE_STEP)*constants::TO_RADIANS);

		vertices.push_back(Vector2D(x, y));
	}
}