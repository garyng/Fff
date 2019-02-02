#include "pch.h"
#include "DebugGui.h"
#include "imgui_custom.h"



void DebugGui::Render()
{
	ImGui::BeginDefault("Debug");

	ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate,
				ImGui::GetIO().Framerate);

	ImGuiIO& io = ImGui::GetIO();

	ImGui::Text("WantCaptureMouse: %d", io.WantCaptureMouse);
	ImGui::Text("WantCaptureKeyboard: %d", io.WantCaptureKeyboard);
	ImGui::Text("WantTextInput: %d", io.WantTextInput);
	ImGui::Text("WantSetMousePos: %d", io.WantSetMousePos);

	if (ImGui::IsMousePosValid())
		ImGui::Text("Mouse pos: (%g, %g)", io.MousePos.x, io.MousePos.y);
	else
		ImGui::Text("Mouse pos: <INVALID>");
	ImGui::Text("Mouse delta: (%g, %g)", io.MouseDelta.x, io.MouseDelta.y);
	ImGui::Text("Mouse down:");
	for (int i = 0; i < IM_ARRAYSIZE(io.MouseDown); i++)
		if (io.MouseDownDuration[i] >= 0.0f)
		{
			ImGui::SameLine();
			ImGui::Text("b%d (%.02f secs)", i, io.MouseDownDuration[i]);
		}
	ImGui::Text("Mouse clicked:");
	for (int i = 0; i < IM_ARRAYSIZE(io.MouseDown); i++)
		if (ImGui::IsMouseClicked(i))
		{
			ImGui::SameLine();
			ImGui::Text("b%d", i);
		}
	ImGui::Text("Mouse dbl-clicked:");
	for (int i = 0; i < IM_ARRAYSIZE(io.MouseDown); i++)
		if (ImGui::IsMouseDoubleClicked(i))
		{
			ImGui::SameLine();
			ImGui::Text("b%d", i);
		}
	ImGui::Text("Mouse released:");
	for (int i = 0; i < IM_ARRAYSIZE(io.MouseDown); i++)
		if (ImGui::IsMouseReleased(i))
		{
			ImGui::SameLine();
			ImGui::Text("b%d", i);
		}
	ImGui::Text("Mouse wheel: %.1f", io.MouseWheel);

	ImGui::Text("Keys down:");
	for (int i = 0; i < IM_ARRAYSIZE(io.KeysDown); i++)
		if (io.KeysDownDuration[i] >= 0.0f)
		{
			ImGui::SameLine();
			ImGui::Text("%d (%.02f secs)", i, io.KeysDownDuration[i]);
		}
	ImGui::Text("Keys pressed:");
	for (int i = 0; i < IM_ARRAYSIZE(io.KeysDown); i++)
		if (ImGui::IsKeyPressed(i))
		{
			ImGui::SameLine();
			ImGui::Text("%d", i);
		}
	ImGui::Text("Keys release:");
	for (int i = 0; i < IM_ARRAYSIZE(io.KeysDown); i++)
		if (ImGui::IsKeyReleased(i))
		{
			ImGui::SameLine();
			ImGui::Text("%d", i);
		}
	ImGui::Text("Keys mods: %s%s%s%s", io.KeyCtrl ? "CTRL " : "", io.KeyShift ? "SHIFT " : "",
				io.KeyAlt ? "ALT " : "", io.KeySuper ? "SUPER " : "");

	ImGui::End();
}
