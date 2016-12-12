#ifndef _VISUALIZATIONFACTORY_H
#define _VISUALIZATIONFACTORY_H

class GameObject;
class Visualization;

class VisualizationFactory
{
public:
	VisualizationFactory();
	~VisualizationFactory();

	Visualization* createVisualization(GameObject* object);
};

#endif