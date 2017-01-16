#ifndef _VISUALIZATION_H
#define _VISUALIZATION_H

#include "Core/Helpers/TaggedObject.h"

#ifndef _RENDERITEM_H
#include "Rendering/Objects/RenderItems/RenderItem.h"
#endif

#ifndef _VECTOR_
#include <vector>
#endif

class Object;
class RenderItem;
class Scene;

class Visualization : public TaggedObject<Visualization>
{
public:
	Visualization(Object* object, const std::tstring& name = _T(""));
	virtual ~Visualization();

	virtual bool initialize() = 0;
	virtual bool shutdown() = 0;

	virtual void getRenderItems(std::vector<RenderItem*>& items) = 0;

	void setScene(Scene* scene);
	Scene* getScene() const;

	void setParent(Visualization* visualization);
	Visualization* getParent() const;

	Object* getObject() const;

protected:
	Scene* scene;
	Object* object;
	Visualization* parent_visualization;
};

#endif