#ifndef _SCENEOBJECTVISUALIZATION_H
#define _SCENEOBJECTVISUALIZATION_H

#include "Core/Rendering/Visualization/Objects/Visualization.h"

class SceneObject;

class Visualization;
class VisualizationManager;

class SceneObjectVisualization : public Visualization
{
public:
	SceneObjectVisualization(SceneObject* object, const std::tstring& name = _T(""));
	virtual ~SceneObjectVisualization();

	virtual void getRenderItems(std::vector<RenderItem>& items);

	SceneObject* getSceneObject() const;

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
