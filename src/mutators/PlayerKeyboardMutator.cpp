#include "pch.h"
#include "PlayerKeyboardMutator.h"

void PlayerKeyboardMutator::Apply()
{
	auto&& io = ImGui::GetIO();
	if (io.WantCaptureKeyboard) return;

	if (ImGui::IsKeyDown(_player->KeyBindings().Up))
	{
		_target->Position().z -= _player->DeltaMovement().z;
	}
	if (ImGui::IsKeyDown(_player->KeyBindings().Down))
	{
		_target->Position().z += _player->DeltaMovement().z;
	}
	if (ImGui::IsKeyDown(_player->KeyBindings().Left))
	{
		_target->Position().x -= _player->DeltaMovement().x;
	}
	if (ImGui::IsKeyDown(_player->KeyBindings().Right))
	{
		_target->Position().x += _player->DeltaMovement().x;
	}
}

bool PlayerKeyboardMutator::CanDetach()
{
	return false;
}

void PlayerKeyboardMutator::OnInit()
{
	_player = std::static_pointer_cast<Player>(_target);
}
