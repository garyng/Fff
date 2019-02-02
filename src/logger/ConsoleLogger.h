#pragma once
#include "IChildLogger.h"
class ConsoleLogger : public IChildLogger
{
public:

	void Debug(std::string message) override;
	void Info(std::string message) override;
	void Warn(std::string message) override;
	void Error(std::string message) override;
};
