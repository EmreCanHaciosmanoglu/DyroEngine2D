#ifndef _IMAGEVISUALIZATION_H
#define _IMAGEVISUALIZATION_H

#include "Core/Rendering/Visualization/Objects/ComponentVisualization.h"

class Texture;

class ImageVisualization : public ComponentVisualization
{
public:
	ImageVisualization(Component* component, const std::tstring& name = _T(""));
	virtual ~ImageVisualization();

protected:
	virtual void generateRenderItems(std::vector<RenderItem*>& items);

private:
	Texture* texture;
};

#endif