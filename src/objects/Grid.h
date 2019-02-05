#pragma once
#include "IObject.h"
#include "config/Config.h"

class Grid : public IObject
{
private:
	std::shared_ptr<Config> _config;
	unsigned int _quadsListId;
	Vector3<float> _gridMin{-10, -10, -10};
	Vector3<float> _gridMax{ 10, 10, 10 };

public:
	Grid(const std::shared_ptr<Config>& config): _config(config)
	{
		_dimension = _config->WorldDimension;
		_quadsListId = glGenLists(1);
		DrawQuads();
	}

	Vector3<float> _quadDimension{1, 0, 1};

	void Render() override;
	void DrawQuads();
	void DrawQuad();
};
