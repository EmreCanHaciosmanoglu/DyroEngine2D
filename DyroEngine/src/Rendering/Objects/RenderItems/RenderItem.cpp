#include "Rendering/Objects/RenderItems/RenderItem.h"

#include "Core\Data\Objects\Layer.h"

RenderItem::RenderItem(const std::tstring& name)
	:TaggedObject<RenderItem>(name)
	, layer(nullptr)
	, transform(Matrix2D::createIdentityMatrix())

	,position(0.0f, 0.0f)
	,scale(0.0f, 0.0f)
	,rotation(0.0f)
{
}
RenderItem::~RenderItem()
{
}

void RenderItem::setLayer(Layer* layer)
{
	this->layer = layer;
}
Layer* RenderItem::getLayer() const
{
	return this->layer;
}

void RenderItem::setTransform(const Vector2D& position, const Vector2D& scale, float rotation)
{
	this->position = position;
	this->scale = scale;
	this->rotation = rotation;

	Matrix2D mat_translate = Matrix2D::createTranslationMatrix(position);
	Matrix2D mat_scale = Matrix2D::createScalingMatrix(scale);
	Matrix2D mat_rotate = Matrix2D::createRotationMatrix(rotation);

	this->transform = mat_scale * mat_rotate * mat_translate;
}

const Vector2D& RenderItem::getPosition() const
{
	return this->position;
}
const Vector2D& RenderItem::getScale() const
{
	return this->scale;
}
float RenderItem::getRotation() const
{
	return this->rotation;
}

const Matrix2D& RenderItem::getTransform() const
{
	return this->transform;
}