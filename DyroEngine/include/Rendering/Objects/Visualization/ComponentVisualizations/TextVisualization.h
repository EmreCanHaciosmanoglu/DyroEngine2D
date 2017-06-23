#ifndef _TEXTVISUALIZATION_H
#define _TEXTVISUALIZATION_H

#include "Rendering\Objects\Visualization\ComponentVisualizations\ConcreteComponentVisualization.h"

class TextComponent;
class Text;

class TextVisualization : public ConcreteComponentVisualization<TextComponent>
{
public:
	TextVisualization(Component* object, const std::tstring& name = _T(""));
	virtual ~TextVisualization();

	virtual bool initialize();
	virtual bool shutdown();

	virtual Rect2D getBoundingBox() const;

protected:
	virtual void generateRenderItems(std::vector<RenderItem*>& items);

private:
	Text* text;
};

#endif