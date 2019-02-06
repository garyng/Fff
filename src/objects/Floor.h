#pragma once
#include "IObject.h"
#include "config/Config.h"
#include "game/TextureService.h"

class Floor : public IObject
{
private:
	std::shared_ptr<Config> _config;
	std::shared_ptr<TextureService> _texture;
	Vector3<float> _quadDimension{ 1, 0, 1 };
	Vector3<float> _textureDimension{5, 0, 5};

public:
	Vector3<float>& QuadDimension() { return _quadDimension; }
	Vector3<float>& TextureDimension() { return _textureDimension; }

	Floor(const std::shared_ptr<Config>& config, const std::shared_ptr<TextureService>& textureService)
		: _config(config),
		  _texture(textureService)
	{
		_dimension = { _config->WorldDimension.x, 0, _config->WorldDimension.z };
		_position = { 0,0,0 };
	}

	void Render() override;
};
