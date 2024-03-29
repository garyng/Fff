﻿#pragma once
#include "Player.h"

class Player1 : public Player
{
private:
	// left hand and right leg rotation, delta, min, max
	Vector4<float> _left{30, 90, -30, 30};
	// right hand and left leg rotation, delta, min, max
	Vector4<float> _right{-30, 90, -30, 30};
	// ball rotation, delta, min, max
	Vector4<float> _ballRotation{0, 180, 0, 360};
	// ball location, delta, min, max
	Vector4<float> _ballPosition;
public:
	Player1(const std::shared_ptr<Config>& config, const std::shared_ptr<ILogger>& logger)
		: Player(config, logger)
	{
		_keyBindings = _config->Player1Keys;
		Normalize({14, 25, 8}, 15);
		_direction = Vector3<float>{0, 0, 1};
		_ballPosition = Vector4<float>{0, 15, 0, 20};
	}

	void Animate();

	void Render() override;

	void Eye();
	void Nose();
	void Mouth();
	void Hair();
	void Face();
	void Head();
	void Body();
	void Hand();
	void Leg();
};
