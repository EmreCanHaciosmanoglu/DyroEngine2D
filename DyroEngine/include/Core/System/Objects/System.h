#ifndef _SYSTEM_H
#define _SYSTEM_H

enum class SystemType;

class System
{
public:
	System(SystemType type);
	virtual ~System();

	virtual bool initialize() = 0;
	virtual void update() = 0;
	virtual bool shutdown() = 0;

	void activate();
	void deactivate();

	bool getIsActive() const;

	SystemType getType() const;

private:
	SystemType system_type;
	bool active;
};

#endif // _SYSTEM_H
