#pragma once
#include "IMutator.h"
#include "game/GameService.h"

class OnFreezedEffect : public IMutator
{
private:
	std::shared_ptr<GameService> _gameService;
	std::shared_ptr<ILogger> _logger;
	Vector3<float> _initialPosition;
	Vector3<float> _initialRotation;
	Vector3<float> _initialDeltaRotation;
	float _startTime = 0;
	Vector3<float> _initialDeltaPosition;
	Vector3<float> _initialMaxPosition;
	Vector3<float> _initialMinPosition;
	WrappingBehaviour _initialWrappingBehaviour;

public:

	OnFreezedEffect(const std::shared_ptr<GameService>& gameService, const std::shared_ptr<ILogger>& logger)
		: _gameService(gameService),
		  _logger(logger)
	{
	}

	void OnInit() override;
	void OnDetach() override;
	void Apply() override;
	bool CanDetach() override;
};
