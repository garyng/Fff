﻿#pragma once
#include "IObject.h"
#include "config/Config.h"


class Player : public IObject
{
protected:
	std::shared_ptr<Config> _config;
	std::shared_ptr<ILogger> _logger;
	Vector3<float> _lastPosition = _position;

	PlayerKeysBinding _keyBindings{};
	// movement speed, different from _deltaPosition, this is used during key presses only
	Vector3<float> _deltaMovement{0.01f, 0, 0.01f};

	// +x (going right), -x (going left), +z (going down), -z (going up)
	Vector3<float> _direction{0, 0, 0};
public:
	PlayerKeysBinding KeyBindings() const { return _keyBindings; }
	Vector3<float>& Direction() { return _direction; }

	Player(const std::shared_ptr<Config>& config,
	       const std::shared_ptr<ILogger>& logger) : _config(config),
	                                                 _logger(logger)
	{
		_minPosition = _config->WorldMin;
		_maxPosition = _config->WorldMax;
	}

	Vector3<float>& DeltaMovement() { return _deltaMovement; }

	void OrientDirection();

	bool HasPositionChanged()
	{
		bool changed = (_lastPosition.x - _position.x != 0) ||
			(_lastPosition.y - _position.y != 0) ||
			(_lastPosition.z - _position.z != 0);

		_lastPosition = _position;
		return changed;
	}

	void Render() override;
};
