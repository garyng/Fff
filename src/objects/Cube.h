#pragma once
#include "IObject.h"
#include "Config.h"

class Cube : public IObject
{
private:
	Vector3<float> _color{1.0, 1.0, 0.0};
	std::shared_ptr<Config> _config;
public:
	Vector3<float>& Color() { return _color; }

	Cube(const std::shared_ptr<Config>& config): _config(config)
	{
		_deltaRotation = Vector3<float>{0, 1, 0};

		_minPosition = _config->WorldMin;
		_maxPosition = _config->WorldMax;
		_minRotation = Vector3<float>{0, 0, 0};
		_maxRotation = Vector3<float>{180, 180, 180};
	}

	void Render() override;
};
