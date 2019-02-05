#pragma once
#include "objects/ObjectGuiBase.h"
#include "objects/player/Player.h"

template <class TObject, class = IsBaseOf<TObject, Player>>
class PlayerGuiBase : public ObjectGuiBase<TObject>
{
protected:
	std::shared_ptr<Player> _player;
public:
	void Render() override
	{
		ImGui::BeginDefault(ObjectGuiBase<TObject>::GetName());
		ObjectGuiBase<TObject>::RenderDefaultControls();

		ImGui::Text("Delta Movement");
		ImGui::DragFloat("x##Delta Movement", &_player->DeltaMovement().x, 0.05f, -50, 50);
		ImGui::SameLine();
		ImGui::DragFloat("y##Delta Movement", &_player->DeltaMovement().y, 0.05f, -50, 50);
		ImGui::SameLine();
		ImGui::DragFloat("z##Delta Movement", &_player->DeltaMovement().z, 0.05f, -50, 50);


		ImGui::End();
	}

	void Object(std::shared_ptr<TObject> value) override
	{
		ObjectGuiBase<TObject>::Object(value);
		_player = std::static_pointer_cast<Player>(value);
	}

};
