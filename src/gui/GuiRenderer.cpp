#include "pch.h"
#include "GuiRenderer.h"
#include <imgui.h>

void GuiRenderer::ShowHelpGui()
{
	if (!_config->ShowHelp()) return;
	_help->Render();
}

void GuiRenderer::Render()
{
	OnKeyboard();
	ShowGlobalGui();
	ShowObjectsGui();
	ShowHelpGui();
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
	if (!_config->ShowObjectsGui() || !_config->IsTerminalEnabled()) return;
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
	}if (ImGui::IsKeyPressed(_config->ToggleHelpKey, false))
	{
		_config->ShowHelp(!_config->ShowHelp());
	}
}
