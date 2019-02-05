
#pragma once
#include "gui/IGui.h"
#include "GameRenderer.h"
#include "GameService.h"

class GameGui : public IGui
{
private:
	std::shared_ptr<GameRenderer> _game;
	std::shared_ptr<GameService> _gameService;

public:


	GameGui(const std::shared_ptr<GameRenderer>& gameRenderer, const std::shared_ptr<GameService>& gameService)
		: _game(gameRenderer),
		  _gameService(gameService)
	{
	}

	void Render();
};
