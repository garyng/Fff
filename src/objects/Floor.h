#pragma once
#include "IObject.h"
#include "Config.h"

class Floor : public IObject
{
private:
	std::shared_ptr<Config> _config{};
	Vector3<float> _quadDimension{1, 0, 1};
public:
	Vector3<float>& QuadDimension() { return _quadDimension; }

	Floor(const std::shared_ptr<Config>& config)
		: _config(config)
	{
		_dimension = _config->WorldDimension;
	}

	void Render() override;
	void DrawQuad();
};
