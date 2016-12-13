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

void VisualizationManager::addVisualization(Visualization* v)
{
	addObject(v->getID(), v);
}

void VisualizationManager::removeVisualization(unsigned int id)
{
	removeObject(id);
}
void VisualizationManager::removeVisualization(Visualization* v)
{
	removeObject(v);
}

void VisualizationManager::removeVisualizations(GameObject* gameObject)
{
	std::map<unsigned int, Visualization*> visualizations = getObjects();
	std::vector<unsigned int> to_remove;

	for (std::map<unsigned int, Visualization*>::const_iterator it = visualizations.begin(); it != visualizations.end(); ++it)
	{
		if ((*it).second->getGameObject() == gameObject)
			to_remove.push_back((*it).first);
	}

	for (std::vector<unsigned int>::const_iterator it = to_remove.begin(); it != to_remove.end(); ++it)
		removeObject(*it);
}

void VisualizationManager::getVisualizations(std::vector<Visualization*>& visualizations) const
{
	getObjects(visualizations);
}
const std::map<unsigned int, Visualization*>&  VisualizationManager::getVisualizations() const
{
	return getObjects();
}