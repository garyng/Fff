#pragma once
#include "gui/IGui.h"
#include "IObject.h"

template <class TObject, class = IsBaseOf<TObject, IObject>>
class ObjectGuiBase : public IGui
{
protected:
	std::shared_ptr<TObject> _object;
	
public:
	// the object is property-injected
	std::shared_ptr<TObject> Object() const { return _object; }
	void Object(std::shared_ptr<TObject> value) { _object = value; }

	virtual ~ObjectGuiBase() = default;
};
