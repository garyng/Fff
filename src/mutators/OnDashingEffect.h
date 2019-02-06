#pragma once
#include "IMutator.h"
#include "objects/ObjectFactory.h"
#include "game/GameService.h"

class OnDashingEffect : public IMutator
{
private:
	std::shared_ptr<ObjectFactory> _objectFactory;
	std::shared_ptr<GameService> _gameService;
	std::shared_ptr<IObject> _chevron;
	std::shared_ptr<Player> _player;
	Vector3<float> _initialDeltaMovement;
	float _startTime = 0;
public:

	OnDashingEffect(const std::shared_ptr<ObjectFactory>& objectFactory,
		const std::shared_ptr<GameService>& gameService)
		: _objectFactory(objectFactory),
		  _gameService(gameService)
	{
	}

	void OnInit() override;
	void OnDetach() override;
	void Apply() override;
	bool CanDetach() override;
};
