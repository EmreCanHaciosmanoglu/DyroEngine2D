#include "SceneGraph\Component\TransformComponent.h"

#include "SceneGraph\Object\GameObjects\GameObject.h"
#include "SceneGraph/Scene/Scene.h"

#include "Core/Rendering/Renderer.h"

TransformComponent::TransformComponent(const std::tstring& name)
	:Component(name == _T("") ? _T("TransformComponent") : name)
	, is_dirty(false)
	, position(0, 0)
	, scaling(1, 1)
	, rotation(0.0f)
	, world_matrix()
	, mirror_x(Vector2D(1, 1))
	, mirror_y(Vector2D(1, 1))
	, center_position(0,0)
{
	setExecutionOrder(100);
}
TransformComponent::~TransformComponent()
{
}

bool TransformComponent::initialize()
{
	calculateWorldMatrix();

	return true;
}
void TransformComponent::update()
{
	if (!this->is_dirty)
		return;

	calculateWorldMatrix();

	Renderer* renderer = getParent()->getScene()->getManager<Renderer>();
	renderer->updateRenderItem(getParent()->getObjectID(), getWorldMatrix());

	this->is_dirty = false;
}
bool TransformComponent::shutdown()
{
	return true;
}

void TransformComponent::mirrorX()
{
	this->is_dirty = true;
	this->mirror_x *= Vector2D(-1, 1);
}
void TransformComponent::mirrorY()
{
	this->is_dirty = true;
	this->mirror_y *= Vector2D(1, -1);
}
void TransformComponent::resetMirror(bool x, bool y)
{
	this->is_dirty = true;
	if (x)
		this->mirror_x = Vector2D(1, 1);
	if (y)
		this->mirror_y = Vector2D(1, 1);
}

void TransformComponent::center(float xCenter, float yCenter) 
{
	this->is_dirty = true;
	center(Vector2D(xCenter, yCenter));
}
void TransformComponent::center(const Vector2D& centerPosition)
{
	this->is_dirty = true;
	this->center_position = centerPosition;
}
void TransformComponent::resetCenter()
{
	this->is_dirty = true;
	center(Vector2D(0, 0));
}

void TransformComponent::translate(const Vector2D& translation)
{
	setPosition(getPosition() + translation);
	
	for (GameObject* obj : getParent()->getChilderen())
	{
		TransformComponent* transform = obj->getComponent<TransformComponent>();
		if (!transform)
			continue;

		transform->translate(translation);
	}
}
void TransformComponent::scale(const Vector2D& scale)
{
	setScale(getScale() + scale);

	for (GameObject* obj : getParent()->getChilderen())
	{
		TransformComponent* transform = obj->getComponent<TransformComponent>();
		if (!transform)
			continue;

		transform->scale(scale);
	}
}
void TransformComponent::rotate(float rotation)
{
	setRotation(getRotation() + rotation);

	for (GameObject* obj : getParent()->getChilderen())
	{
		TransformComponent* transform = obj->getComponent<TransformComponent>();
		if (!transform)
			continue;

		transform->rotate(rotation);
	}
}

void TransformComponent::setPosition(const Vector2D& position)
{
	this->is_dirty = true;
	this->position = position;
}
void TransformComponent::setPosition(float x, float y)
{
	setPosition(Vector2D(x, y));
}
void TransformComponent::setScale(const Vector2D& scale)
{
	this->is_dirty = true;
	this->scaling = scale;
}
void TransformComponent::setScale(float x, float y)
{
	setScale(Vector2D(x, y));
}
void TransformComponent::setRotation(float angle)
{
	this->is_dirty = true;
	this->rotation = angle;
}

const Vector2D& TransformComponent::getPosition() const
{
	return this->position;
}
const Vector2D& TransformComponent::getCenterPosition() const
{
	return this->center_position;
}
const Vector2D& TransformComponent::getScale() const
{
	return this->scaling;
}
const Vector2D& TransformComponent::getMirrorX() const
{
	return this->mirror_x;
}
const Vector2D& TransformComponent::getMirrorY() const
{
	return this->mirror_y;
}
float TransformComponent::getRotation() const
{
	return this->rotation;
}

const Matrix2D& TransformComponent::getWorldMatrix() const
{
	return this->world_matrix;
}

void TransformComponent::calculateWorldMatrix()
{
	Matrix2D mat_center = Matrix2D::createTranslationMatrix(this->center_position);
	Matrix2D mat_translation = Matrix2D::createTranslationMatrix(this->position);
	Matrix2D mat_scale = Matrix2D::createScalingMatrix(this->scaling);
	Matrix2D mat_rotation = Matrix2D::createRotationMatrix(this->rotation);

	Matrix2D mat_mirror_x = Matrix2D::createScalingMatrix(this->mirror_x);
	Matrix2D mat_mirror_y = Matrix2D::createScalingMatrix(this->mirror_y);

	this->world_matrix = mat_center*mat_mirror_x*mat_mirror_y*mat_scale*mat_rotation*mat_translation;
}