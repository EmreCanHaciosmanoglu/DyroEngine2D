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

	void mirrorX();
	void mirrorY();
	void resetMirror(bool x = true, bool y = true);

	void center(float xCenter, float yCenter);
	void center(const Vector2D& centerPosition);
	void resetCenter();

	void translate(const Vector2D& translation);
	void scale(const Vector2D& scale);
	void rotate(float rotation);

	void setPosition(const Vector2D& position);
	void setPosition(float x, float y);
	void setScale(const Vector2D& scale);
	void setScale(float x, float y);
	void setRotation(float angle);

	const Vector2D& getPosition() const;
	const Vector2D& getCenterPosition() const;
	const Vector2D& getScale() const;
	const Vector2D& getMirrorX() const;
	const Vector2D& getMirrorY() const;
	float getRotation() const;

	const Matrix2D& getWorldMatrix() const;

private:
	bool is_dirty;

	void calculateWorldMatrix();

	Vector2D center_position;
	Vector2D position;
	Vector2D scaling;
	Vector2D mirror_x;
	Vector2D mirror_y;
	float rotation;

	Matrix2D world_matrix;
};

#endif