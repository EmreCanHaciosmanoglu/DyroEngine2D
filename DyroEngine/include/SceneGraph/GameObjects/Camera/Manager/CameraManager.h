#ifndef _CAMERAMANAGER_H
#define _CAMERAMANAGER_H

#include "Helpers/Manager.h"

#ifndef _STRING_H
#include "Defines\string.h"
#endif

#ifndef _VECTOR_
#include <vector>
#endif

class Camera;

class CameraManager : public Manager
{
public:
	CameraManager();
	virtual ~CameraManager();

	virtual bool initialize();
	virtual bool shutdown();

	void setActiveCamera(const std::tstring& name);
	void setActiveCamera(Camera* camera);

	Camera* getActiveCamera() const;

	void addCamera(Camera* camera, bool setActive = true);

private:
	std::vector<Camera*> vec_cameras;
	Camera* active_camera;
};

#endif