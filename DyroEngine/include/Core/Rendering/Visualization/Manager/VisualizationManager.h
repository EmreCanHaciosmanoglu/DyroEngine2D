#ifndef _VISUALIZATIONMANAGER_H
#define _VISUALIZATIONMANAGER_H

#include "Helpers\Manager.h"

class Visualization;

class VisualizationManager : Manager<Visualization>
{
public:
	VisualizationManager();
	virtual ~VisualizationManager();

	virtual bool initialize();
	virtual bool shutdown();

	void addVisualization(unsigned int id, Visualization* v);
	
	void removeVisualization(unsigned int id);
	void removeVisualization(Visualization* v);

	void getVisualizations(std::vector<Visualization*> visualizations);
};

#endif