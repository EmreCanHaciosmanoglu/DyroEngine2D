#include "SceneGraph\Objects\Components\TransformComponent.h"

#include "SceneGraph\Objects\GameObjects\GameObject.h"
#include "SceneGraph\Objects\GameObjects\SceneObject.h"

#include "SceneGraph/Objects/Scenes/Scene.h"

#include "Rendering/Renderer.h"

const Vector2D TransformComponent::world_forward = Vector2D(0, 1);
const Vector2D TransformComponent::world_right = Vector2D(1, 0);

TransformComponent::TransformComponent(const std::tstring& name)
	:Component(name == _T("") ? _T("TransformComponent") : name)
	, is_dirty(false)
	, start_position(0, 0)
	, start_scaling(1, 1)
	, start_rotation(0.0f)
	, position(start_position)
	, scaling(start_scaling)
	, rotation(start_rotation)
	, world_matrix()
	, mirror_x(Vector2D(1, 1))
	, mirror_y(Vector2D(1, 1))
	//, center_position(0, 0)
	, forward(TransformComponent::world_forward)
	, right(TransformComponent::world_right)
{
	OBJECT_INIT(_T("TransformComponent"));

	setExecutionOrder(100);
}
TransformComponent::~TransformComponent()
{
}

bool TransformComponent::initialize()
{
	//Starting transform
	setPosition(getStartPosition());
	setScale(getStartScale());
	setRotation(getStartRotation());

	calculateWorldMatrix();

	return true;
}
void TransformComponent::update()
{
	if (!getIsDirty())
		return;

	Matrix2D rot_mat = Matrix2D::createRotationMatrix(getRotation());

	forward = rot_mat.transformVector(TransformComponent::world_forward);
	right = rot_mat.transformVector(TransformComponent::world_right);

	calculateWorldMatrix();

	clearIsDirty();
}
bool TransformComponent::shutdown()
{
	return true;
}

void TransformComponent::mirrorX()
{
	setIsDirty();
	this->mirror_x *= Vector2D(-1, 1);
}
void TransformComponent::mirrorY()
{
	setIsDirty();
	this->mirror_y *= Vector2D(1, -1);
}
void TransformComponent::resetMirror(bool x, bool y)
{
	setIsDirty();
	if (x)
		this->mirror_x = Vector2D(1, 1);
	if (y)
		this->mirror_y = Vector2D(1, 1);
}

//void TransformComponent::center(float xCenter, float yCenter)
//{
//	setIsDirty();
//	center(Vector2D(xCenter, yCenter));
//}
//void TransformComponent::center(const Vector2D& centerPosition)
//{
//	setIsDirty();
//	this->center_position = centerPosition;
//}
//void TransformComponent::resetCenter()
//{
//	setIsDirty();
//	center(Vector2D(0, 0));
//}

void TransformComponent::translate(const Vector2D& translation)
{
	setPosition(getPosition() + translation);

	std::vector<GameObject*> childeren;
	getParent()->getChilderen(childeren);

	for (GameObject* obj : childeren)
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

	std::vector<GameObject*> childeren;
	getParent()->getChilderen(childeren);

	for (GameObject* obj : childeren)
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

	std::vector<GameObject*> childeren;
	getParent()->getChilderen(childeren);

	for (GameObject* obj : childeren)
	{
		TransformComponent* transform = obj->getComponent<TransformComponent>();
		if (!transform)
			continue;

		transform->rotate(rotation);
	}
}

void TransformComponent::setPosition(const Vector2D& position)
{
	setIsDirty();
	this->position = position;
}
void TransformComponent::setPosition(float x, float y)
{
	setPosition(Vector2D(x, y));
}
void TransformComponent::setStartPosition(const Vector2D& position)
{
	setIsDirty();
	this->start_position = position;
}
void TransformComponent::setStartPosition(float x, float y)
{
	setStartPosition(Vector2D(x, y));
}
void TransformComponent::setScale(const Vector2D& scale)
{
	setIsDirty();
	this->scaling = scale;
}
void TransformComponent::setScale(float x, float y)
{
	setScale(Vector2D(x, y));
}
void TransformComponent::setStartScale(const Vector2D& scale)
{
	setIsDirty();
	this->start_scaling = scale;
}
void TransformComponent::setStartScale(float x, float y)
{
	setStartScale(Vector2D(x, y));
}
void TransformComponent::setRotation(float angle)
{
	setIsDirty();
	this->rotation = angle;
}
void TransformComponent::setStartRotation(float angle)
{
	this->start_rotation = angle;
}

const Vector2D& TransformComponent::getPosition() const
{
	return this->position;
}
const Vector2D& TransformComponent::getStartPosition() const
{
	return this->start_position;
}
//const Vector2D& TransformComponent::getCenterPosition() const
//{
//	return this->center_position;
//}
const Vector2D& TransformComponent::getScale() const
{
	return this->scaling;
}
const Vector2D& TransformComponent::getStartScale() const
{
	return this->start_scaling;
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
float TransformComponent::getStartRotation() const
{
	return this->start_rotation;
}

const Vector2D& TransformComponent::getForward() const
{
	return this->forward;
}
const Vector2D& TransformComponent::getRight() const
{
	return this->right;
}

const Matrix2D& TransformComponent::getWorldMatrix() const
{
	return this->world_matrix;
}

void TransformComponent::clearIsDirty()
{
	this->is_dirty = false;
}

void TransformComponent::setIsDirty()
{
	this->is_dirty = true;
}
bool TransformComponent::getIsDirty() const
{
	return this->is_dirty;
}

void TransformComponent::calculateWorldMatrix()
{
	//Matrix2D mat_center = Matrix2D::createTranslationMatrix(this->center_position);
	Matrix2D mat_translation = Matrix2D::createTranslationMatrix(this->position);
	Matrix2D mat_scale = Matrix2D::createScalingMatrix(this->scaling);
	Matrix2D mat_rotation = Matrix2D::createRotationMatrix(this->rotation);

	Matrix2D mat_mirror_x = Matrix2D::createScalingMatrix(this->mirror_x);
	Matrix2D mat_mirror_y = Matrix2D::createScalingMatrix(this->mirror_y);

	this->world_matrix = /*mat_center**/mat_mirror_x*mat_mirror_y*mat_scale*mat_rotation*mat_translation;
}