#ifndef _POLYGONSHAPEVISUALIZATION_H
#define _POLYGONSHAPEVISUALIZATION_H

#include "Core/Rendering/Visualization/Shapes/ShapeVisualization.h"
#include "Interfaces/IBoundingBox.h"

class GameObject;

class PolygonShapeVisualization : public ShapeVisualization, public IBoundingBox
{
public:
	PolygonShapeVisualization(GameObject* object);
	virtual ~PolygonShapeVisualization();

	virtual Rect2D getBoundingBox() const;
};

#endif