#ifndef _VISUALIZATION_H
#define _VISUALIZATION_H

#ifndef _RENDERITEM_H
#include "Core/Rendering/RenderItem.h"
#endif

#ifndef _VECTOR_
#include <vector>
#endif

class GameObject;

class Visualization
{
public:
	Visualization(GameObject* object);
	virtual ~Visualization();

	const std::vector<RenderItem>& getRenderItems();
	GameObject* getGameObject() const;

protected:

	std::vector<RenderItem> vec_renderitems;
	GameObject* game_object;
};

#endif