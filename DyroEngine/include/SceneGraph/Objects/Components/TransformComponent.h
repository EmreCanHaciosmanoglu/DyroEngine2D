#ifndef _TRANSFORMCOMPONENT_H
#define _TRANSFORMCOMPONENT_H

#include "SceneGraph\Objects\Components\Component.h"

#include "Math/Objects/Matrix2D.h"
#include "Math/Objects/Vector2D.h"

class TransformComponent : public Component
{
	/**
	\note Must be present in every subclass definition.
	*/
	OBJECT_STATICS("TransformComponent")

public:
	TransformComponent(const std::tstring& name = _T(""));
	virtual ~TransformComponent();

	virtual bool initialize();
	virtual void update();
	virtual bool shutdown();

	void mirrorX();
	void mirrorY();
	void resetMirror(bool x = true, bool y = true);

	//void center(float xCenter, float yCenter);
	//void center(const Vector2D& centerPosition);
	//void resetCenter();

	void translate(const Vector2D& translation);
	void scale(const Vector2D& scale);
	void rotate(float rotation);

	void setPosition(const Vector2D& position);
	void setPosition(float x, float y);
	void setStartPosition(const Vector2D& startPosition);
	void setStartPosition(float x, float y);
	void setScale(const Vector2D& scale);
	void setScale(float x, float y);
	void setStartScale(const Vector2D& scale);
	void setStartScale(float x, float y);
	void setRotation(float angle);
	void setStartRotation(float angle);

	const Vector2D& getPosition() const;
	const Vector2D& getStartPosition() const;
	//const Vector2D& getCenterPosition() const;
	const Vector2D& getScale() const;
	const Vector2D& getStartScale() const;
	const Vector2D& getMirrorX() const;
	const Vector2D& getMirrorY() const;
	float getRotation() const;
	float getStartRotation() const;

	const Vector2D& getForward() const;
	const Vector2D& getRight() const;

	const Matrix2D& getWorldMatrix() const;

	static const Vector2D world_forward;
	static const Vector2D world_right;

protected:
	void clearIsDirty();

	void setIsDirty();
	bool getIsDirty() const;

private:
	bool is_dirty;

	void calculateWorldMatrix();

	//Vector2D center_position;
	Vector2D position;
	Vector2D start_position;
	Vector2D scaling;
	Vector2D start_scaling;
	Vector2D mirror_x;
	Vector2D mirror_y;
	float rotation;
	float start_rotation;

	Vector2D forward;
	Vector2D right;

	Matrix2D world_matrix;
};

#endif