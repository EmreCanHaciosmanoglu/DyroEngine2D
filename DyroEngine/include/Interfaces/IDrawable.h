#pragma once
class IDrawable
{
public:
	IDrawable();
	virtual ~IDrawable();

	virtual void draw() = 0;

	void setCanDraw(bool draw);
	bool getCanDraw() const;

private:
	bool can_draw;
};

