#pragma once
#include "IObject.h"

class Chevron : public IObject
{
public:
	Chevron()
	{
		Normalize({ 1, 0.7, 0.1}, 5);
		_deltaRotation = Vector3<float>{ 0, 90, 0 };
		_deltaPosition = Vector3<float>{ 0, 1, 0 };

		_minPosition = Vector3<float>{ 0, 0, 0 };
		_maxPosition = Vector3<float>{ 0, 1, 0 };
		_minRotation = Vector3<float>{ 0, 0, 0 };
		_maxRotation = Vector3<float>{ 0, 360, 0 };
		_rotationWrappingBehaviour = WrappingBehaviour::Wrap;
	}

	void Render() override;
	void One();
};
