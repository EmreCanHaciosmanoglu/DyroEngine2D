#include "Core/Rendering/Visualization/Visualization.h"
#include "Core\Rendering\Visualization\Manager\VisualizationManager.h"

#include "Defines\deletemacros.h"

Visualization::Visualization(GameObject* object, const std::tstring& name)
	:TaggedObject(name)
	,parent_visualization(nullptr)
	,game_object(object)
{
	this->visualization_manager = new VisualizationManager();
	this->visualization_manager->initialize();
}
Visualization::~Visualization()
{
	this->visualization_manager->shutdown();
	SafeDelete(this->visualization_manager);
}

const std::vector<RenderItem>& Visualization::getRenderItems() const
{
	return this->render_items;
}

void Visualization::setParent(Visualization* visualization)
{
	this->parent_visualization = visualization;
}
Visualization* Visualization::Visualization::getParent() const
{
	return this->parent_visualization;
}

GameObject* Visualization::getGameObject() const
{
	return this->game_object;
}

void Visualization::addVisualizationChildNode(Visualization* visualization)
{
	visualization->setParent(this);
	this->visualization_manager->addVisualization(visualization);
}
void Visualization::removeVisualizationChildNode(Visualization* visualization)
{
	this->visualization_manager->removeVisualization(visualization->getID());
}