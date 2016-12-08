#ifndef _VISUALIZATION_H
#define _VISUALIZATION_H

#include "Interfaces/IBoundingBox.h"

#ifndef _RENDERITEM_H
#include "Core/Rendering/RenderItem.h"
#endif

#ifndef _VECTOR_
#include <vector>
#endif

class Object;

class Visualization : public IBoundingBox
{
public:
	Visualization();
	virtual ~Visualization();

	const std::vector<RenderItem>& getRenderItems();
	Object* getObject();

	virtual Rect2D getBoundingBox() const = 0;

private:

	std::vector<RenderItem> vec_renderitems;
	Object* object;
};

#endif