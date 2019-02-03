#pragma once
#include "Player.h"

class Player2 : public Player
{
public:
	Player2(const std::shared_ptr<Config>& config, const std::shared_ptr<ILogger>& logger)
		: Player(config, logger)
	{
		_keyBindings = _config->Player2Keys;
	}
};
