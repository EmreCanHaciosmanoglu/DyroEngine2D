#ifndef _IDESTROYABLE_H
#define _IDESTROYABLE_H

class IDestroyable
{
	virtual void destroy() = 0;
	virtual bool isDestroyed() const = 0;

protected:
	IDestroyable()
		:destroyed(false)
	{}
	virtual ~IDestroyable()
	{}

	bool destroyed;
};

#endif