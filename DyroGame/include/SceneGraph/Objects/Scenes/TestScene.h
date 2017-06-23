#ifndef _TESTSCENE_H
#define _TESTSCENE_H

#include "SceneGraph/Objects/Scenes/Scene.h"

#ifndef _VECTOR2D_H
#include "Math/Objects/Vector2D.h"
#endif

#ifndef _SETTINGSDATA_H
#include "Core/Defines/settingsdata.h"
#endif

class Input;

class TestScene : public Scene
{
	OBJECT_STATICS("TestScene");

public:
	TestScene();
	virtual ~TestScene();

	virtual bool initialize();
	virtual void update();
	virtual bool shutdown();

	virtual void setupInput(Input* input);
	virtual void setupSettings(const SettingsData& settings);

private:
	void noDebugRendering();
	void debugOnlyRendering();
	void overlayDebugRendering();
};

#endif