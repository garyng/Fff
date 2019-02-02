#pragma once
#include "ILogger.h"
#include "IChildLogger.h"

class CompositeLogger : public ILogger
{
private:
	std::vector<std::shared_ptr<IChildLogger>> _loggers;
public:


	CompositeLogger(const std::vector<std::shared_ptr<IChildLogger>>& loggers);

	void Debug(std::string message) override;

	void Info(std::string message) override;

	void Warn(std::string message) override;

	void Error(std::string message) override;
};
