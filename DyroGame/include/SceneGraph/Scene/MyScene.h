#ifndef _MYSCENE_H
#define _MYSCENE_H

#include "SceneGraph/Scene/Scene.h"

class SceneObject;
class Input;
class FreeCamera;

class MyScene : public Scene
{
public:
	MyScene();
	virtual ~MyScene();

	virtual bool initialize();
	virtual void update();
	virtual bool shutdown();

	virtual void setupInput(Input* input);

	void changeColorRectangle();
	void changeColorCircle();

	void mirrorXImage();
	void mirrorYImage();	
	void centerImage();
	void resetImage();

	void nextImage();
	void previousImage();
	void randomImage();

private:
	static const int CIRCLE_AMOUNT = 100;
	static const int IMAGE_PATH_AMOUNT = 15;

	float animated_angle;

	FreeCamera* camera;

	SceneObject* rectangle;
	SceneObject* circles[CIRCLE_AMOUNT];

	SceneObject* object;

	std::tstring image_paths[IMAGE_PATH_AMOUNT];
	int current_image;
};

#endif