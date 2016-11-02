#include "SceneGraph\Object\GameObjects\Camera\Manager\CameraManager.h"
#include "SceneGraph\Object\GameObjects\Camera\Camera.h"

#include "Defines/assert.h"

#include <algorithm>

CameraManager::CameraManager()
	:active_camera(nullptr)
{
}
CameraManager::~CameraManager()
{
}

bool CameraManager::initialize()
{
	return true;
}
bool CameraManager::shutdown()
{
	this->vec_cameras.clear();
	return true;
}

void CameraManager::setActiveCamera(const std::tstring& name)
{
	std::vector<Camera*>::iterator it = std::find_if(this->vec_cameras.begin(),this->vec_cameras.end(),
		[name](Camera* camera)
	{
		return name == camera->getName();
	});

	if (it == this->vec_cameras.end())
		return;

	if (this->active_camera != nullptr)
		this->active_camera->deactive();
	this->active_camera = (*it);
	this->active_camera->activate();
}
void CameraManager::setActiveCamera(Camera* camera)
{
	std::vector<Camera*>::iterator it = std::find(this->vec_cameras.begin(), this->vec_cameras.end(), camera);
	if (it == this->vec_cameras.end())
		return;

	if (this->active_camera != nullptr)
		this->active_camera->deactive();
	this->active_camera = camera;
	this->active_camera->activate();
}

Camera* CameraManager::getActiveCamera() const
{
	return this->active_camera;
}

void CameraManager::addCamera(Camera* camera, bool setActive)
{
	//Camera cannot be null
	assert(camera != nullptr);

	std::vector<Camera*>::iterator it = std::find(this->vec_cameras.begin(), this->vec_cameras.end(), camera);
	if (it != this->vec_cameras.end())
		return;

	this->vec_cameras.push_back(camera);
	if (setActive)
	{
		if (this->active_camera != nullptr)
			this->active_camera->deactive();
		this->active_camera = camera;
		this->active_camera->activate();
	}
}