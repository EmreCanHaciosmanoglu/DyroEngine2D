#ifndef _LAYERMANAGER_H
#define _LAYERMANAGER_H

#include "Core/Helpers/Patterns/Manager.h"
#include "Core/Helpers/Patterns/Singleton.h"

#include "Core\Data\Objects\Layer.h"

class LayerManager : public Manager<Layer>, public Singleton<LayerManager>
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