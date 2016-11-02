#include "SceneGraph\Component\TransformComponent.h"

#include "SceneGraph\Object\GameObjects\GameObject.h"

TransformComponent::TransformComponent(const std::tstring& name)
	:Component(name == _T("") ? _T("TransformComponent") : name)
	,is_dirty(false)
	,position(0,0)
	,scaling(1,1)
	,rotation(0.0f)
	,world_matrix()
{
}
TransformComponent::~TransformComponent()
{
}

bool TransformComponent::initialize()
{
	return true;
}
void TransformComponent::update()
{
	if (!this->is_dirty)
		return;

	Matrix2D mat_translation = Matrix2D::createTranslationMatrix(this->position);
	Matrix2D mat_scale = Matrix2D::createScalingMatrix(this->scaling);
	Matrix2D mat_rotation = Matrix2D::createRotationMatrix(this->rotation);

	this->world_matrix = mat_scale*mat_rotation*mat_translation;

	this->is_dirty = false;
}
bool TransformComponent::shutdown()
{
	return true;
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
void TransformComponent::setScale(const Vector2D& scale)
{
	this->is_dirty = true;
	this->scaling = scale;
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
const Vector2D& TransformComponent::getScale() const
{
	return this->scaling;
}
float TransformComponent::getRotation() const
{
	return this->rotation;
}

const Matrix2D& TransformComponent::getWorldMatrix() const
{
	return this->world_matrix;
}
