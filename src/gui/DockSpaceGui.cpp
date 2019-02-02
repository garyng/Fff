#include "pch.h"
#include "DockSpaceGui.h"

void DockSpaceGui::Render()
{
	auto&& io = ImGui::GetIO();


	ImGuiViewport* viewport = ImGui::GetMainViewport();
	float width = viewport->Size.x;
	float height = viewport->Size.y / 2;
	float x = viewport->Pos.x;
	float y = viewport->Pos.y;

	ImGui::SetNextWindowPos({x, y});
	ImGui::SetNextWindowSize({width, height});
	ImGui::SetNextWindowViewport(viewport->ID);

	ImGui::Begin("Settings", nullptr,
	             ImGuiWindowFlags_NoDocking | ImGuiWindowFlags_NoBackground | ImGuiWindowFlags_NoResize |
	             ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoBringToFrontOnFocus |
	             ImGuiWindowFlags_NoNavFocus);
	ImGuiID dockSpaceId = ImGui::GetID("DockSpace");
	ImGui::DockSpace(dockSpaceId, {0, 0}, ImGuiDockNodeFlags_PassthruDockspace);


	ImGui::End();
}
