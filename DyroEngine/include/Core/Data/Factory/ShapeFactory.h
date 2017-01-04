#ifndef _SHAPEFACTORY_H
#define _SHAPEFACTORY_H

class Shape;
enum class ShapeType;

class ShapeFactory
{
public:
	ShapeFactory();
	virtual ~ShapeFactory();

	Shape* createShape(ShapeType type);
};

#endif