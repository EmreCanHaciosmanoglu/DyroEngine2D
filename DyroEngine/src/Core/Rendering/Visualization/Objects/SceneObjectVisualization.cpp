#include "Core\Rendering\Visualization\Objects\SceneObjectVisualization.h"
#include "Core\Rendering\Visualization\Manager\VisualizationManager.h"

#include "SceneGraph\GameObjects\SceneObject.h"

#include "SceneGraph\Component\TransformComponent.h"

#include "Defines\deletemacros.h"

SceneObjectVisualization::SceneObjectVisualization(SceneObject* object, const std::tstring& name)
	:Visualization(object, name)
	, is_root(false)
	, visualization_manager(nullptr)
{
	this->visualization_manager = new VisualizationManager();
	this->visualization_manager->initialize();
}
SceneObjectVisualization::~SceneObjectVisualization()
{
	this->visualization_manager->shutdown();
	SafeDelete(this->visualization_manager);
}

void SceneObjectVisualization::getRenderItems(std::vector<RenderItem*>& items)
{
	std::vector<Visualization*> visualizations;
	this->visualization_manager->getVisualizations(visualizations);
	for (Visualization* visualization : visualizations)
	{
		visualization->getRenderItems(items);
	}
}

SceneObject* SceneObjectVisualization::getSceneObject() const
{
	return dynamic_cast<SceneObject*>(getObject());
}

const Vector2D& SceneObjectVisualization::getPosition() const
{
	TransformComponent* transform = getSceneObject()->getTransform();
	return transform->getPosition();
}
const Vector2D& SceneObjectVisualization::getScale() const
{
	TransformComponent* transform = getSceneObject()->getTransform();
	return transform->getScale();
}
float SceneObjectVisualization::getRotation() const
{
	TransformComponent* transform = getSceneObject()->getTransform();
	return transform->getRotation();
}

const Matrix2D& SceneObjectVisualization::getTransform() const
{
	TransformComponent* transform = getSceneObject()->getTransform();
	return transform->getWorldMatrix();
}

void SceneObjectVisualization::addVisualizationChildNode(Visualization* visualization)
{
	visualization->setParent(this);
	this->visualization_manager->addVisualization(visualization);
}
void SceneObjectVisualization::removeVisualizationChildNode(Visualization* visualization)
{
	this->visualization_manager->removeVisualization(visualization->getID());
}

void SceneObjectVisualization::setRoot(bool root)
{
	this->is_root = root;
}
bool SceneObjectVisualization::isRoot() const
{
	return this->is_root;
}