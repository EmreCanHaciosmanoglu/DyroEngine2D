#ifndef _ABSTRACTSCENEFACTORY_H
#define _ABSTRACTSCENEFACTORY_H

#ifndef _ASSERT_H
#include "Core/Defines/assert.h"
#endif
#ifndef _STRING_H
#include "Core/Defines/string.h"
#endif

class Scene;

class AbstractSceneFactory
{
public:
	AbstractSceneFactory();
	virtual ~AbstractSceneFactory();

	virtual Scene* createScene(const std::tstring& sceneName) const = 0;

private:
};

#endif