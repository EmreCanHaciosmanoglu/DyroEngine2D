#include "Rendering/Objects/Visualization/ComponentVisualizations/ImageVisualization.h"
#include "Rendering\Manager\VisualizationManager.h"

#include "Rendering/Objects/RenderItems/Texture.h"

#include "SceneGraph\Objects\Components\ImageComponent.h"

#include "Core/Defines\deletemacros.h"

ImageVisualization::ImageVisualization(Component* component, const std::tstring& name)
	:ComponentVisualization(component, name)
	, texture(nullptr)
{}
ImageVisualization::~ImageVisualization()
{
	SafeDelete(this->texture);
}

void ImageVisualization::generateRenderItems(std::vector<RenderItem*>& items)
{
	ImageComponent* component = dynamic_cast<ImageComponent*>(getObject());
	if (component == nullptr)
		return;

	Image* image = component->getImage();

	if (this->texture == nullptr)
		this->texture = new Texture(image);
	else if (this->texture->getImage() != image)
	{
		SafeDelete(this->texture);
		this->texture = new Texture(image);
	}

	///items.push_back(this->texture);
}