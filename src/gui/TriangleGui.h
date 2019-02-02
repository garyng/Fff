#pragma once
#include "imgui_custom.h"
#include "objects/Triangle.h"
#include "objects/ObjectGuiBase.h"

class TriangleGui : public ObjectGuiBase<Triangle>
{
public:

	void Render() override
	{
		ImGui::BeginDefault(GetName());

		RenderDefault();

		ImVec4 color{ _object->Color().x, _object->Color().y, _object->Color().z, 1 };
		ImGui::ColorEdit3("MyColor##1", (float*)&color, ImGuiColorEditFlags_Float);
		_object->Color().x = color.x;
		_object->Color().y = color.y;
		_object->Color().z = color.z;

		ImGui::End();
	}
};
