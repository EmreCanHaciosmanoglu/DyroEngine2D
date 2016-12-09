#ifndef _MANAGER_H
#define _MANAGER_H

#ifndef _STRING_H
	#include "Defines/string.h"
#endif

#ifndef _VECTOR_
	#include <vector>
#endif
#ifndef _MAP_
	#include <map>	
#endif
#ifndef _ALGORITHM_
	#include <algorithm>
#endif

class AbstractManager
{
public:
	AbstractManager();
	virtual ~AbstractManager();

	virtual bool initialize() = 0;
	virtual bool shutdown() = 0;
};

template <typename T>
class Manager : public AbstractManager
{
public:
	Manager();
	virtual ~Manager();

	virtual bool initialize() = 0;
	virtual bool shutdown() = 0;

protected:
	virtual void addObject(unsigned int id, T* object);

	virtual void removeObject(unsigned int id);
	virtual void removeObject(T* object);

	T* getObject(unsigned int id) const;
	std::vector<T*> getObjects() const;

	std::map<unsigned int, T*> map_objects;

private:
	typename std::map<unsigned int, T*>::const_iterator& getIteratorWithID(unsigned int id) const;
	typename std::map<unsigned int, T*>::const_iterator& getIteratorWithObject(T* object) const;
};
template <typename T>
Manager<T>::Manager()
{}
template <typename T>
Manager<T>::~Manager()
{
	this->map_objects.clear();
}

template <typename T>
void Manager<T>::addObject(unsigned int id, T* object)
{
	if (typename getIteratorWithID<T>(id) != this->map_objects.end())
		return;

	this->map_objects[id] = object;
}

template <typename T>
void Manager<T>::removeObject(T* object)
{
	typename std::map<unsigned int, T*>::const_iterator it = getIteratorWithObject<T>(object);
	if (it == this->map_objects.end())
		return;

	this->map_objects.erase(it);
	SafeDelete((*it));
}
template <typename T>
void Manager<T>::removeObject(unsigned int id)
{
	typename std::map<unsigned int, T*>::const_iterator it = getIteratorWithID<T>(id);
	if (it == this->map_objects.end())
		return;

	this->map_objects.erase(it);
	SafeDelete((*it).second);
}

template <typename T>
T* Manager<T>::getObject(unsigned int id) const
{
	typename std::map<unsigned int, T*>::const_iterator it = getIteratorWithID<T>(id);
	if (it == this->map_objects.end())
		return nullptr;

	return (*it);
}
template <typename T>
std::vector<T*> Manager<T>::getObjects() const
{
	std::vector<T*> objects(this->map_objects.size(), nullptr);
	for (std::map<unsigned int, T*>::const_iterator it = this->map_objects.begin(); it != this->map_objects.end(); ++it)
		objects.push_back((*it).second);

	return objects;
}

template <typename T>
typename std::map<unsigned int, T*>::const_iterator& Manager<T>::getIteratorWithID(unsigned int id) const
{
	std::map<unsigned int, T*>::const_iterator it = std::find_if(this->map_objects.begin(), this->map_objects.end(),
		[id](std::pair<unsigned int, T*> pair)
	{
		return id == pair.first;
	});

	return it;
}
template <typename T>
typename std::map<unsigned int, T*>::const_iterator& Manager<T>::getIteratorWithObject(T* object) const
{
	std::map<unsigned int, T*>::const_iterator it = std::find_if(this->map_objects.begin(), this->map_objects.end(),
		[object](std::pair<unsigned int, T*> pair)
	{
		return object == pair.second;
	});

	return it;
}

#endif //_MANAGER_H

