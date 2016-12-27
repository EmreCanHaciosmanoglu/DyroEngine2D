#include "Core\Data\Manager\LayerManager.h"
#include "Core\Data\Objects\Layer.h"

#include <algorithm>

LayerManager::LayerManager()
{}
LayerManager::~LayerManager()
{}

bool LayerManager::initialize()
{
	return true;
}
bool LayerManager::shutdown()
{
	std::vector<Layer*> layers;
	getObjects(layers);

	for (Layer* layer : layers)
		delete layer;
}

void LayerManager::addLayer(Layer* layer)
{
	addObject(layer->getID(), layer);
}

void LayerManager::removeLayer(Layer* layer)
{
	removeObject(layer);
}
void LayerManager::removeLayer(const std::tstring& name)
{
	std::vector<Layer*> layers;
	getObjects(layers);

	std::vector<Layer*>::const_iterator it = std::find_if(layers.begin(), layers.end(),
		[name](Layer* layer) -> bool
	{
		return layer->getName() == name;
	});

	if (it == layers.end())
		return;

	removeObject((*it)->getID());
}
void LayerManager::removeLayer(unsigned int id)
{
	removeObject(id);
}

Layer* LayerManager::getLayer(const std::tstring& name)
{
	std::vector<Layer*> layers;
	getObjects(layers);

	std::vector<Layer*>::const_iterator it = std::find_if(layers.begin(), layers.end(),
		[name](Layer* layer) -> bool
	{
		return layer->getName() == name;
	});

	return *it;
}
Layer* LayerManager::getLayer(unsigned int id)
{
	return getObject(id);
}

void LayerManager::getLayers(std::vector<Layer*>& layers)
{
	getObjects(layers);
}