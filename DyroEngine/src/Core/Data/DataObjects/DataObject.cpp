#include "Core\Data\DataObjects\DataObject.h"

#include "Helpers/Singleton.h"

#include "Diagnostics/Logger.h"

#include <algorithm>

DataObject::DataObject(const std::tstring& name)
	:id(ObjectCounter<DataObject>::getAmount())
	,name(name == _T("") ? generateUniqueName<DataObject>(_T("DataObject_")) : name)
{
	DATA_OBJECT_INIT(_T("DataObject"));
}
DataObject::~DataObject()
{

}

bool DataObject::isOfType(const std::tstring& classTypeId) const
{
	return std::find(this->inheritance_list.begin(), this->inheritance_list.end(), classTypeId) != this->inheritance_list.end();
}

const std::vector<std::tstring>& DataObject::getInheritanceList() const
{
	return this->inheritance_list;
}

void DataObject::setName(const std::tstring& name)
{
	this->name = name;
}
const std::tstring& DataObject::getName() const
{
	return this->name;
}

unsigned int DataObject::getID() const
{
	return this->id;
}

void DataObject::DATA_OBJECT_INIT(const std::tstring& classTypeId)
{
	std::vector<std::tstring>::const_iterator it = std::find(this->inheritance_list.begin(), this->inheritance_list.end(), classTypeId);
	if (it != this->inheritance_list.end())
	{
		Singleton<Logger>::getInstance().log(_T("DataObject : duplicate class type id detected; ignored:") + classTypeId, LOGTYPE_INFO);
		return;
	}

	this->inheritance_list.push_back(classTypeId);
}

