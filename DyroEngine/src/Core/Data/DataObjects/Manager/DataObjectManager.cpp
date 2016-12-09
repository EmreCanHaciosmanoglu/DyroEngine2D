#include "Core/Data/DataObjects/Manager/DataObjectManager.h"
#include "Core/Data/DataObjects/DataObject.h"

#include "Core/Rendering/Visualization/Manager/VisualizationFactory.h"
#include "Core/Rendering/Visualization/Visualization.h"

#include "Helpers/Singleton.h"

#include "Interfaces/IRenderable.h"

#include "Defines/deletemacros.h"

#include <algorithm>

DataObjectManager::DataObjectManager()
{

}
DataObjectManager::~DataObjectManager()
{

}

bool DataObjectManager::initialize()
{
	return true;
}
bool DataObjectManager::shutdown()
{
	for (DataObject* object : this->vec_dataobjects)
		SafeDelete(object);
	this->vec_dataobjects.clear();

	return true;
}

void DataObjectManager::addDataObject(DataObject* object)
{
	std::vector<DataObject*>::const_iterator it = std::find(this->vec_dataobjects.begin(), this->vec_dataobjects.end(), object);
	if (it != this->vec_dataobjects.end())
		return;

	this->vec_dataobjects.push_back(object);

	if (dynamic_cast<IRenderable*>(object) != nullptr)
	{
		Visualization* visualization = Singleton<VisualizationFactory>::getInstance().createVisualization(object);
		this->vec_visualizations.push_back(visualization);
	}
}
void DataObjectManager::removeDataObject(DataObject* object)
{
	std::vector<DataObject*>::const_iterator it = std::find(this->vec_dataobjects.begin(), this->vec_dataobjects.end(), object);
	if (it == this->vec_dataobjects.end())
		return;

	if (dynamic_cast<IRenderable*>(object) != nullptr)
	{
		Visualization* visualization = getVisualization(object);
		if (visualization != nullptr)
		{
			std::vector<Visualization*>::const_iterator it = std::find(this->vec_visualizations.begin(), this->vec_visualizations.end(), visualization);
			if (it != this->vec_visualizations.end())
			{
				this->vec_visualizations.erase(it);
				SafeDelete(visualization);
			}
		}
	}

	this->vec_dataobjects.erase(it);
	SafeDelete(object);
}

Visualization* DataObjectManager::getVisualization(DataObject* dataObject) const
{
	if (dataObject == nullptr)
		return nullptr;

	std::vector<Visualization*>::const_iterator it = std::find_if(this->vec_visualizations.begin(), this->vec_visualizations.end(),
		[dataObject](const Visualization* visualization) -> bool
	{
		return dataObject == visualization->getDataObject();
	});

	if (it == this->vec_visualizations.end())
		return nullptr;

	return (*it);
}
Visualization* DataObjectManager::getVisualization(const std::tstring& dataObjectName) const
{
	return getVisualization(getDataObject(dataObjectName));
}
Visualization* DataObjectManager::getVisualization(unsigned int id) const
{
	return getVisualization(getDataObject(id));
}
const std::vector<Visualization*>& DataObjectManager::getVisualizations() const
{
	return this->vec_visualizations;
}

DataObject* DataObjectManager::getDataObject(unsigned int id) const
{
	std::vector<DataObject*>::const_iterator it = std::find_if(this->vec_dataobjects.begin(), this->vec_dataobjects.end(),
		[id](DataObject* object) -> bool
	{
		return id == object->getID();
	});

	if (it == this->vec_dataobjects.end())
		return nullptr;

	return (*it);
}
DataObject* DataObjectManager::getDataObject(const std::tstring& name) const
{
	std::vector<DataObject*>::const_iterator it = std::find_if(this->vec_dataobjects.begin(), this->vec_dataobjects.end(),
		[name](DataObject* object) -> bool
	{
		return name == object->getName();
	});

	if (it == this->vec_dataobjects.end())
		return nullptr;

	return (*it);
}
const std::vector<DataObject*>& DataObjectManager::getDataObjects() const
{
	return this->vec_dataobjects;
}

const std::vector<DataObject*> DataObjectManager::getDataObjectsOfType(const std::vector<std::tstring>& types) const
{
	std::vector<DataObject*> objects;
	for (DataObject* object : this->vec_dataobjects)
	{
		for (const std::tstring& type : types)
		{
			if (!object->isOfType(type))
				continue;

			objects.push_back(object);
		}
	}

	return objects;
}
const std::vector<DataObject*> DataObjectManager::getDataObjectsOfType(const std::tstring& type) const
{
	std::vector<DataObject*> objects;
	for (DataObject* object : this->vec_dataobjects)
	{
		if (!object->isOfType(type))
			continue;
		
		objects.push_back(object);
	}

	return objects;
}

