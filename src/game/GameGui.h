
#pragma once
#include "gui/IGui.h"
#include "GameRenderer.h"

class GameGui : public IGui
{
private:
	std::shared_ptr<GameRenderer> _game;

public:
	GameGui(std::shared_ptr<GameRenderer> game) : _game(game)
	{
	}

	void Render();
};
