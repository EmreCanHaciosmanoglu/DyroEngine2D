#include "SceneGraph\Objects\Components\Physics\Collision\TriangleCollisionComponent.h"

TriangleCollisionComponent::TriangleCollisionComponent(RigidBodyComponent* rigid, float xScale, float yScale, float restitution, float friction, float density, const std::tstring& name)
	:PolygonCollisionComponent(rigid, std::vector<Vector2D>() = { Vector2D(-1 * xScale , 0), Vector2D(1 * xScale,1 * yScale), Vector2D(1 * xScale, -1 * yScale) }, restitution, friction, density, name == _T("") ? _T("TriangleCollisionComponent") : name)
{
	OBJECT_INIT(_T("TriangleCollisionComponent"));
}
TriangleCollisionComponent::~TriangleCollisionComponent()
{}