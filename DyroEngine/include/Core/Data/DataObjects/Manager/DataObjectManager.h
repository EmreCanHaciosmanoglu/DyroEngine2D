#ifndef _DATAOBJECTMANAGER_H
#define _DATAOBJECTMANAGER_H

#include "Helpers/Manager.h"

#ifndef _STRING_H
#include "Defines/string.h"
#endif

#ifndef _VECTOR_
	#include <vector>
#endif

class DataObject;
class Visualization;

class DataObjectManager : public Manager
{
public:
	DataObjectManager();
	virtual ~DataObjectManager();

	virtual bool initialize();
	virtual bool shutdown();

	void addDataObject(DataObject* object);
	void removeDataObject(DataObject* object);

	Visualization* getVisualization(DataObject* dataObject) const;
	Visualization* getVisualization(const std::tstring& dataObjectName) const;
	Visualization* getVisualization(unsigned int id) const;
	const std::vector<Visualization*>& getVisualizations() const;

	DataObject* getDataObject(unsigned int id) const;
	DataObject* getDataObject(const std::tstring& name) const;
	const std::vector<DataObject*>& getDataObjects() const;

	const std::vector<DataObject*> getDataObjectsOfType(const std::vector<std::tstring>& types) const;
	const std::vector<DataObject*> getDataObjectsOfType(const std::tstring& type) const;

private:
	std::vector<Visualization*> vec_visualizations;
	std::vector<DataObject*> vec_dataobjects;
};

#endif