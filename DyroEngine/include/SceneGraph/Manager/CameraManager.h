#ifndef _CAMERAMANAGER_H
#define _CAMERAMANAGER_H

#include "Core/Helpers/Patterns/Manager.h"

#ifndef _STRING_H
#include "Core\Defines\string.h"
#endif

#include "SceneGraph\Objects\GameObjects\Camera\Camera.h"

class CameraManager : public Manager<Camera>
{
public:
	CameraManager();
	virtual ~CameraManager();

	virtual bool initialize();
	virtual bool shutdown();

	void addCamera(Camera* camera, bool setActive = true);

	void setActiveCamera(unsigned int id);
	void setActiveCamera(Camera* camera);

	Camera* getActiveCamera() const;

	void clearActiveCamera();

private:
	Camera* active_camera;
};

#endif