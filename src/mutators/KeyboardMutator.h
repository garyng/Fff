#pragma once
#include "logger/ILogger.h"
#include "IMutator.h"

class KeyboardMutator : public IMutator
{
private:
	std::shared_ptr<ILogger> _logger;
public:

	KeyboardMutator(const std::shared_ptr<ILogger>& logger)
		: _logger(logger)
	{
	}

	void Apply() override;

	bool CanDetach() override;
};
