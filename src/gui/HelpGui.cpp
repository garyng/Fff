#include "pch.h"
#include "HelpGui.h"
#include "CubeGui.h"

void HelpGui::Render()
{
	ImGui::SetNextWindowPosCenter(0);
	ImGui::Begin("Help", nullptr,
	             ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoDocking |
	             ImGuiWindowFlags_NoResize | ImGuiWindowFlags_Modal);
	ImGui::Text("Help: %c", _config->ToggleHelpKey);
	ImGui::Text("Start/Restart: <space>");

	ImGui::Separator();
	ImGui::Spacing();

	ImGui::Text("Player 1");
	ImGui::Text("Up: %c", _config->Player1Keys.Up);
	ImGui::Text("Down: %c", _config->Player1Keys.Down);
	ImGui::Text("Left: %c", _config->Player1Keys.Left);
	ImGui::Text("Right: %c", _config->Player1Keys.Right);

	ImGui::Separator();
	ImGui::Spacing();

	ImGui::Text("Player 2");
	ImGui::Text("Up: <up arrow key>");
	ImGui::Text("Down: <down arrow key>");
	ImGui::Text("Left: <left arrow key>");
	ImGui::Text("Right: <right arrow key>");

	ImGui::Separator();
	ImGui::Spacing();

	ImGui::Text("Others");
	ImGui::Text("Toggle terminal: `");
	ImGui::Text("Toggle wireframe mode: F1");
	ImGui::Text("Toggle lightning: F2");
	ImGui::Text("Toggle texture: F3");
	ImGui::Text("Toggle grid coordinates: F4");
	ImGui::Text("Toggle bounding boxes: F5");
	ImGui::End();
}
