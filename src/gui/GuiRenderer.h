#pragma once
#include "GuiContainer.h"

class GuiRenderer
{
private:
	std::vector<std::shared_ptr<IGui>> _globalGuis;
	std::shared_ptr<GuiContainer> _guiContainer;
	bool _showGui = true;

public:
	GuiRenderer(const std::vector<std::shared_ptr<IGui>>& globalGuis,
	            const std::shared_ptr<GuiContainer>& guiContainer);

	void Render();
};
