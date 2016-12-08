#ifndef _RENDERITEM_H
#define _RENDERITEM_H

class RenderItem
{
public:
	RenderItem();
	virtual ~RenderItem();

	void setLayer(unsigned int layer);
	unsigned int getLayer() const;

	virtual void render() = 0;

private:

	unsigned int layer;
};

#endif