#include "pch.h"
#include "KeyboardMutator.h"
#include "objects/IObject.h"

void KeyboardMutator::Apply()
{
	auto&& io = ImGui::GetIO();
	if (io.WantCaptureKeyboard) return;

	if (ImGui::IsKeyDown('w'))
	{
		_target->Position().z -= 0.01f;
	}
	if (ImGui::IsKeyDown('s'))
	{
		_target->Position().z += 0.01f;
	}
	if (ImGui::IsKeyDown('a'))
	{
		_target->Position().x -= 0.01f;
	}
	if (ImGui::IsKeyDown('d'))
	{
		_target->Position().x += 0.01f;
	}
}

bool KeyboardMutator::CanDetach()
{
	return false;
}
