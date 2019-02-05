#pragma once
#include "IObject.h"
#include "config/Config.h"
#include "game/TextureService.h"

class Floor : public IObject
{
private:
	std::shared_ptr<Config> _config;
	std::shared_ptr<TextureService> _texture;
	Vector3<float> _quadDimension{15, 0, 15};
public:
	Vector3<float>& QuadDimension() { return _quadDimension; }


	Floor(const std::shared_ptr<Config>& config, const std::shared_ptr<TextureService>& textureService)
		: _config(config),
		  _texture(textureService)
	{
		_dimension = _config->WorldDimension;
		_position = Vector3<float>{-_dimension.x / 2, 0, -_dimension.z / 2};
	}

	void Render() override;
	void DrawQuad();
};
