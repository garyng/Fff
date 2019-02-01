#pragma once
#include <GL/glut.h>
#include "Vector3.h"

class IObject
{
protected:
	Vector3<float> _scale{ 0, 0, 0 };
	Vector3<float> _boundingBox{ 0,0,0 };
	Vector3<float> _position{ 0,0,0 };
	Vector3<float> _rotation{ 0,0,0 };
	Vector3<float> _delta{ 0,0,0 };

	// id is property-injected
	unsigned int _id = 0;

	void ApplyTransformations() const;

public:
	unsigned int Id() const { return _id; }
	void Id(unsigned int value) { _id = value; }

	Vector3<float>& BoundingBox() { return _boundingBox; }
	Vector3<float>& Scale() { return _scale; }
	Vector3<float>& Position() { return _position; }
	Vector3<float>& Rotation() { return _rotation; }
	Vector3<float>& Delta() { return _delta; }

	virtual ~IObject() = default;
	virtual void Render() = 0;
};
