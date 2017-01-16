#include "Rendering/Objects/Visualization/ComponentVisualizations/ImageVisualization.h"
#include "Rendering/Objects/Visualization/GameObjectVisualizations/GameObjectVisualization.h"
#include "Rendering/Objects/RenderItems/Texture.h"
#include "Rendering\Manager\VisualizationManager.h"
#include "Rendering\Manager\TextureManager.h"

#include "SceneGraph\Objects\GameObjects\SceneObject.h"

#include "Core/Helpers/Patterns/Singleton.h"

#include "SceneGraph\Objects\Components\ImageComponent.h"
#include "SceneGraph\Objects\Scenes\Scene.h"

#include "Core/Defines\deletemacros.h"

ImageVisualization::ImageVisualization(Component* object, const std::tstring& name)
	:ConcreteComponentVisualization(object, name)
	, texture(nullptr)
{
	ImageComponent* component = dynamic_cast<ImageComponent*>(object);
	if (component == nullptr)
		return;

	this->texture = getScene()->getManager<TextureManager>()->getTexture(component->getImage());

	if (this->texture == nullptr)
	{
		this->texture = new Texture(this, component->getImage());
		getScene()->getManager<TextureManager>()->addTexture(this->texture);
	}
}
ImageVisualization::~ImageVisualization()
{
}

void ImageVisualization::generateRenderItems(std::vector<RenderItem*>& items)
{
	ImageComponent* component = getConcreteComponent();

	if (this->texture->getImage() != component->getImage())
		this->texture = Singleton<TextureManager>::getInstance().getTexture(component->getImage());

	GameObjectVisualization* parent = dynamic_cast<GameObjectVisualization*>(getParent());
	if (parent != nullptr)
	{
		SceneObject* parent_object = dynamic_cast<SceneObject*>(parent->getObject());

		this->texture->setTransform(parent->getPosition(), parent->getScale(), parent->getRotation());
		this->texture->setLayer(parent_object->getLayer());
	}

	items.push_back(this->texture);
}