#ifndef _LAYERMANAGER_H
#define _LAYERMANAGER_H

#include "Helpers\Manager.h"

class Layer;

class LayerManager : public Manager<Layer>
{
public:
	LayerManager();
	virtual ~LayerManager();

	virtual bool initialize();
	virtual bool shutdown();

	void addLayer(Layer* layer);

	void removeLayer(Layer* layer);
	void removeLayer(const std::tstring& name);
	void removeLayer(unsigned int id);

	Layer* getLayer(const std::tstring& name);
	Layer* getLayer(unsigned int id);

	void getLayers(std::vector<Layer*>& layers);
};
#endif