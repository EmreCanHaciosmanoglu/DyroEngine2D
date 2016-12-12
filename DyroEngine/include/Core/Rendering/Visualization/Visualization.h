#ifndef _VISUALIZATION_H
#define _VISUALIZATION_H

#include "Helpers/ObjectCounter.h"

#ifndef _RENDERITEM_H
#include "Core/Rendering/RenderItem.h"
#endif

#ifndef _VECTOR_
#include <vector>
#endif

class GameObject;
class VisualizationManager;

class Visualization : public ObjectCounter<Visualization>
{
public:
	Visualization(GameObject* object);
	virtual ~Visualization();

	virtual const std::vector<RenderItem>& getRenderItems() const;

	unsigned int getVisualizationID() const;
	GameObject* getGameObject() const;

	void addVisualizationChildNode(Visualization* visualization);
	void removeVisualizationChildNode(Visualization* visualization);

protected:

	unsigned int id;

	std::vector<RenderItem> render_items;

	GameObject* game_object;
	VisualizationManager* visualization_manager;
};

#endif