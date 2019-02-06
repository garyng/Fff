#pragma once
#include "gui/IGui.h"
#include "IObject.h"
#include "utilities/nameof.h"

template <class TObject, class = IsBaseOf<TObject, IObject>>
class ObjectGuiBase : public IGui
{
protected:
	std::shared_ptr<TObject> _object;
	std::shared_ptr<IObject> _castedObject;

public:
	// the object is property-injected
	std::shared_ptr<TObject> Object() const { return _object; }

	virtual void Object(std::shared_ptr<TObject> value)
	{
		_object = value;
		_castedObject = std::static_pointer_cast<IObject>(_object);
	}

	bool CanRemove() const override
	{
		return _castedObject->CanRemove();
	}

	void Render() override
	{
		ImGui::BeginDefault(GetName());
		RenderDefaultControls();
		ImGui::End();
	}

	void RenderDefaultControls()
	{
		ImGui::Text("Bounding Box");
		ImGui::DragFloat("x##Bounding Box", &_castedObject->BoundingBox().x, 0.05f, 1, 100);
		ImGui::SameLine();
		ImGui::DragFloat("y##Bounding Box", &_castedObject->BoundingBox().y, 0.05f, 1, 100);
		ImGui::SameLine();
		ImGui::DragFloat("z##Bounding Box", &_castedObject->BoundingBox().z, 0.05f, 1, 100);

		ImGui::Text("Dimension");
		ImGui::DragFloat("x##Dimension", &_castedObject->Dimension().x, 0.01f, 0.01f, 50);
		ImGui::SameLine();
		ImGui::DragFloat("y##Dimension", &_castedObject->Dimension().y, 0.01f, 0.01f, 50);
		ImGui::SameLine();
		ImGui::DragFloat("z##Dimension", &_castedObject->Dimension().z, 0.01f, 0.01f, 50);

		ImGui::Text("Scale");
		ImGui::DragFloat("x##Scale", &_castedObject->Scale().x, 0.05f, 0, 100);
		ImGui::SameLine();
		ImGui::DragFloat("y##Scale", &_castedObject->Scale().y, 0.05f, 0, 100);
		ImGui::SameLine();
		ImGui::DragFloat("z##Scale", &_castedObject->Scale().z, 0.05f, 0, 100);

		ImGui::Text("Rotation");
		ImGui::DragFloat("x##Rotation", &_castedObject->Rotation().x, 0.05f, 0, 360);
		ImGui::SameLine();
		ImGui::DragFloat("y##Rotation", &_castedObject->Rotation().y, 0.05f, 0, 360);
		ImGui::SameLine();
		ImGui::DragFloat("z##Rotation", &_castedObject->Rotation().z, 0.05f, 0, 360);


		ImGui::Text("Max Rotation");
		ImGui::DragFloat("x##MaxRotation", &_castedObject->MaxRotation().x, 0.05f, -100, 100);
		ImGui::SameLine();
		ImGui::DragFloat("y##MaxRotation", &_castedObject->MaxRotation().y, 0.05f, -100, 100);
		ImGui::SameLine();
		ImGui::DragFloat("z##MaxRotation", &_castedObject->MaxRotation().z, 0.05f, -100, 100);

		ImGui::Text("Min Rotation");
		ImGui::DragFloat("x##Min Rotation", &_castedObject->MinRotation().x, 0.05f, -100, 100);
		ImGui::SameLine();
		ImGui::DragFloat("y##Min Rotation", &_castedObject->MinRotation().y, 0.05f, -100, 100);
		ImGui::SameLine();
		ImGui::DragFloat("z##Min Rotation", &_castedObject->MinRotation().z, 0.05f, -100, 100);

		ImGui::Text("Position");
		ImGui::DragFloat("x##Position", &_castedObject->Position().x, 0.05f, -100, 100);
		ImGui::SameLine();
		ImGui::DragFloat("y##Position", &_castedObject->Position().y, 0.05f, -100, 100);
		ImGui::SameLine();
		ImGui::DragFloat("z##Position", &_castedObject->Position().z, 0.05f, -100, 100);

		ImGui::Text("Max Position");
		ImGui::DragFloat("x##MaxPosition", &_castedObject->MaxPosition().x, 0.05f, -100, 100);
		ImGui::SameLine();
		ImGui::DragFloat("y##MaxPosition", &_castedObject->MaxPosition().y, 0.05f, -100, 100);
		ImGui::SameLine();
		ImGui::DragFloat("z##MaxPosition", &_castedObject->MaxPosition().z, 0.05f, -100, 100);


		ImGui::Text("Min Position");
		ImGui::DragFloat("x##Min Position", &_castedObject->MinPosition().x, 0.05f, -100, 100);
		ImGui::SameLine();
		ImGui::DragFloat("y##Min Position", &_castedObject->MinPosition().y, 0.05f, -100, 100);
		ImGui::SameLine();
		ImGui::DragFloat("z##Min Position", &_castedObject->MinPosition().z, 0.05f, -100, 100);

		ImGui::Text("Delta position per second");
		ImGui::DragFloat("x##Delta position", &_castedObject->DeltaPosition().x, 0.05f, -100, 100);
		ImGui::SameLine();
		ImGui::DragFloat("y##Delta position", &_castedObject->DeltaPosition().y, 0.05f, -100, 100);
		ImGui::SameLine();
		ImGui::DragFloat("z##Delta position", &_castedObject->DeltaPosition().z, 0.05f, -100, 100);

		ImGui::Text("Position wrapping behaviour");

		ImGui::PushID(0);
		WrappingBehaviour position = DrawWrappingBehaviourRadios(
			static_cast<int>(_castedObject->PositionWrappingBehaviour()));
		_castedObject->PositionWrappingBehaviour(position);
		ImGui::PopID();


		ImGui::Text("Delta rotation per second");
		ImGui::DragFloat("x##Delta rotation", &_castedObject->DeltaRotation().x, 0.05f, -360, 360);
		ImGui::SameLine();
		ImGui::DragFloat("y##Delta rotation", &_castedObject->DeltaRotation().y, 0.05f, -360, 360);
		ImGui::SameLine();
		ImGui::DragFloat("z##Delta rotation", &_castedObject->DeltaRotation().z, 0.05f, -360, 360);

		ImGui::Text("Rotation wrapping behaviour");

		ImGui::PushID(1);
		WrappingBehaviour rotation = DrawWrappingBehaviourRadios(
			static_cast<int>(_castedObject->RotationWrappingBehaviour()));
		_castedObject->RotationWrappingBehaviour(rotation);
		ImGui::PopID();

		if (ImGui::Button("Remove"))
		{
			_castedObject->CanRemove(true);
		}
	}

	WrappingBehaviour DrawWrappingBehaviourRadios(int index)
	{
		ImGui::RadioButton("Wrap", &index, static_cast<int>(WrappingBehaviour::Wrap));
		ImGui::SameLine();
		ImGui::RadioButton("Stop", &index, static_cast<int>(WrappingBehaviour::Stop));
		ImGui::SameLine();
		ImGui::RadioButton("Bounce", &index, static_cast<int>(WrappingBehaviour::Bounce));
		return WrappingBehaviour(index); // need use function notation in gcc 5
	}

	std::string GetName()
	{
		return nameof(*_castedObject) + " #" + std::to_string(_castedObject->Id());
	}

	virtual ~ObjectGuiBase() = default;
};
