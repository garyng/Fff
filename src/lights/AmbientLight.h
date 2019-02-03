#pragma once
#include "config/Config.h"
#include "ILight.h"

class AmbientLight : public ILight
{
private:
	std::shared_ptr<Config> _config;
public:
	AmbientLight(const std::shared_ptr<Config>& config) : _config(config)
	{
		_position = Vector3<float>{
			_config->WorldMin.x + _config->WorldDimension.x / 2,
			_config->WorldMax.y,
			_config->WorldMin.z + _config->WorldDimension.z / 2,

		};
		_diffuse = Vector3<float>{ 0.5f, 0.5f, 0.5f };
	}

	void Render() override;
};
