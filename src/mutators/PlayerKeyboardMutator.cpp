#include "pch.h"
#include "PlayerKeyboardMutator.h"

void PlayerKeyboardMutator::Apply()
{
	auto&& io = ImGui::GetIO();
	if (io.WantCaptureKeyboard) return;

	if (ImGui::IsKeyDown(_player->KeyBindings().Up) || ImGui::IsKeyDown(_player->KeyBindings().Down) || ImGui::
		IsKeyDown(_player->KeyBindings().Left) || ImGui::IsKeyDown(_player->KeyBindings().Right))
	{
		_player->Direction() = Vector3<float>{0, 0, 0};
	}

	if (ImGui::IsKeyDown(_player->KeyBindings().Up))
	{
		_player->Position().z -= _player->DeltaMovement().z;
		_player->Direction().z = -1;
	}
	if (ImGui::IsKeyDown(_player->KeyBindings().Down))
	{
		_player->Position().z += _player->DeltaMovement().z;
		_player->Direction().z = 1;
	}
	if (ImGui::IsKeyDown(_player->KeyBindings().Left))
	{
		_player->Position().x -= _player->DeltaMovement().x;
		_player->Direction().x = -1;
	}
	if (ImGui::IsKeyDown(_player->KeyBindings().Right))
	{
		_player->Position().x += _player->DeltaMovement().x;
		_player->Direction().x = 1;
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
