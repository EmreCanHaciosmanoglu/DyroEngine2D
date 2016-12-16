#ifndef _VISUALIZATION_H
#define _VISUALIZATION_H

#include "Helpers\TaggedObject.h"

#ifndef _RENDERITEM_H
#include "Core/Rendering/RenderItem.h"
#endif

#ifndef _VECTOR_
#include <vector>
#endif

class Object;
class RenderItem;
class VisualizationManager;

class Visualization : public TaggedObject<Visualization>
{
public:
	Visualization(Object* object, const std::tstring& name = _T(""));
	virtual ~Visualization();

	void getRenderItems(std::vector<RenderItem*>& items);
	
	void setParent(Visualization* visualization);
	Visualization* getParent() const;

	Object* getObject() const;

	void addVisualizationChildNode(Visualization* visualization);
	void removeVisualizationChildNode(Visualization* visualization);

protected:

	virtual void generateRenderItems(std::vector<RenderItem*>& items);

	Object* object;
	
	Visualization* parent_visualization;
	VisualizationManager* visualization_manager;
};

#endif