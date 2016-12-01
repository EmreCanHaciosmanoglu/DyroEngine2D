#include "SceneGraph/Component/ImageComponent.h"
#include "SceneGraph\Component\TransformComponent.h"

#include "SceneGraph/Object/GameObjects/GameObject.h"
#include "SceneGraph/Scene/Scene.h"

#include "Core/Rendering/Renderer.h"

#include "Core/Resources/Image.h"

ImageComponent::ImageComponent(Image* image, const std::tstring& name)
	:Component(name == _T("") ? _T("ImageComponent") : name)
	,image(image)
	,transform(nullptr)
{}
ImageComponent::~ImageComponent()
{}

bool ImageComponent::initialize()
{
	this->transform = getParent()->getComponent<TransformComponent>();

	//Transform on a camera cannot be null
	assert(transform != nullptr);

	return true;
}
void ImageComponent::update()
{

}
void ImageComponent::draw()
{
	Renderer* renderer = getParent()->getScene()->getManager<Renderer>();

	this->image->getClip() != Rect2D::empty
		? renderer->drawBitmap(image, this->image->getClip())
		: renderer->drawBitmap(image);
}
bool ImageComponent::shutdown()
{
	return true;
}

void ImageComponent::centerImage()
{
	this->transform->center(-this->image->getWidth() / 2.0f, -this->image->getHeight() / 2.0f);
}
void ImageComponent::resetCenter()
{
	this->transform->resetCenter();
}

void ImageComponent::mirrorImageX()
{
	this->transform->mirrorX();
}
void ImageComponent::mirrorImageY()
{
	this->transform->mirrorY();
}
void ImageComponent::resetMirror(bool x, bool y)
{
	this->transform->resetMirror(x, y);
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

Rect2D ImageComponent::getBoundingBox() const
{
	TransformComponent* transform = getParent()->getComponent<TransformComponent>();

	Vector2D scale(1, 1);
	if (transform != nullptr)
		scale = transform->getScale();

	Rect2D bounding_rect = Rect2D::empty;

	bounding_rect = this->image->getBoundingBox();
	bounding_rect.right = bounding_rect.right * scale.x;
	bounding_rect.bottom = bounding_rect.bottom * scale.y;

	return bounding_rect;
}