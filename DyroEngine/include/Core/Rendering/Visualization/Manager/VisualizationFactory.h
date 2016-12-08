#ifndef _VISUALIZATIONFACTORY_H
#define _VISUALIZATIONFACTORY_H

class DataObject;
class Visualization;

class VisualizationFactory
{
	VisualizationFactory();
	~VisualizationFactory();

	Visualization* createVisualization(DataObject* object);
};

#endif