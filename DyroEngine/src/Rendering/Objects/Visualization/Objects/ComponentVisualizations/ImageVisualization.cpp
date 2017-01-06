#include "Rendering/Objects/Visualization/ComponentVisualizations/ImageVisualization.h"
#include "Rendering\Manager\VisualizationManager.h"

#include "Rendering/Objects/RenderItems/Texture.h"

#include "SceneGraph\Objects\Components\ImageComponent.h"

#include "Core/Defines\deletemacros.h"

ImageVisualization::ImageVisualization(Component* object, const std::tstring& name)
	:ComponentVisualization(object, name)
	, texture(nullptr)
{
	ImageComponent* component = dynamic_cast<ImageComponent*>(object);
	if (component == nullptr)
		return;

	this->texture = new Texture(component->getImage());
}
ImageVisualization::~ImageVisualization()
{
	SafeDelete(this->texture);
}

void ImageVisualization::generateRenderItems(std::vector<RenderItem*>& items)
{
	ImageComponent* component = dynamic_cast<ImageComponent*>(object);
	if (component == nullptr)
		return;

	if (this->texture->getImage() != component->getImage())
	{
		SafeDelete(this->texture);
		this->texture = new Texture(component->getImage());
	}

	items.push_back(this->texture);
}