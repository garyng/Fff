#pragma once
#include "utilities/nameof.h"
#include "IObject.h"
#include "Config.h"


class Player : public IObject
{
protected:
	PlayerKeysBinding _keyBindings{};
	std::shared_ptr<Config> _config;
	// movement speed, different from _deltaPosition, this is used during key presses only
	Vector3<float> _deltaMovement{ 0.01f, 0, 0.01f };
public:
	PlayerKeysBinding KeyBindings() const { return _keyBindings; }

	Player(const std::shared_ptr<Config>& config) : _config(config)
	{
		_minPosition = _config->WorldMin;
		_maxPosition = _config->WorldMax;
	}

	Vector3<float>& DeltaMovement() { return _deltaMovement; }

	void Render() override;
};
