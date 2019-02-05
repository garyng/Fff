#pragma once
#include "utilities/constraints.h"
#include "lights/ILight.h"
#include "objects/ObjectGuiBase.h"

template <class TObject, class = IsBaseOf<TObject, ILight>>
class LightGuiBase : public ObjectGuiBase<TObject>
{
protected:
	std::shared_ptr<ILight> _light;
public:

	void Object(std::shared_ptr<TObject> value) override
	{
		ObjectGuiBase<TObject>::Object(value);
		_light = std::static_pointer_cast<ILight>(value);
	}

	void Render() override
	{
		ImGui::BeginDefault(ObjectGuiBase<TObject>::GetName());

		ObjectGuiBase<TObject>::RenderDefaultControls();

		ImGui::Text("Direction");
		ImGui::DragFloat("x##Direction", &_light->Direction().x, 0.05f, -1, 1);
		ImGui::SameLine();
		ImGui::DragFloat("y##Direction", &_light->Direction().y, 0.05f, -1, 1);
		ImGui::SameLine();
		ImGui::DragFloat("z##Direction", &_light->Direction().z, 0.05f, -1, 1);

		RenderColorControl("Ambient", _light->Ambient());
		RenderColorControl("Diffuse", _light->Diffuse());
		RenderColorControl("Specular", _light->Specular());

		ImGui::DragFloat("Spot cutoff", &_light->SpotCutoff(), 0.05f, 0, 90);
		ImGui::SameLine();
		ImGui::DragFloat("Spot exponent", &_light->SpotExponent(), 0.05f, 0, 128);

		ImGui::DragFloat("Constant attenuation", &_light->ConstantAttenuation(), 0.05f, 0, 100);
		ImGui::DragFloat("Linear attenuation", &_light->LinearAttenuation(), 0.05f, 0, 100);
		ImGui::DragFloat("Quadratic attenuation", &_light->QuadraticAttenuation(), 0.05f, 0, 100);

		ImGui::End();
	}

	void RenderColorControl(std::string name, Vector3<float>& color)
	{
		ImVec4 imColor{color.x, color.y, color.z, 1};
		ImGui::ColorEdit3(name.c_str(), (float*)&imColor, ImGuiColorEditFlags_Float);
		color.x = imColor.x;
		color.y = imColor.y;
		color.z = imColor.z;
	}
};
