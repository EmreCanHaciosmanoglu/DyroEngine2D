#include "SceneGraph\GameObjects\Camera\Manager\CameraManager.h"
#include "SceneGraph\GameObjects\Camera\Camera.h"

#include "Defines/assert.h"

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
	return true;
}

void CameraManager::setActiveCamera(unsigned int id)
{
	setActiveCamera(getObject(id));
}
void CameraManager::setActiveCamera(Camera* camera)
{
	if (camera == nullptr)
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

	addObject(camera->getID(), camera);
	if (setActive)
	{
		setActiveCamera(camera);
	}
}