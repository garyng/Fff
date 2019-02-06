#pragma once
#include "IPowerUp.h"
#include "collision/ITestCollision.h"

class Magnet : public IPowerUp, public ITestCollision
{
public:
	Magnet()
	{
		Normalize({ 17, 8, 17 }, 7);
		_deltaRotation = Vector3<float>{ 0, 90, 0 };
		_deltaPosition = Vector3<float>{ 0, 1, 0 };

		_minPosition = Vector3<float>{ 0, 0, 0 };
		_maxPosition = Vector3<float>{ 0, 1, 0 };
		_minRotation = Vector3<float>{ 0, 0, 0 };
		_maxRotation = Vector3<float>{ 0, 360, 0 };
		_rotationWrappingBehaviour = WrappingBehaviour::Wrap;
	}

	void Render() override;
};
