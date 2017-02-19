#include "SceneGraph/Objects/GameObjects/UI/UIObject.h"
#include "SceneGraph/Objects/Scenes/Scene.h"

#include "Core/Data/Manager/LayerManager.h"

UIObject::UIObject(const std::tstring& name)
	:SceneObject(name)
{
	OBJECT_INIT(_T("UIObject"));
}
UIObject::~UIObject()
{}

bool UIObject::initialize()
{
	setLayer(getScene()->getManager<LayerManager>()->getLayer(_T("UI")));
	
	return GameObject::initialize();
}
void UIObject::upddate()
{
	SceneObject::update();
}
bool UIObject::shutdown()
{
	return SceneObject::shutdown();
}