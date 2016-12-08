#ifndef _RENDERITEM_H
#define _RENDERITEM_H

class RenderItem
{
	RenderItem();
	virtual ~RenderItem();

	virtual void render() = 0;
};

#endif