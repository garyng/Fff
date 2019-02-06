#include "pch.h"
#include "GameService.h"
#include "objects/Floor.h"
#include "objects/Grid.h"
#include "objects/player/Player2.h"
#include "mutators/PlayerKeyboardMutator.h"
#include "objects/player/Player1.h"
#include "lights/SceneSpotLight.h"
#include "objects/StartScreen.h"
#include "objects/Countdown.h"
#include "objects/EndScreen.h"

float GameService::DeltaTime()
{
	auto&& io = ImGui::GetIO();
	return io.DeltaTime;
}

void GameService::IncrementTime()
{
	_totalTimeElapsed += DeltaTime();
	if (TimeLeft() <= 0 && _gameState == GameStates::InGame)
	{
		End();
	}
}

void GameService::Start()
{
	_totalTimeElapsed = 0;
	_gameState = GameStates::InGame;
	_objectContainer->FirstOf<StartScreen>()->CanRemove(true);
	_objectFactory->Make<Floor>();
	_objectFactory->Make<Countdown>();
	_objectFactory->Make<Grid>();
	_objectFactory->Make<Player1>();
	_objectFactory->Make<Player2>();
	_objectFactory->Make<SceneSpotLight>();
	_mutatorFactory->Attach<PlayerKeyboardMutator, Player1>();
	_mutatorFactory->Attach<PlayerKeyboardMutator, Player2>();
	_foodService->New();
}

void GameService::End()
{
	_gameState = GameStates::Ended;
	// dont clear, otherwise the player's information is gone
	// _objectContainer->Clear();
	for (auto&& food : _objectContainer->AllOfBase<IFood>())
	{
		food->CanRemove(true);
	}
	_objectContainer->FirstOf<Countdown>()->CanRemove(true);
	_objectFactory->Make<EndScreen>();
}

void GameService::Restart()
{
	_totalTimeElapsed = 0;
	_objectContainer->Clear();
	_gameState = GameStates::Pending;
	_objectFactory->Make<StartScreen>();
}

int GameService::TimeLeft()
{
	return int(_maximumTime - _totalTimeElapsed);
}

float GameService::TotalTimeElapsed() const
{
	return _totalTimeElapsed;
}

std::shared_ptr<Player> GameService::Winner(bool& isTie)
{
	std::vector<std::shared_ptr<Player>> players = _objectContainer->AllOfBase<Player>();

	std::shared_ptr<Player> winner = players[0];
	for (std::shared_ptr<Player> player : players)
	{
		winner = player->Score() > winner->Score() ? player : winner;
	}

	int withSameScore = 0;
	for (std::shared_ptr<Player> player : players)
	{
		if (player->Score() == winner->Score())
		{
			withSameScore++;
		}
	}

	if (withSameScore == players.size())
	{
		isTie = true;
	}
	return winner;
}
