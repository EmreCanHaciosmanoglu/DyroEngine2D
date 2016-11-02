#ifndef _TRANSFORMCOMPONENT_H
#define _TRANSFORMCOMPONENT_H

#include "SceneGraph\Component\Component.h"

#include "Helpers\Math\Matrix2D.h"
#include "Helpers\Math\Vector2D.h"

class TransformComponent :	public Component
{
public:
	TransformComponent(const std::tstring& name = _T(""));
	virtual ~TransformComponent();

	virtual bool initialize();
	virtual void update();
	virtual bool shutdown();

	void translate(const Vector2D& translation);
	void scale(const Vector2D& scale);
	void rotate(float rotation);

	void setPosition(const Vector2D& position);
	void setScale(const Vector2D& scale);
	void setRotation(float angle);

	const Vector2D& getPosition() const;
	const Vector2D& getScale() const;
	float getRotation() const;

	const Matrix2D& getWorldMatrix() const;

private:
	bool is_dirty;

	Vector2D position;
	Vector2D scaling;
	float rotation;

	Matrix2D world_matrix;
};

#endif