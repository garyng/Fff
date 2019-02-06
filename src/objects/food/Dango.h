#pragma once
#include "IFood.h"
#include "collision/ITestCollision.h"

class Dango : public IFood, public ITestCollision
{
private:
	float _stickLength = 30.0f;
	float _ballRadius = 4.0f;
	float _angle = 60.0f;
	float _height = _stickLength * sin(_angle / 180 * PI);
public:
	Dango()
	{
		Normalize({16, 32, 9}, 5);
		_deltaRotation = Vector3<float>{ 0, 90, 0 };
		_deltaPosition = Vector3<float>{0, 1, 0};

		_minPosition = Vector3<float>{0, 0, 0};
		_maxPosition = Vector3<float>{0, 1, 0};
		_minRotation = Vector3<float>{ 0, 0, 0 };
		_maxRotation = Vector3<float>{ 0, 360, 0 };
		_rotationWrappingBehaviour = WrappingBehaviour::Wrap;
	}

	void Render() override;
};
