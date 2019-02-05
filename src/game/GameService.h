#pragma once
#include "FoodService.h"
#include "mutators/MutatorFactory.h"
#include "objects/player/Player.h"

enum class GameStates
{
	Pending, InGame, Ended
};

class GameService
{
private:
	float _totalTimeElapsed = 0;
	float _maximumTime = 120;
	std::shared_ptr<FoodService> _foodService;
	std::shared_ptr<ObjectFactory> _objectFactory;
	std::shared_ptr<ObjectContainer> _objectContainer;
	std::shared_ptr<MutatorFactory> _mutatorFactory;
	GameStates _gameState = GameStates::Pending;

public:

	GameService(const std::shared_ptr<FoodService>& foodService, const std::shared_ptr<ObjectFactory>& objectFactory,
	            const std::shared_ptr<ObjectContainer>& objectContainer,
	            const std::shared_ptr<MutatorFactory>& mutatorFactory)
		: _foodService(foodService),
		  _objectFactory(objectFactory),
		  _objectContainer(objectContainer),
		  _mutatorFactory(mutatorFactory)
	{
	}

	GameStates GameState() const { return _gameState; }
	void GameState(GameStates value) { _gameState = value; }
	
	// Seconds elapsed since last frame
	float DeltaTime();
	void IncrementTime();
	// Seconds since last game start
	float TotalTimeElapsed() const;
	std::shared_ptr<Player> Winner(bool& isTie);


	void Start();
	// Game is over
	void End();
	void Restart();

	int TimeLeft();
};
