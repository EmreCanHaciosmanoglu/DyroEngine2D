#ifndef _RENDERTARGET_H
#define _RENDERTARGET_H

#include "Core/Data/Objects/Direct2D/DeviceResource.h"

#ifndef _RENDERTARGETDESCRIPTION_H
#include "Core/Data/Objects/Descriptions/Direct2D/RenderTargetDescription.h"
#endif

class RenderTarget : public DeviceResource
{
public:
	RenderTarget(ID2D1Factory* factory, RenderTargetDescription& description);
	virtual ~RenderTarget();

	virtual bool create();
	virtual bool destroy();

	ID2D1HwndRenderTarget* getRenderTarget() const;

private:
	ID2D1HwndRenderTarget* render_target;
	RenderTargetDescription render_target_description;
};

#endif