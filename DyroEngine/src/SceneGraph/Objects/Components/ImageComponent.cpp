#include "SceneGraph/Objects/Components/ImageComponent.h"

#include "SceneGraph/Objects/GameObjects/GameObject.h"
#include "SceneGraph/Objects/Scenes/Scene.h"

#include "Rendering/Renderer.h"

#include "Core/Data/Objects/Resources/Image.h"

ImageComponent::ImageComponent(Image* image, const std::tstring& name)
	:Component(name == _T("") ? _T("ImageComponent") : name)
	, image(image)
{
	OBJECT_INIT(_T("ImageComponent"));
}
ImageComponent::~ImageComponent()
{}

bool ImageComponent::initialize()
{
	return true;
}
void ImageComponent::update()
{
}
bool ImageComponent::shutdown()
{
	return true;
}

void ImageComponent::setTransparencyColor(const Color& color)
{
	this->image->setTransparencyColor(color);
}

void ImageComponent::setImage(Image* image)
{
	this->image = image;
}
Image* ImageComponent::getImage() const
{
	return this->image;
}

void ImageComponent::setOpacity(float o)
{
	this->image->setOpacity(o);
}
float ImageComponent::getOpacity() const
{
	return this->image->getOpacity();
}

void ImageComponent::setClip(const Rect2D& c)
{
	this->image->setClip(c);
}
const Rect2D& ImageComponent::getClip() const
{
	return this->image->getClip();
}