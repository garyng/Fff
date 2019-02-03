#include "pch.h"
#include "GameGui.h"
#include "imgui_custom.h"

void GameGui::Render()
{
	ImGui::BeginDefault("Game");

	ImGui::DragFloat("z Near", &_game->ZNear(), 0.05, 0.1, 100);
	ImGui::DragFloat("z Far", &_game->ZFar(), 0.05, 100, 1000);
	ImGui::DragFloat("Field of View", &_game->FieldOfView(), 0.1, 0, 360);

	ImGui::Text("Eye");
	ImGui::DragFloat("x##Eye", &_game->Eye().x, 0.05, 0, 100);
	ImGui::DragFloat("y##Eye", &_game->Eye().y, 0.05, 0, 100);
	ImGui::DragFloat("z##Eye", &_game->Eye().z, 0.05, 0, 100);

	ImGui::Text("Center");
	ImGui::DragFloat("x##Center", &_game->Center().x, 0.05, 0, 100);
	ImGui::DragFloat("y##Center", &_game->Center().y, 0.05, 0, 100);
	ImGui::DragFloat("z##Center", &_game->Center().z, 0.05, 0, 100);

	ImGui::Text("Scale");
	ImGui::DragFloat("x##Scale", &_game->Scale().x, 0.05, 1, 10);
	ImGui::DragFloat("y##Scale", &_game->Scale().y, 0.05, 1, 10);
	ImGui::DragFloat("z##Scale", &_game->Scale().z, 0.05, 1, 10);

	ImGui::Text("Rotation");
	ImGui::DragFloat("x##Rotation", &_game->Rotation().x, 0.05, 0, 100);
	ImGui::DragFloat("y##Rotation", &_game->Rotation().y, 0.05, 0, 100);
	ImGui::DragFloat("z##Rotation", &_game->Rotation().z, 0.05, 0, 100);

	ImGui::Text("Position");
	ImGui::DragFloat("x##Position", &_game->Position().x, 0.05, -100, 100);
	ImGui::DragFloat("y##Position", &_game->Position().y, 0.05, -100, 100);
	ImGui::DragFloat("z##Position", &_game->Position().z, 0.05, -100, 100);


	ImGui::End();
}
