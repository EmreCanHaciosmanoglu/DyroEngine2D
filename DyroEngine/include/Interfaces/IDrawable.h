#ifndef _IDRAWABLE_H
#define _IDRAWABLE_H

class IDrawable
{
public:
	IDrawable();
	virtual ~IDrawable();

	void setCanDraw(bool draw);
	bool getCanDraw() const;

private:
	bool can_draw;
};

#endif

