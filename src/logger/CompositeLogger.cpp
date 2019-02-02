#include "pch.h"
#include "CompositeLogger.h"

CompositeLogger::CompositeLogger(const std::vector<std::shared_ptr<IChildLogger>>& loggers): _loggers(loggers)
{
}

void CompositeLogger::Debug(std::string message)
{
	for (auto&& logger : _loggers)
	{
		logger->Debug(message);
	}
}

void CompositeLogger::Info(std::string message)
{
	for (auto&& logger : _loggers)
	{
		logger->Info(message);
	}
}

void CompositeLogger::Warn(std::string message)
{
	for (auto&& logger : _loggers)
	{
		logger->Warn(message);
	}
}

void CompositeLogger::Error(std::string message)
{
	for (auto&& logger : _loggers)
	{
		logger->Error(message);
	}
}
