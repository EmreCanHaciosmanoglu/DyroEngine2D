#include "Rendering/Objects/Visualization/GameObjectVisualizations/GameObjectVisualization.h"
#include "Rendering\Manager\VisualizationManager.h"

#include "SceneGraph\Objects\GameObjects\SceneObject.h"

#include "SceneGraph\Objects\Components\TransformComponent.h"

#include "Core\Defines\deletemacros.h"

GameObjectVisualization::GameObjectVisualization(GameObject* object, const std::tstring& name)
	:Visualization(object, name)
	, is_root(false)
	, visualization_manager(nullptr)
{
	this->visualization_manager = new VisualizationManager();

	//Set the active scene of the game object
	setScene(object->getScene());
}
GameObjectVisualization::~GameObjectVisualization()
{
	SafeDelete(this->visualization_manager);
}

bool GameObjectVisualization::initialize()
{
	bool result = this->visualization_manager->initialize();

	return result;
}
bool GameObjectVisualization::shutdown()
{
	bool result = this->visualization_manager->shutdown();

	return result;
}

void GameObjectVisualization::getRenderItems(std::vector<RenderItem*>& items)
{
	std::vector<Visualization*> visualizations;
	this->visualization_manager->getVisualizations(visualizations);
	for (Visualization* visualization : visualizations)
	{
		visualization->getRenderItems(items);
	}
}

GameObject* GameObjectVisualization::getGameObject() const
{
	return dynamic_cast<GameObject*>(getObject());
}

const Vector2D& GameObjectVisualization::getPosition() const
{
	TransformComponent* transform = getGameObject()->getComponent<TransformComponent>();
	if(transform != nullptr)
		return transform->getPosition();
	return Vector2D::ZeroVector;
}
const Vector2D& GameObjectVisualization::getScale() const
{
	TransformComponent* transform = getGameObject()->getComponent<TransformComponent>();
	if (transform != nullptr)
		return transform->getScale();
	return Vector2D::ZeroVector;
}
float GameObjectVisualization::getRotation() const
{
	TransformComponent* transform = getGameObject()->getComponent<TransformComponent>();
	if (transform != nullptr)
		return transform->getRotation();
	return 0.0f;
}

const Matrix2D& GameObjectVisualization::getTransform() const
{
	TransformComponent* transform = getGameObject()->getComponent<TransformComponent>();
	if (transform != nullptr)
		return transform->getWorldMatrix();
	return Matrix2D::ZeroMatrix;
}
void GameObjectVisualization::addVisualizationChildNode(Visualization* visualization)
{
	visualization->setParent(this);
	visualization->setScene(getScene());
	this->visualization_manager->addVisualization(visualization);
}
void GameObjectVisualization::removeVisualizationChildNode(Visualization* visualization)
{
	this->visualization_manager->removeVisualization(visualization->getID());
}

void GameObjectVisualization::setRoot(bool root)
{
	this->is_root = root;
}
bool GameObjectVisualization::isRoot() const
{
	return this->is_root;
}