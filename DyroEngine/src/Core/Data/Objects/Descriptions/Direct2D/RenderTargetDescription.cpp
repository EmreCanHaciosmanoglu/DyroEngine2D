#include "Core/Data/Objects/Descriptions/Direct2D/RenderTargetDescription.h"

RenderTargetDescription::RenderTargetDescription(D2D1_RENDER_TARGET_PROPERTIES renderTargetProperties, D2D1_HWND_RENDER_TARGET_PROPERTIES hwndProperties)
	:render_target_properties(renderTargetProperties)
	,hwnd_properties(hwndProperties)
{}
RenderTargetDescription::~RenderTargetDescription()
{}

void RenderTargetDescription::setRenderTargetProperties(D2D1_RENDER_TARGET_PROPERTIES properties)
{
	this->render_target_properties = properties;
}
void RenderTargetDescription::setHwndProperties(D2D1_HWND_RENDER_TARGET_PROPERTIES properties)
{
	this->hwnd_properties = properties;
}

const D2D1_RENDER_TARGET_PROPERTIES& RenderTargetDescription::getRenderTargetProperties() const
{
	return this->render_target_properties;
}
const D2D1_HWND_RENDER_TARGET_PROPERTIES& RenderTargetDescription::getHwndProperties() const
{
	return this->hwnd_properties;
}