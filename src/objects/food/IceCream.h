#pragma once
#include "IFood.h"

class IceCream : public IFood
{
public:
	IceCream()
	{
		Normalize({23, 40, 20});
		_scale = Vector3<float>{1.5, 1.5, 1.5};
		_deltaRotation = Vector3<float>{0, 1, 0};
		_deltaPosition = Vector3<float>{0, 1, 0};

		_minPosition = Vector3<float>{0, 0, 0};
		_maxPosition = Vector3<float>{0, 1, 0};
	}

	void Render() override;
};
