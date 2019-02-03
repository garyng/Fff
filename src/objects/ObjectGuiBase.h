#pragma once
#include "gui/IGui.h"
#include "IObject.h"
#include "utilities/nameof.h"
#include <iostream>

template <class TObject, class = IsBaseOf<TObject, IObject>>
class ObjectGuiBase : public IGui
{
protected:
	std::shared_ptr<TObject> _object;
	std::shared_ptr<IObject> _castedObject;
	
public:
	// the object is property-injected
	std::shared_ptr<TObject> Object() const { return _object; }
	void Object(std::shared_ptr<TObject> value)
	{
		_object = value;
		_castedObject = std::static_pointer_cast<IObject>(_object);
	}

	void RenderDefault()
	{
		ImGui::Text("Scale");
		ImGui::DragFloat("x##Scale", &_castedObject->Scale().x, 0.05, 0, 100);
		ImGui::DragFloat("y##Scale", &_castedObject->Scale().y, 0.05, 0, 100);
		ImGui::DragFloat("z##Scale", &_castedObject->Scale().z, 0.05, 0, 100);

		ImGui::Text("Rotation");
		ImGui::DragFloat("x##Rotation", &_castedObject->Rotation().x, 0.05, 0, 360);
		ImGui::DragFloat("y##Rotation", &_castedObject->Rotation().y, 0.05, 0, 360);
		ImGui::DragFloat("z##Rotation", &_castedObject->Rotation().z, 0.05, 0, 360);

		ImGui::Text("Position");
		ImGui::DragFloat("x##Position", &_castedObject->Position().x, 0.05, -100, 100);
		ImGui::DragFloat("y##Position", &_castedObject->Position().y, 0.05, -100, 100);
		ImGui::DragFloat("z##Position", &_castedObject->Position().z, 0.05, -100, 100);

		ImGui::Text("Delta position per second");
		ImGui::DragFloat("x##Delta position", &_castedObject->DeltaPosition().x, 0.05, -100, 100);
		ImGui::DragFloat("y##Delta position", &_castedObject->DeltaPosition().y, 0.05, -100, 100);
		ImGui::DragFloat("z##Delta position", &_castedObject->DeltaPosition().z, 0.05, -100, 100);

		ImGui::Text("Position wrapping behaviour");

		ImGui::PushID(0);
		WrappingBehaviour position = DrawWrappingBehaviourRadios(static_cast<int>(_castedObject->PositionWrappingBehaviour()));
		_castedObject->PositionWrappingBehaviour(position);
		ImGui::PopID();


		ImGui::Text("Delta rotation per second");
		ImGui::DragFloat("x##Delta rotation", &_castedObject->DeltaRotation().x, 0.05, -360, 360);
		ImGui::DragFloat("y##Delta rotation", &_castedObject->DeltaRotation().y, 0.05, -360, 360);
		ImGui::DragFloat("z##Delta rotation", &_castedObject->DeltaRotation().z, 0.05, -360, 360);

		ImGui::Text("Rotation wrapping behaviour");

		ImGui::PushID(1);
		WrappingBehaviour rotation = DrawWrappingBehaviourRadios(static_cast<int>(_castedObject->RotationWrappingBehaviour()));
		_castedObject->RotationWrappingBehaviour(rotation);
		ImGui::PopID();
	}


	WrappingBehaviour DrawWrappingBehaviourRadios(int index)
	{
		ImGui::RadioButton("Wrap", &index, static_cast<int>(WrappingBehaviour::Wrap)); ImGui::SameLine();
		ImGui::RadioButton("Stop", &index, static_cast<int>(WrappingBehaviour::Stop)); ImGui::SameLine();
		ImGui::RadioButton("Bounce", &index, static_cast<int>(WrappingBehaviour::Bounce));
		return WrappingBehaviour(index); // need use function notation in gcc 5
	}

	std::string GetName()
	{
		return nameof(*_castedObject) + " #" + std::to_string(_castedObject->Id());
	}

	virtual ~ObjectGuiBase() = default;
};
