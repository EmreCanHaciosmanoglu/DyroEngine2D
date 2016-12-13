#ifndef _VISUALIZATIONMANAGER_H
#define _VISUALIZATIONMANAGER_H

#include "Helpers\Manager.h"

class GameObject;
class Visualization;

class VisualizationManager : Manager<Visualization>
{
public:
	VisualizationManager();
	virtual ~VisualizationManager();

	virtual bool initialize();
	virtual bool shutdown();

	void addVisualization(Visualization* v);
	
	void removeVisualization(unsigned int id);
	void removeVisualization(Visualization* v);

	void removeVisualizations(GameObject* gameObject);

	void getVisualizations(std::vector<Visualization*>& visualizations) const;
	const std::map<unsigned int, Visualization*>& getVisualizations() const;
};

#endif