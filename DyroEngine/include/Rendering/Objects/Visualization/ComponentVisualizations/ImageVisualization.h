#ifndef _IMAGEVISUALIZATION_H
#define _IMAGEVISUALIZATION_H

#include "Rendering/Objects/Visualization/ComponentVisualizations/ConcreteComponentVisualization.h"

class ImageComponent;

class Texture;

class ImageVisualization : public ConcreteComponentVisualization<ImageComponent>
{
public:
	ImageVisualization(Component* object, const std::tstring& name = _T(""));
	virtual ~ImageVisualization();

	virtual bool initialize();
	virtual bool shutdown();

	virtual Rect2D getBoundingBox() const;

protected:
	virtual void generateRenderItems(std::vector<RenderItem*>& items);

private:
	Texture* texture;
};

#endif