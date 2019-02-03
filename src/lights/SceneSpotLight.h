#pragma once
#include "ILight.h"
#include "config/Config.h"

class SceneSpotLight : public ILight
{
private:
	std::shared_ptr<Config> _config;
public:
	SceneSpotLight(const std::shared_ptr<Config>& config) : _config(config)
	{
		_position = Vector3<float>{
			_config->WorldMin.x + _config->WorldDimension.x / 2,
			_config->WorldMax.y / 2,
			_config->WorldMin.z + _config->WorldDimension.z / 2,
		};
		_direction = Vector3<float>{0, -1, 0};
	}

	void Render() override;
};
