#ifndef _SCENEOBJECTVISUALIZATION_H
#define _SCENEOBJECTVISUALIZATION_H

#include "Rendering/Objects/Visualization/Visualization.h"

class GameObject;

class Visualization;
class VisualizationManager;

class GameObjectVisualization : public Visualization
{
public:
	GameObjectVisualization(GameObject* object, const std::tstring& name = _T(""));
	virtual ~GameObjectVisualization();

	virtual void getRenderItems(std::vector<RenderItem*>& items);
	virtual Rect2D getBoundingBox();

	GameObject* getGameObject() const;

	const Vector2D& getPosition() const;
	const Vector2D& getScale() const;
	float getRotation() const;

	const Matrix2D& getTransform() const;
	
	void addVisualizationChildNode(Visualization* visualization);
	void removeVisualizationChildNode(Visualization* visualization);

	void setRoot(bool root);
	bool isRoot() const;

private:

	bool is_root;
	VisualizationManager* visualization_manager;
};

#endif
