#ifndef _SCENEFACTORY_H
#define _SCENEFACTORY_H

#include "SceneGraph\Factory\AbstractSceneFactory.h"

class SceneFactory : public AbstractSceneFactory
{
public:
	SceneFactory();
	virtual ~SceneFactory();

	Scene* createScene(const std::tstring& sceneTypeID) const;

private:
};

#endif 