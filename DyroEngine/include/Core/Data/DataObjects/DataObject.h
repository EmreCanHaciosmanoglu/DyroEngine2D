#ifndef _DATAOBJECT_H
#define _DATAOBJECT_H

#include "Helpers/ObjectCounter.h"

#ifndef _STRING_H
#include "Defines/string.h"
#endif
#ifndef _VECTOR_
#include <vector>
#endif

// Macro for the hard coded methods.
#define DATA_OBJECT_STATICS( class_type_id ) \
    public: \
    static const std::tstring getClassTypeId() { return _T( class_type_id ); } \
    virtual const std::tstring getTypeId() const { return _T( class_type_id ); }

class DataObject : public ObjectCounter<DataObject>
{
	/**
	\note Must be present in every subclass definition.
	*/
	DATA_OBJECT_STATICS("DataObject")

public:
	DataObject(const std::tstring& name =_T(""));
	virtual ~DataObject();

	bool isOfType(const std::tstring& classTypeId) const;
	/** returns the list of object types in the order that the constructors are called. The list starts with the type "DataObject". */
	const std::vector<std::tstring>& getInheritanceList() const;

	void setName(const std::tstring& name);
	const std::tstring& getName() const;

	unsigned int getID() const;

protected:
	/**
	\note Must be called in the constructor of every subclass for inheritance checking to work.
	*/
	void DATA_OBJECT_INIT(const std::tstring& classTypeId);

private:
	template<typename T>
	const std::tstring generateUniqueName(const std::tstring& partialName)
	{
		return partialName + TOSTRING(ObjectCounter<T>::getAmount());
	}

	unsigned int id;
	std::tstring name;
	std::vector<std::tstring> inheritance_list;
};

#endif