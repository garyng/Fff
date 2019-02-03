#pragma once
#include "Vectors.h"
#include "mutators/IMutable.h"
#include "IRemovable.h"

enum class WrappingBehaviour
{
	Wrap,
	Stop,
	Bounce
};

class IObject : public IMutable, public IRemovable
{
protected:
	Vector3<float> _scale{1, 1, 1};
	// used to fit the entire model into a 1x1x1 cube
	Vector3<float> _normalizationScale{1, 1, 1};
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

	// apply changes positions/rotations/etc
	void ApplyDeltas();
	// perform the transformation
	void Transform() const;

	void Add(Vector3<float>& target, Vector3<float>& increment, Vector3<float> min, Vector3<float> max);

	// wrap an axis
	void Wrap(float& target, float& delta, float min, float max, WrappingBehaviour behaviour);

	// wrap a vector
	void Wrap(Vector3<float>& target, Vector3<float>& delta, Vector3<float> min, Vector3<float> max,
	          WrappingBehaviour behaviour);

	// wrap position and rotation
	void Wrap();

	// move the object so that the center of the base (XZ plane) is at the center
	void Center();

	// normalize the original dimension to fit into 1x1x1 cube
	void Normalize(Vector3<float> originalDimension);

	// apply delta with wrapping and transform the model
	void Apply()
	{
		ApplyDeltas();
		Wrap();
		Transform();
	}

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
