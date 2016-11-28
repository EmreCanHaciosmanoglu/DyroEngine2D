#include "Interfaces/IDrawableDebugInfo.h"

IDrawableDebugInfo::IDrawableDebugInfo()
	:can_draw_debug(true)
{
}
IDrawableDebugInfo::~IDrawableDebugInfo()
{
}

void IDrawableDebugInfo::setCanDrawDebugInfo(bool canDraw)
{
	this->can_draw_debug = canDraw;
}
bool IDrawableDebugInfo::getCanDrawDebugInfo() const
{
	return this->can_draw_debug;
}