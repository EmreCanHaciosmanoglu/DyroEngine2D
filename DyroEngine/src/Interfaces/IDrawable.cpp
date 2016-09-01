#include "Interfaces/IDrawable.h"

IDrawable::IDrawable()
	:can_draw(true)
{
}
IDrawable::~IDrawable()
{
}

void IDrawable::setCanDraw(bool draw)
{
	this->can_draw = draw;
}
bool IDrawable::getCanDraw() const
{
	return this->can_draw;
}