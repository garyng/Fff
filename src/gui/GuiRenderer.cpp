#include "pch.h"
#include "GuiRenderer.h"

void GuiRenderer::Render()
{

	auto && io = ImGui::GetIO();
	if (io.KeysDown[_config->ToggleTerminalKey] && io.KeysDownDuration[_config->ToggleTerminalKey] >= _config->KeyDownDuration)
	{
		io.KeysDownDuration[_config->ToggleTerminalKey] = 0;
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
