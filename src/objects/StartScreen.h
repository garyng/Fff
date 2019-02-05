#pragma once
#include "IObject.h"
#include "config/Config.h"
#include "game/GameService.h"

class StartScreen : public IObject
{
private:
	std::shared_ptr<Config> _config;
	std::shared_ptr<GameService> _gameService;
	float _sinceLastVisibilityToggle = 0;
	bool _visible = true;
public:

	StartScreen(const std::shared_ptr<Config>& config, const std::shared_ptr<GameService>& gameService)
		: _config(config),
		  _gameService(gameService)
	{
		_position = Vector3<float>{-75, 10, 0};
	}


	void Render() override;
};
