#ifndef _ENGINESTATETYPE_H
#define _ENGINESTATETYPE_H

class EngineState
{
public:
	enum class EngineStateType
	{
		CREATING,
		RUNNING,
		DESTROYING,
		INVALID
	};

	//Defined in "Engine.cpp"
	static EngineStateType ENGINE_STATE;
};

#endif