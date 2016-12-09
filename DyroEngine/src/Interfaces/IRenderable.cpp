#include "Interfaces/IRenderable.h"

IRenderable::IRenderable()
	:can_render(true)
{
}
IRenderable::~IRenderable()
{
}

void IRenderable::setCanRender(bool draw)
{
	this->can_render = draw;
}
bool IRenderable::getCanRender() const
{
	return this->can_render;
}