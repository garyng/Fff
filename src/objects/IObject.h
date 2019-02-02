#pragma once
#include "Vector3.h"
#include "mutators/IMutable.h"

enum class WrappingBehaviour
{
	Wrap,
	Stop,
	Bounce
};

class IObject : public IMutable
{
protected:
	Vector3<float> _scale{1, 1, 1};
	Vector3<float> _dimension{0, 0, 0};
	Vector3<float> _position{0, 0, 0};
	Vector3<float> _rotation{0, 0, 0};

	Vector3<float> _deltaPosition{0, 0, 0};
	Vector3<float> _minPosition{0, 0, 0};
	Vector3<float> _maxPosition{0, 0, 0};
	WrappingBehaviour _positionWrappingBehaviour = WrappingBehaviour::Bounce;

	Vector3<float> _deltaRotation{0, 0, 0};
	Vector3<float> _minRotation{0, 0, 0};
	Vector3<float> _maxRotation{0, 0, 0};
	WrappingBehaviour _rotationWrappingBehaviour = WrappingBehaviour::Bounce;

	// id is property-injected
	unsigned int _id = 0;

	void ApplyTransformations() const;

	// apply animations
	void ApplyDeltas();

	void addWithBound(Vector3<float>& target, Vector3<float>& increment, Vector3<float> min, Vector3<float> max,
	                  WrappingBehaviour behaviour);

	void wrap(float& target, float& delta, float min, float max, WrappingBehaviour behaviour);


public:
	unsigned int Id() const { return _id; }
	void Id(unsigned int value) { _id = value; }

	float _elapsed;
	// seconds elapsed since last frame, property injected
	float Elapsed() const { return _elapsed; }
	void Elapsed(float value) { _elapsed = value; }

	Vector3<float>& Dimension() { return _dimension; }
	Vector3<float>& Scale() { return _scale; }
	Vector3<float>& Position() { return _position; }
	Vector3<float>& Rotation() { return _rotation; }
	Vector3<float>& DeltaPosition() { return _deltaPosition; }
	Vector3<float>& DeltaRotation() { return _deltaRotation; }

	WrappingBehaviour PositionWrappingBehaviour() const { return _positionWrappingBehaviour; }
	void PositionWrappingBehaviour(WrappingBehaviour value) { _positionWrappingBehaviour = value; }

	WrappingBehaviour RotationWrappingBehaviour() const { return _rotationWrappingBehaviour; }
	void RotationWrappingBehaviour(WrappingBehaviour value) { _rotationWrappingBehaviour = value; }

	virtual ~IObject() = default;
	virtual void Render() = 0;
};
