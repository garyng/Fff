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
		ImGui::DragFloat("y##Quads", &_object->QuadDimension().y, 0.05f, 0.05f, 100);
		ImGui::DragFloat("z##Quads", &_object->QuadDimension().z, 0.05f, 0.05f, 100);

		ImGui::End();
	}
};
