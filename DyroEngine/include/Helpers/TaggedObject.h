#ifndef _TaggedObject_H
#define _TaggedObject_H

#include "Helpers\Patterns/ObjectCounter.h"

#ifndef _STRING_H
#include "Defines\string.h"
#endif

template <typename T>
class TaggedObject : public ObjectCounter<T>
{
public:
	TaggedObject(const std::tstring& name);
	virtual ~TaggedObject();

	unsigned int getID();

	void setName(const std::tstring& name);
	const std::tstring& getName() const;

	static std::tstring BASE_NAME;

private:
	std::tstring generateUniqueName(const std::tstring& baseName = TaggedObject<T>::BASE_NAME);

	unsigned int id;
	std::tstring name;
};

template <typename T>
std::tstring TaggedObject<T>::BASE_NAME = _T("Object");

template <typename T>
TaggedObject<T>::TaggedObject(const std::tstring& name)
	:id(ObjectCounter<T>::getAmount())
	, name(name == _T("") ? generateUniqueName(_T("Object")) : name)
{}
template <typename T>
TaggedObject<T>::~TaggedObject()
{}

template <typename T>
unsigned int TaggedObject<T>::getID()
{
	return this->id;
}

template <typename T>
void TaggedObject<T>::setName(const std::tstring& name)
{
	this->name = name;
}
template <typename T>
const std::tstring& TaggedObject<T>::getName() const
{
	return this->name;
}

template <typename T>
std::tstring TaggedObject<T>::generateUniqueName(const std::tstring& baseName)
{
	return std::tstring(baseName + TOSTRING(this->id));
}

#endif