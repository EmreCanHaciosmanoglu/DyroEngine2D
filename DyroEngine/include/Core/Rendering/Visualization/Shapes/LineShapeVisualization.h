#ifndef _LINEVISUALIZATION_H
#define _LINESHAPEVISUALIZATION_H

#include "Core/Rendering/Visualization/Shapes/ShapeVisualization.h"

class DataObject;

class LineShapeVisualization : public ShapeVisualization
{
public:
	LineShapeVisualization(DataObject* object);
	virtual ~LineShapeVisualization();
};

#endif