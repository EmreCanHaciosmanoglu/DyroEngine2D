#ifndef _SHAPEVISUALIZATION_H
#define _SHAPEVISUALIZATION_H

#include "Core/Rendering/Visualization/Visualization.h"

class DataObject;

class ShapeVisualization : public Visualization
{
public:
	ShapeVisualization(DataObject* object);
	virtual ~ShapeVisualization();
};

#endif