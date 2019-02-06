#include "pch.h"
#include "GuiRenderer.h"
#include <imgui.h>

void GuiRenderer::Render()
{
	OnKeyboard();
	ShowGlobalGui();
	ShowObjectsGui();

	_guiContainer->Purge();
}

void GuiRenderer::ShowGlobalGui()
{
	if (!_config->IsTerminalEnabled()) return;

	for (auto&& gui : _globalGuis)
	{
		// render global gui
		gui->Render();
	}
}

void GuiRenderer::ShowObjectsGui()
{
	if (!_config->ShowObjectsGui()) return;
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
		_config->IsTerminalEnabled(!_config->IsTerminalEnabled());
	}
	if (ImGui::IsKeyPressed(_config->ToggleObjectsGui, false))
	{
		_config->ShowObjectsGui(!_config->ShowObjectsGui());
	}
}
