#include "Core/Rendering/Visualization/Visualization.h"
#include "Core\Rendering\Visualization\Manager\VisualizationManager.h"

#include "Defines\deletemacros.h"

Visualization::Visualization(Object* object, const std::tstring& name)
	:TaggedObject(name)
	,parent_visualization(nullptr)
	,object(object)
{
	this->visualization_manager = new VisualizationManager();
	this->visualization_manager->initialize();
}
Visualization::~Visualization()
{
	this->visualization_manager->shutdown();
	SafeDelete(this->visualization_manager);
}

void Visualization::getRenderItems(std::vector<RenderItem*>& items)
{
	generateRenderItems(items);

	std::vector<Visualization*> visualizations;
	this->visualization_manager->getVisualizations(visualizations);
	for (Visualization* visualization : visualizations)
	{
		visualization->getRenderItems(items);
	}
}

void Visualization::setParent(Visualization* visualization)
{
	this->parent_visualization = visualization;
}
Visualization* Visualization::Visualization::getParent() const
{
	return this->parent_visualization;
}

Object* Visualization::getObject() const
{
	return this->object;
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

void Visualization::generateRenderItems(std::vector<RenderItem*>& items)
{

}