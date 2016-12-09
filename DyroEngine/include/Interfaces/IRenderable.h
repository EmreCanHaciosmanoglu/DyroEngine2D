#ifndef _IRENDERABLE_H
#define _IRENDERABLE_H

class IRenderable
{
public:
	IRenderable();
	virtual ~IRenderable();

	void setCanRender(bool draw);
	bool getCanRender() const;

private:
	bool can_render;
};

#endif

