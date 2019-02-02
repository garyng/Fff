#include "pch.h"
#include "GuiRenderer.h"

GuiRenderer::GuiRenderer(const std::vector<std::shared_ptr<IGui>>& globalGuis,
						 const std::shared_ptr<GuiContainer>& guiContainer): _globalGuis(globalGuis),
																			 _guiContainer(guiContainer)
{
}

void GuiRenderer::Render()
{
	if (_showDemoWindow)
		ImGui::ShowDemoWindow(&_showDemoWindow);

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
