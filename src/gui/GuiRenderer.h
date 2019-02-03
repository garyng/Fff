#pragma once
#include "GuiContainer.h"
#include "config/Config.h"

class GuiRenderer
{
private:
	std::vector<std::shared_ptr<IGui>> _globalGuis;
	std::shared_ptr<GuiContainer> _guiContainer;
	std::shared_ptr<Config> _config;
	bool _showGui = true;

public:
	GuiRenderer(const std::vector<std::shared_ptr<IGui>>& globalGuis,
		const std::shared_ptr<Config>& config,
		const std::shared_ptr<GuiContainer>& guiContainer) : _globalGuis(globalGuis),
		_guiContainer(guiContainer), _config(config)
	{
	}

	void Render();
	void OnKeyboard();
};
