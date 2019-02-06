#pragma once
#include "IMutator.h"
#include "game/GameService.h"

class WinningMutator : public IMutator
{
private:
	std::shared_ptr<GameService> _gameService;
	std::shared_ptr<ILogger> _logger;
	float _initialMaxRotation{ 0 };
	WrappingBehaviour _initialRotationBehaviour;
public:

	WinningMutator(const std::shared_ptr<GameService>& gameService, const std::shared_ptr<ILogger>& logger)
		: _gameService(gameService),
		  _logger(logger)
	{
	}

	void Apply() override;

	bool CanDetach() override;

	void OnInit() override;

	void OnDetach() override;
};
