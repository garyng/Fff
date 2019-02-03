#pragma once
#include "IObject.h"
#include "ContainerBase.h"

class ObjectContainer : public ContainerBase<IObject>
{
public:
	ObjectContainer(const std::shared_ptr<ILogger>& logger)
		: ContainerBase<IObject>(logger)
	{
	}

protected:
	bool Predicate(std::shared_ptr<IObject> item) override
	{
		return item->CanRemove();
	}

	void OnPurge(std::shared_ptr<IObject> item) override
	{
		_logger->Debug("Purging %1% [%2%]", { nameof(*item), std::to_string(item->Id()) });
	}
};
