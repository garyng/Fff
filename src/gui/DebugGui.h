#pragma once
#include "IGui.h"
#include "objects/ObjectFactory.h"
#include "logger/ILogger.h"

class DebugGui : public IGui
{
private:
	std::shared_ptr<ILogger> _logger;

public:
	DebugGui(const std::shared_ptr<ILogger>& _logger) : _logger(_logger)
	{
	}

	void Render() override;

};
