#include "Core/Rendering/Visualization/Visualization.h"

#include "Core/Rendering/Visualization/Manager/VisualizationManager.h"

Visualization::Visualization(GameObject* object)
	:game_object(object)
	,id(ObjectCounter<Visualization>::getAmount())
{

}
Visualization::~Visualization()
{

}

const std::vector<RenderItem>& Visualization::getRenderItems() const
{
	return this->render_items;
}

unsigned int Visualization::getVisualizationID() const
{
	return this->id;
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
	this->visualization_manager->removeVisualization(visualization);
}