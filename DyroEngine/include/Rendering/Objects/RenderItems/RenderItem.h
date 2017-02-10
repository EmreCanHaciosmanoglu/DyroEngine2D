#ifndef _RENDERITEM_H
#define _RENDERITEM_H

#include "Core/Helpers/TaggedObject.h"

#ifndef _VECTOR2D_H
#include "Math/Objects/Vector2D.h"
#endif
#ifndef _RECT2D_H
#include "Math\Objects\Rect2D.h"
#endif
#ifndef _MATRIX2D_H
#include "Math/Objects/Matrix2D.h"
#endif

class Renderer;
class Layer;

class RenderItem : public TaggedObject<RenderItem>
{
public:
	RenderItem(const std::tstring& name = _T("RenderItem"));
	virtual ~RenderItem();

	virtual void render(Renderer* renderer) = 0;
	
	void setLayer(Layer* layer);
	void setTransform(const Vector2D& position, const Vector2D& scale, float rotation);
	void setTransform(const Matrix2D& transform);

	virtual bool isTransparant() const = 0;
	virtual Rect2D getBounds() const = 0;

	virtual float getWidth() const = 0;
	virtual float getHeight() const = 0;

	Layer* getLayer() const;

	const Vector2D& getPosition() const;
	const Vector2D& getScale() const;
	float getRotation() const;

	const Matrix2D& getTransform() const;

private:
	Layer* layer;
	Matrix2D transform;

	Vector2D position;
	Vector2D scale;
	float rotation;
};

#endif