#pragma once
#include "Player.h"

class Player1 : public Player
{
public:
	Player1(const std::shared_ptr<Config>& config)
		: Player(config)
	{
		_keyBindings = _config->Player1Keys;
	}
};
