#pragma once
#include "IObject.h"
#include "game/GameService.h"

class Countdown : public IObject
{
private:
	std::shared_ptr<GameService> _gameService;
	std::shared_ptr<Config> _config;
public:


	Countdown(const std::shared_ptr<GameService>& gameService, const std::shared_ptr<Config>& config)
		: _gameService(gameService),
		  _config(config)
	{
		_position = Vector3<float>{ -15, 0, _config->WorldMin.z };
	}

	void Render() override;
};
