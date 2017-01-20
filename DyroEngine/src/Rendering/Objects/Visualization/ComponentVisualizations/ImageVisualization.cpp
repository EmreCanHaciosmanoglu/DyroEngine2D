#include "Rendering/Objects/Visualization/ComponentVisualizations/ImageVisualization.h"
#include "Rendering/Objects/Visualization/GameObjectVisualizations/GameObjectVisualization.h"
#include "Rendering/Objects/RenderItems/Texture.h"
#include "Rendering\Manager\VisualizationManager.h"
#include "Rendering\Manager\TextureManager.h"

#include "SceneGraph\Objects\GameObjects\SceneObject.h"

#include "SceneGraph\Objects\Components\ImageComponent.h"
#include "SceneGraph\Objects\Scenes\Scene.h"

#include "Core/Defines\deletemacros.h"

ImageVisualization::ImageVisualization(Component* object, const std::tstring& name)
	:ConcreteComponentVisualization(object, name)
	, texture(nullptr)
{

}
ImageVisualization::~ImageVisualization()
{
}

bool ImageVisualization::initialize()
{
	ImageComponent* component = dynamic_cast<ImageComponent*>(getObject());
	if (component == nullptr)
		return false;

	this->texture = getScene()->getManager<TextureManager>()->getTexture(component->getImage());

	if (this->texture == nullptr)
	{
		this->texture = new Texture(this, component->getImage());
		getScene()->getManager<TextureManager>()->addTexture(this->texture);
	}

	return true;
}
bool ImageVisualization::shutdown()
{
	return true;
}

void ImageVisualization::generateRenderItems(std::vector<RenderItem*>& items)
{
	ImageComponent* component = getConcreteComponent();

	if (this->texture->getImage() != component->getImage())
		this->texture = TextureManager::getInstance().getTexture(component->getImage());

	GameObjectVisualization* parent = dynamic_cast<GameObjectVisualization*>(getParent());
	if (parent != nullptr)
	{
		SceneObject* parent_object = dynamic_cast<SceneObject*>(parent->getObject());

		//Since an image will get renderer from his top corner we will need to center the image in order to achieve correct visuals.
		Vector2D center = Vector2D(this->texture->getWidth() / 2, this->texture->getHeight() / 2);

		this->texture->setTransform(parent->getPosition() - center, parent->getScale(), parent->getRotation());
		this->texture->setLayer(parent_object->getLayer());
	}

	items.push_back(this->texture);
}