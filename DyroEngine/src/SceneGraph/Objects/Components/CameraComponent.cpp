#include "SceneGraph\Objects\Components\CameraComponent.h"
#include "SceneGraph\Objects\Components\TransformComponent.h"

#include "SceneGraph\Objects\GameObjects\GameObject.h"

#include "Core\Defines\assert.h"

CameraComponent::CameraComponent(const std::tstring& name)
	:Component(name == _T("") ? _T("CameraComponent") : name)
	, transform(nullptr)
{
}
CameraComponent::~CameraComponent()
{
}

bool CameraComponent::initialize()
{
	this->transform = getParent()->getComponent<TransformComponent>();

	//Transform on a camera cannot be null
	assert(transform != nullptr);

	return true;
}
void CameraComponent::update()
{
}
bool CameraComponent::shutdown()
{
	return true;
}

const Matrix2D CameraComponent::getViewMatrix() const
{
	Matrix2D world_matrix = this->transform->getWorldMatrix();
	return world_matrix.inverse();
}