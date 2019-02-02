#include "pch.h"
#include "GuiRenderer.h"

GuiRenderer::GuiRenderer(const std::vector<std::shared_ptr<IGui>>& globalGuis,
						 const std::shared_ptr<GuiContainer>& guiContainer): _globalGuis(globalGuis),
																			 _guiContainer(guiContainer)
{
}

void GuiRenderer::Render()
{

	auto && io = ImGui::GetIO();
	// todo: extract keybindings to configuration
	if (io.KeysDown[96] && io.KeysDownDuration[96] > 0.2) // `
	{
		io.KeysDownDuration[96] = 0;
		_showGui = !_showGui;
	}
	if (!_showGui) return;

	for (auto&& gui : _globalGuis)
	{
		// render global gui
		gui->Render();
	}
	for (auto&& gui : _guiContainer->All())
	{
		// render gui that has object
		gui->Render();
	}
}
