#include "pch.h"
#include "KeyboardMutator.h"

void KeyboardMutator::Apply()
{
	auto&& io = ImGui::GetIO();
	if (io.WantCaptureKeyboard) return;

	if (io.KeysDown['w'])
	{
		_target->Position().z -= 0.01;
	}
	if (io.KeysDown['s'])
	{
		_target->Position().z += 0.01;
	}
	if (io.KeysDown['a'])
	{
		_target->Position().x -= 0.01;
	}
	if (io.KeysDown['d'])
	{
		_target->Position().x += 0.01;
	}
}

bool KeyboardMutator::CanDetach()
{
	return false;
}
