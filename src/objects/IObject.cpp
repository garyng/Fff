#include "pch.h"
#include "IObject.h"

void IObject::Transform() const
{
	glTranslatef(_position.x, _position.y, _position.z);
	glRotatef(_rotation.x, 1, 0, 0);
	glRotatef(_rotation.y, 0, 1, 0);
	glRotatef(_rotation.z, 0, 0, 1);
	glScalef(_scale.x, _scale.y, _scale.z);
	glScalef(_normalizationScale.x, _normalizationScale.y, _normalizationScale.z);
}

void IObject::Wrap(Vector3<float>& target, Vector3<float>& delta, Vector3<float> min, Vector3<float> max,
                   WrappingBehaviour behaviour)
{
	Wrap(target.x, delta.x, min.x, max.x, behaviour);
	Wrap(target.y, delta.y, min.y, max.y, behaviour);
	Wrap(target.z, delta.z, min.z, max.z, behaviour);
}

void IObject::Wrap()
{
	Wrap(_position, _deltaPosition, _minPosition, _maxPosition, _positionWrappingBehaviour);
	Wrap(_rotation, _deltaRotation, _minRotation, _maxRotation, _rotationWrappingBehaviour);
}

void IObject::ApplyDeltas()
{
	Add(_position, _deltaPosition, _minPosition, _maxPosition);
	Add(_rotation, _deltaRotation, _minRotation, _maxRotation);
}

void IObject::Add(Vector3<float>& target, Vector3<float>& increment, Vector3<float> min, Vector3<float> max)
{
	target.x += increment.x * _elapsed;
	target.y += increment.y * _elapsed;
	target.z += increment.z * _elapsed;
}

void IObject::Wrap(float& target, float& delta, float min, float max, WrappingBehaviour behaviour)
{
	// will modify delta if wrapping behavior Wrap
	if (target < min)
	{
		switch (behaviour)
		{
			case WrappingBehaviour::Wrap:
				target = max;
				break;
			case WrappingBehaviour::Stop:
				target = min;
				break;
			case WrappingBehaviour::Bounce:
				// only bounce when delta is != 0 since keyboard input wont be able to do bouncing
				// this also implies that bouncing can be done only when using delta to control the axis
				if (delta != 0)
				{
					target = min;
					delta = -delta;
				}
				break;
		}
	}
	if (target > max)
	{
		switch (behaviour)
		{
			case WrappingBehaviour::Wrap:
				target = min;
				break;
			case WrappingBehaviour::Stop:
				target = max;
				break;
			case WrappingBehaviour::Bounce:
				if (delta != 0)
				{
					target = max;
					delta = -delta;
				}
				break;
		}
	}
}

void IObject::Normalize(Vector3<float> originalDimension)
{
	float max = std::max({originalDimension.x, originalDimension.y, originalDimension.z});
	_dimension.x = originalDimension.x / max;
	_dimension.y = originalDimension.y / max;
	_dimension.z = originalDimension.z / max;

	_normalizationScale.x = _dimension.x / originalDimension.x;
	_normalizationScale.y = _dimension.y / originalDimension.y;
	_normalizationScale.z = _dimension.z / originalDimension.z;
}
