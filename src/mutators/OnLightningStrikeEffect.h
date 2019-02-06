#pragma once
#include "IMutator.h"
#include "game/GameService.h"

class OnLightningStrikeEffect : public IMutator
{
private:
	std::shared_ptr<GameService> _gameService;
	std::shared_ptr<ObjectFactory> _objectFactory;
	std::shared_ptr<Config> _config;
	float _startTime = 0;
	Vector3<float> _initialDeltaRotation;
	Vector3<float> _initialMaxRotation;
	Vector3<float> _initialMinRotation;
	Vector3<float> _initialRotation;
	std::shared_ptr<IObject> _cylinder;
public:


	OnLightningStrikeEffect(const std::shared_ptr<GameService>& gameService,
		const std::shared_ptr<ObjectFactory>& objectFactory, const std::shared_ptr<Config>& config)
		: _gameService(gameService),
		  _objectFactory(objectFactory),
		  _config(config)
	{
	}

	void OnInit() override;

	void OnDetach() override;

	void Apply() override;

	bool CanDetach() override;
};
