#ifndef _VISUALIZATION_H
#define _VISUALIZATION_H

#include "Helpers\TaggedObject.h"

#ifndef _RENDERITEM_H
#include "Core/Rendering/RenderItem.h"
#endif

#ifndef _VECTOR_
#include <vector>
#endif

class GameObject;
class VisualizationManager;

class Visualization : public TaggedObject<Visualization>
{
public:
	Visualization(GameObject* object, const std::tstring& name = _T(""));
	virtual ~Visualization();

	const std::vector<RenderItem>& getRenderItems();

	GameObject* getGameObject() const;

	void addVisualizationChildNode(Visualization* visualization);
	void removeVisualizationChildNode(Visualization* visualization);

protected:

	std::vector<RenderItem> vec_renderitems;

	GameObject* game_object;
	VisualizationManager* visualization_manager;
};

#endif