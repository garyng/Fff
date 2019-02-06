#pragma once
#include "objects/ObjectGuiBase.h"
#include "objects/Floor.h"

class FloorGui : public ObjectGuiBase<Floor>
{
public:
	void Render() override
	{
		ImGui::BeginDefault(GetName());

		RenderDefaultControls();
		
		ImGui::Text("Quad Dimension");
		ImGui::DragFloat("x##Quads", &_object->QuadDimension().x, 0.05f, 0.05f, 100);
		ImGui::DragFloat("z##Quads", &_object->QuadDimension().z, 0.05f, 0.05f, 100);

		ImGui::Text("Texture Dimension");
		ImGui::DragFloat("x##Texture", &_object->TextureDimension().x, 0.05f, 0.05f, 100);
		ImGui::DragFloat("z##Texture", &_object->TextureDimension().z, 0.05f, 0.05f, 100);

		ImGui::End();
	}
};
