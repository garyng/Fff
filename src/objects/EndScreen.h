#pragma once
#include "game/GameService.h"

class EndScreen : public IObject
{
private:
	std::shared_ptr<Config> _config;
	std::shared_ptr<GameService> _gameService;
	float _sinceLastVisibilityToggle = 0;
	bool _visible = true;
public:

	EndScreen(const std::shared_ptr<Config>& config, const std::shared_ptr<GameService>& gameService)
		: _config(config),
		_gameService(gameService)
	{
	}


	void Render() override;
};
