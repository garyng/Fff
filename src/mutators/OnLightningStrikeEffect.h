#pragma once
#include "IMutator.h"
#include "game/GameService.h"

class OnLightningStrikeEffect : public IMutator
{
private:
	std::shared_ptr<GameService> _gameService;
	float _startTime = 0;
	Vector3<float> _initialDeltaRotation;
	Vector3<float> _initialMaxRotation;
	Vector3<float> _initialMinRotation;
	Vector3<float> _initialRotation;
public:
	OnLightningStrikeEffect(const std::shared_ptr<GameService>& gameService)
		: _gameService(gameService)
	{
	}

	void OnInit() override;

	void OnDetach() override;

	void Apply() override;

	bool CanDetach() override;
};
