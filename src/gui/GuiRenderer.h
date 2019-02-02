#pragma once
#include "GuiContainer.h"

class GuiRenderer
{
private:
	bool _showDemoWindow = true;
	std::vector<std::shared_ptr<IGui>> _globalGuis;
	std::shared_ptr<GuiContainer> _guiContainer;

public:
	GuiRenderer(const std::vector<std::shared_ptr<IGui>>& globalGuis,
	            const std::shared_ptr<GuiContainer>& guiContainer);

	void Render();
};
