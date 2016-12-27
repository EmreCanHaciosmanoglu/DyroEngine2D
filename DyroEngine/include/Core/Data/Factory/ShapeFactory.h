#ifndef _SHAPEFACTORY_H
#define _SHAPEFACTORY_H

#include "Core\Data\Manager\ShapeFactory.h"

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