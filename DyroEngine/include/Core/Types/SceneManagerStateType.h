#ifndef _SCENEMANAGERSTATETYPE_H
#define _SCENEMANAGERSTATETYPE_H

class SceneManagerState
{
public:
	enum class SceneManagerStateType
	{
		INITIALIZE,
		UPDATE,
		SHUTDOWN,
		INVALID
	};

	//Defined in "SceneManager.cpp"
	static SceneManagerStateType SCENEMANAGER_STATE;
};

#endif