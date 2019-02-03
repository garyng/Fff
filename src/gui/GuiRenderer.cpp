#include "pch.h"
#include "GuiRenderer.h"
#include <imgui.h>

void GuiRenderer::Render()
{
	OnKeyboard();
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

void GuiRenderer::OnKeyboard()
{
	auto&& io = ImGui::GetIO();
	if (io.WantCaptureKeyboard) return;

	if (ImGui::IsKeyPressed(_config->ToggleTerminalKey, false))
	{
		_showGui = !_showGui;
	}
}
