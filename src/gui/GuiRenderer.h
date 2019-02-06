#pragma once
#include "GuiContainer.h"
#include "config/Config.h"
#include "HelpGui.h"

class GuiRenderer
{
private:
	std::vector<std::shared_ptr<IGui>> _globalGuis;
	std::shared_ptr<GuiContainer> _guiContainer;
	std::shared_ptr<Config> _config;
	std::shared_ptr<HelpGui> _help;

public:


	GuiRenderer(const std::vector<std::shared_ptr<IGui>>& sharedPtrs, const std::shared_ptr<GuiContainer>& guiContainer,
		const std::shared_ptr<Config>& config, const std::shared_ptr<HelpGui>& helpGui)
		: _globalGuis(sharedPtrs),
		  _guiContainer(guiContainer),
		  _config(config),
		  _help(helpGui)
	{
	}

	void ShowHelpGui();
	void Render();
	void ShowGlobalGui();
	void ShowObjectsGui();
	void OnKeyboard();
};
