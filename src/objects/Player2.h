#pragma once
#include "Player.h"

class Player2 : public Player
{
public:
	Player2(const std::shared_ptr<Config>& config)
		: Player(config)
	{
		_keyBindings = _config->Player2Keys;
	}
};
