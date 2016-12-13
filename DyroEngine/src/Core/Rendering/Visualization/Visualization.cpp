#include "Core/Rendering/Visualization/Visualization.h"
#include "Core\Rendering\Visualization\Manager\VisualizationManager.h"

#include "Defines\deletemacros.h"
Visualization::Visualization(GameObject* object)
	:game_object(object)
	,id(ObjectCounter<Visualization>::getAmount())

Visualization::Visualization(GameObject* object, const std::tstring& name)
	:TaggedObject(name)
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

GameObject* Visualization::getGameObject() const
{
	return this->game_object;
}

void Visualization::addVisualizationChildNode(Visualization* visualization)
{
	this->visualization_manager->addVisualization(visualization);
}
void Visualization::removeVisualizationChildNode(Visualization* visualization)
{
	this->visualization_manager->removeVisualization(visualization->getID());
}

void Visualization::addVisualizationChildNode(Visualization* visualization)
{
	this->visualization_manager->addVisualization(visualization);
}
void Visualization::removeVisualizationChildNode(Visualization* visualization)
{
	this->visualization_manager->removeVisualization(visualization);
}