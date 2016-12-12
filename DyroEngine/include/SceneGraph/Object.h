#ifndef _OBJECT_H
#define _OBJECT_H

#include "Helpers/ObjectCounter.h"

#ifndef _STRING_H
#include "Defines/string.h"
#endif

#ifndef _VECTOR_H
#include <vector>
#endif

// Macro for the hard coded methods.
#define OBJECT_STATICS( class_type_id ) \
    public: \
    static const std::tstring getClassTypeId() { return _T( class_type_id ); } \
    virtual const std::tstring getTypeId() const { return _T( class_type_id ); }

class Object : public ObjectCounter<Object>
{
	/**
	\note Must be present in every subclass definition.
	*/
	OBJECT_STATICS("Object")

public:
	Object(const std::tstring& name = _T(""));
	virtual ~Object();

	virtual bool initialize() = 0;
	virtual bool postInitialize() = 0;
	virtual bool shutdown() = 0;

	bool isOfType(const std::tstring& classTypeId) const;
	const std::vector<std::tstring>& getInheritanceList() const;
	unsigned int getObjectID() const;

	void setInitialized();
	bool getInitialized();
	void setPostInitialized();
	bool getPostInitialized();

	virtual void activate();
	virtual void deactive();
	bool isActive();

	virtual void destroy();
	bool isDestroyed() const;

	void setName(const std::tstring& name);
	const std::tstring& getName() const;

protected:
	void OBJECT_INIT(const std::tstring& classTypeId);

	template<typename T>
	const std::tstring generateUniqueName(const std::tstring& partialName)
	{
		return partialName + TOSTRING(ObjectCounter<T>::getAmount());
	}

private:
	unsigned int id;

	bool active;

	bool initialized;
	bool post_initialized;
	bool destroyed;

	std::tstring name;
	std::vector<std::tstring> inheritance_list;
};

#endif //_OBJECT_H

