#include "Core/Rendering/Visualization/Visualization.h"
#include "Core\Rendering\Visualization\Manager\VisualizationManager.h"

#include "Defines\deletemacros.h"

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

const std::vector<RenderItem>& Visualization::getRenderItems()
{
	return this->vec_renderitems;
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

