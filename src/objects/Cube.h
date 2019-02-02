#pragma once
#include "IObject.h"

class Cube : public IObject
{
private:
	Vector3<float> _color{1.0, 1.0, 0.0};
public:
	Vector3<float>& Color() { return _color; }

	Cube()
	{
		_deltaRotation = Vector3<float>{0, 1, 0};

		// todo: use x, y min max from configuration!
		_minPosition = Vector3<float>{-10, -10, -10};
		_maxPosition = Vector3<float>{10, 10, 10};
		_minRotation = Vector3<float>{0, 0, 0};
		_maxRotation = Vector3<float>{180, 180, 180};
	}

	void Render() override;
};
