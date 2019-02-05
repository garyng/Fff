#pragma once
#include "IFood.h"
#include "collision/ITestCollision.h"
#include "lights/ILight.h"

class IceCream : public IFood, public ITestCollision
{
public:
	IceCream()
	{
		Normalize({20, 40, 20}, 5);
		_deltaRotation = Vector3<float>{0, 1, 0};
		_deltaPosition = Vector3<float>{0, 1, 0};

		_minPosition = Vector3<float>{0, 0, 0};
		_maxPosition = Vector3<float>{0, 1, 0};
	}

	void Render() override;
};
