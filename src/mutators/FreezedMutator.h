#pragma once
#include "utilities/nameof.h"
#include "logger/ILogger.h"
#include "game/GameService.h"
#include "Vectors.h"
#include "IMutator.h"
#include "objects/IObject.h"

class FreezedMutator : public IMutator
{
private:
	std::shared_ptr<GameService> _gameService;
	std::shared_ptr<ILogger> _logger;

	Vector3<float> _initialPosition;
	float _startTime = 0;

public:
	FreezedMutator(const std::shared_ptr<GameService>& gameService, const std::shared_ptr<ILogger>& logger)
		: _gameService(gameService), _logger(logger)
	{
	}


	void Apply() override;

	bool CanDetach() override;

	void OnInit() override;

	void OnDetach() override;
};
