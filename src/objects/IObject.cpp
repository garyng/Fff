#include "pch.h"
#include "IObject.h"

void IObject::ApplyTransformations() const
{
	glTranslatef(_position.x, _position.y, _position.z);
	glRotatef(_rotation.x, 1, 0, 0);
	glRotatef(_rotation.y, 0, 1, 0);
	glRotatef(_rotation.z, 0, 0, 1);
	glScalef(_scale.x, _scale.y, _scale.z);
}

void IObject::ApplyDeltas()
{
	addWithBound(_position, _deltaPosition, _minPosition, _maxPosition, _positionWrappingBehaviour);
	addWithBound(_rotation, _deltaRotation, _minRotation, _maxRotation, _rotationWrappingBehaviour);
}

void IObject::addWithBound(Vector3<float>& target, Vector3<float>& increment, Vector3<float> min, Vector3<float> max,
                           WrappingBehaviour behaviour)
{
	target.x += increment.x * _elapsed;
	wrap(target.x, increment.x, min.x, max.x, behaviour);
	target.y += increment.y * _elapsed;
	wrap(target.y, increment.y, min.y, max.y, behaviour);
	target.z += increment.z * _elapsed;
	wrap(target.z, increment.z, min.z, max.z, behaviour);
}

void IObject::wrap(float& target, float& delta, float min, float max, WrappingBehaviour behaviour)
{
	// will modify delta if wrapping behavior wrap
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
				delta = -delta;
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
				delta = -delta;
				break;
		}
	}
}
