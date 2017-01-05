#ifndef _DRAWABLEDEBUGINFO_H
#define _DRAWABLEDEBUGINFO_H

class IDrawableDebugInfo
{
public:
	IDrawableDebugInfo();
	virtual ~IDrawableDebugInfo();

	virtual void drawDebugInfo() = 0;

	void setCanDrawDebugInfo(bool canDraw);
	bool getCanDrawDebugInfo() const;

private:
	bool can_draw_debug;
};

#endif