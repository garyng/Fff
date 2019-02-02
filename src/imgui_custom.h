#pragma once
#include <string>
#include <imgui.h>

namespace ImGui
{
	// todo: move to cpp file?

	inline bool BeginDefault(const std::string& name)
	{
		return Begin(name.c_str(), nullptr, ImGuiWindowFlags_AlwaysAutoResize);
	}
}