#ifndef _CAMERAMANAGER_H
#define _CAMERAMANAGER_H

#include "Helpers/Manager.h"

#ifndef _STRING_H
	#include "Defines\string.h"
#endif

class Camera;

class CameraManager : public Manager<Camera>
{
public:
	CameraManager();
	virtual ~CameraManager();

	virtual bool initialize();
	virtual bool shutdown();

	void setActiveCamera(unsigned int id);
	void setActiveCamera(Camera* camera);

	Camera* getActiveCamera() const;

	void addCamera(Camera* camera, bool setActive = true);

private:
	Camera* active_camera;
};

#endif