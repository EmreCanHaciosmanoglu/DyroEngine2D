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

class Visualization : public TaggedObject<Visualization>
{
public:
	Visualization(Object* object, const std::tstring& name = _T(""));
	virtual ~Visualization();

	virtual void getRenderItems(std::vector<RenderItem>& items) = 0;

	void setParent(Visualization* visualization);
	Visualization* getParent() const;

	Object* getObject() const;

protected:
	Object* object;
	Visualization* parent_visualization;
};

#endif