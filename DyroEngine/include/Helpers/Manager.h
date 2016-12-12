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
	virtual bool initialize() = 0;
	virtual bool shutdown() = 0;

protected:
	AbstractManager() {};
	virtual ~AbstractManager() {};
};

template <typename T>
class Manager : public AbstractManager
{
public:
	Manager();
	virtual ~Manager();

	virtual bool initialize() = 0;
	virtual bool shutdown() = 0;

	bool exists(unsigned int id);
	bool exists(GameObject* object);

protected:
	virtual bool addObject(unsigned int id, T* object);

	virtual bool removeObject(unsigned int id);
	virtual bool removeObject(T* object);

	T* getObject(unsigned int id) const;
	
	void getObjects(std::vector<T*>& objects);
	void getObjects(std::map<unsigned int, T*>& objects);

private:
	std::map<unsigned int, T*> map_objects;

	typename std::map<unsigned int, T*>::const_iterator getIteratorWithID(unsigned int id) const;
	typename std::map<unsigned int, T*>::const_iterator getIteratorWithObject(T* object) const;
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
bool Manager<T>::exists(unsigned int id)
{
	return getIteratorWithID(id) != this->map_objects.end();
}
template <typename T>
bool Manager<T>::exists(T* object)
{
	return getIteratorWithObject(object) != this->map_objects.end();
}

template <typename T>
bool Manager<T>::addObject(unsigned int id, T* object)
{
	if (getIteratorWithID(id) != this->map_objects.end())
		return false;

	this->map_objects[id] = object;
	return true;
}

template <typename T>
bool Manager<T>::removeObject(T* object)
{
	std::map<unsigned int, T*>::const_iterator it = getIteratorWithObject(object);
	if (it == this->map_objects.end())
		return false;

	this->map_objects.erase(it);
	return true;
}
template <typename T>
bool Manager<T>::removeObject(unsigned int id)
{
	std::map<unsigned int, T*>::const_iterator it = getIteratorWithID(id);
	if (it == this->map_objects.end())
		return false;

	this->map_objects.erase(it);
	return true;
}

template <typename T>
T* Manager<T>::getObject(unsigned int id) const
{
	std::map<unsigned int, T*>::const_iterator it = getIteratorWithID(id);
	if (it == this->map_objects.end())
		return nullptr;

	return (*it).second;
}

template <typename T>
void Manager<T>::getObjects(std::vector<T*>& objects)
{
	for (std::map<unsigned int, T*>::const_iterator it = this->map_objects.begin(); it != this->map_objects.end(); ++it)
		objects.push_back((*it).second);
}
template <typename T>
void Manager<T>::getObjects(std::map<unsigned int, T*>& objects)
{
	objects = this->map_objects;
}

template <typename T>
typename std::map<unsigned int, T*>::const_iterator Manager<T>::getIteratorWithID(unsigned int id) const
{
	std::map<unsigned int, T*>::const_iterator it = std::find_if(this->map_objects.begin(), this->map_objects.end(),
		[id](std::pair<unsigned int, T*> pair)
	{
		return id == pair.first;
	});

	return it;
}
template <typename T>
typename std::map<unsigned int, T*>::const_iterator Manager<T>::getIteratorWithObject(T* object) const
{
	std::map<unsigned int, T*>::const_iterator it = std::find_if(this->map_objects.begin(), this->map_objects.end(),
		[object](std::pair<unsigned int, T*> pair)
	{
		return object == pair.second;
	});

	return it;
}

#endif //_MANAGER_H

