#ifndef _RENDERTARGETDESCRIPTION_H
#define _RENDERTARGETDESCRIPTION_H

#ifndef _2DUTILL_H
#include "Core/Defines/d2dutill.h"
#endif

class RenderTargetDescription
{
public:
	RenderTargetDescription(D2D1_RENDER_TARGET_PROPERTIES renderTargetProperties, D2D1_HWND_RENDER_TARGET_PROPERTIES hwndProperties);
	~RenderTargetDescription();

	void setRenderTargetProperties(D2D1_RENDER_TARGET_PROPERTIES properties);
	void setHwndProperties(D2D1_HWND_RENDER_TARGET_PROPERTIES properties);

	const D2D1_RENDER_TARGET_PROPERTIES& getRenderTargetProperties() const;
	const D2D1_HWND_RENDER_TARGET_PROPERTIES& getHwndProperties() const;

private:
	D2D1_RENDER_TARGET_PROPERTIES render_target_properties;
	D2D1_HWND_RENDER_TARGET_PROPERTIES hwnd_properties;
};

#endif