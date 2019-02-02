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
	}

	std::string GetName()
	{
		return nameof(*_castedObject) + " #" + std::to_string(_castedObject->Id());
	}

	virtual ~ObjectGuiBase() = default;
};
