#ifndef _IFILLABLESHAPE_H
#define _IFILLABLESHAPE_H

class IFillableShape
{
public:
	IFillableShape()
		:fill(true)
	{}
	virtual ~IFillableShape(){}

	virtual void setFill(bool fill) = 0;
	virtual bool getFill() const = 0;

protected:
	bool fill;
};

#endif