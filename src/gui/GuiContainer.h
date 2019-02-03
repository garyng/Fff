#pragma once
#include "ContainerBase.h"
#include "IGui.h"

class GuiContainer : public ContainerBase<IGui>
{
public:
	GuiContainer(const std::shared_ptr<ILogger>& logger)
		: ContainerBase<IGui>(logger)
	{
	}

protected:
	bool Predicate(std::shared_ptr<IGui> item) override
	{
		return item->CanRemove();
	}

	void OnPurge(std::shared_ptr<IGui> item) override
	{
		_logger->Debug("Purging %1%", {nameof(*item)});
	}
};
