#ifndef _VISUALIZATIONMANAGER_H
#define _VISUALIZATIONMANAGER_H

#include "Core/Helpers/Patterns/Manager.h"

#include "Rendering/Objects/Visualization/Visualization.h"

class Object;

class VisualizationManager : public Manager<Visualization>
{
public:
	VisualizationManager();
	virtual ~VisualizationManager();

	virtual bool initialize();
	virtual bool shutdown();

	void addVisualization(Visualization* v);

	void removeVisualization(unsigned int id);
	void removeVisualization(Visualization* v);

	void removeVisualizations(Object* gameObject);

	void getVisualizations(std::vector<Visualization*>& visualizations) const;
	const std::map<unsigned int, Visualization*>& getVisualizations() const;
};

#endif