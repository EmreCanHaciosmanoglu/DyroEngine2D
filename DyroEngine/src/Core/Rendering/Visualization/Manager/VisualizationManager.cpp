#include "Core\Rendering\Visualization\Manager\VisualizationManager.h"
#include "Core\Rendering\Visualization\Visualization.h"

#include "Defines\deletemacros.h"

VisualizationManager::VisualizationManager()
{}
VisualizationManager::~VisualizationManager()
{}

bool VisualizationManager::initialize()
{
	return true;
}
bool VisualizationManager::shutdown()
{
	std::vector<Visualization*> visualizations;
	getObjects(visualizations);

	for (Visualization* visualization : visualizations)
		SafeDelete(visualization);

	return true;
}

void VisualizationManager::addVisualization(unsigned int id, Visualization* v)
{
	addObject(id, v);
}

void VisualizationManager::removeVisualization(unsigned int id)
{
	removeObject(id);
}
void VisualizationManager::removeVisualization(Visualization* v)
{
	removeObject(v);
}

void VisualizationManager::getVisualizations(std::vector<Visualization*> visualizations)
{
	getObjects(visualizations);
}