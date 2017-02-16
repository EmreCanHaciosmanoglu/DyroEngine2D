#include "Core/Data/Objects/Direct2D/RenderTarget.h"

#include "Core/Defines/deletemacros.h"

RenderTarget::RenderTarget(ID2D1Factory* factory, RenderTargetDescription& description)
	: DeviceResource(factory)
	, render_target(nullptr)
	, render_target_description(description)
{}
RenderTarget::~RenderTarget()
{}

bool RenderTarget::create()
{
	HRESULT hr = getD2DFactory()->CreateHwndRenderTarget(
		render_target_description.getRenderTargetProperties(),
		render_target_description.getHwndProperties(), 
		&this->render_target);

	return hr == S_OK;
}
bool RenderTarget::destroy()
{
	SafeRelease(this->render_target);

	return true;
}

ID2D1HwndRenderTarget* RenderTarget::getRenderTarget() const
{
	return this->render_target;
}