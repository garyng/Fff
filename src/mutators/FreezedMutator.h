#pragma once
#include "utilities/nameof.h"
#include "logger/ILogger.h"
#include "game/GameService.h"
#include "Vectors.h"
#include "IMutator.h"

class FreezedMutator : public IMutator
{
private:
	std::shared_ptr<GameService> _gameService;
	std::shared_ptr<ILogger> _logger;

	Vector3<float> _initialPosition;

public:
	FreezedMutator(const std::shared_ptr<GameService>& gameService, const std::shared_ptr<ILogger>& logger)
		: _gameService(gameService), _logger(logger)
	{
	}


	void Apply() override
	{
		_target->Position().x = _initialPosition.x;
		_target->Position().y = _initialPosition.y;
		_target->Position().z = _initialPosition.z;
	}

	bool CanDetach() override
	{
		return _gameService->TotalTime() > 10;
	}

	void OnInit() override
	{
		_initialPosition = _target->Position();
	}

	void OnDetach() override
	{
		_logger->Debug("Detach %1% from %2% [#%3%]", { nameof(*this), nameof(*_target), std::to_string(_target->Id()) });
	}
};
