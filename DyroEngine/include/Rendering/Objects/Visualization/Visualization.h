#ifndef _VISUALIZATION_H
#define _VISUALIZATION_H

#include "Core/Helpers/TaggedObject.h"
#ifndef _IBOUNDINGBOX_H
#include "Core/Helpers/Interfaces/IBoundingBox.h"
#endif

#ifndef _RENDERITEM_H
#include "Rendering/Objects/RenderItems/RenderItem.h"
#endif

#ifndef _VECTOR_
#include <vector>
#endif

class Object;
class RenderItem;

class Visualization : public TaggedObject<Visualization> , public IBoundingBox
{
public:
	Visualization(Object* object, const std::tstring& name = _T(""));
	virtual ~Visualization();

	virtual void getRenderItems(std::vector<RenderItem*>& items) = 0;
	virtual Rect2D getBoundingBox() = 0;

	void setParent(Visualization* visualization);
	Visualization* getParent() const;

	Object* getObject() const;

protected:
	Object* object;
	Visualization* parent_visualization;
};

#endif