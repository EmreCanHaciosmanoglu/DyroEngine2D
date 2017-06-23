#ifndef _FIXEDCAMERA_H
#define _FIXEDCAMERA_H

#include "SceneGraph\Objects\GameObjects\Camera\Camera.h"

class FixedCamera : public Camera
{
public:
	FixedCamera(const Vector2D& startPosition, bool isActive = true, const std::tstring& name = _T("FixedCamera"));
	virtual ~FixedCamera();
};

#endif
