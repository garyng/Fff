#pragma once
#include <memory>

class IObject;

class IMutator
{
protected:
	std::shared_ptr<IObject> _target{};

public:
	std::shared_ptr<IObject> Target() const { return _target; }

	virtual void Target(std::shared_ptr<IObject> value)
	{
		_target = value;
		OnInit();
	}

	// called when the target is set
	virtual void OnInit()
	{
	}

	// called when the mutator is detached from the target
	virtual void OnDetach()
	{
	}

	virtual ~IMutator() = default;

	virtual void Apply() = 0;

	// check whether the mutator can be detached from IMutable
	virtual bool CanDetach() = 0;
};
