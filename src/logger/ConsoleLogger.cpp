#include "pch.h"
#include "ConsoleLogger.h"
#include <iostream>

void ConsoleLogger::Debug(std::string message)
{
	std::cout << "[DEBUG] " << message << std::endl;
}

void ConsoleLogger::Info(std::string message)
{
	std::cout << "[INFO] " << message << std::endl;
}

void ConsoleLogger::Warn(std::string message)
{
	std::cout << "[WARN] " << message << std::endl;
}

void ConsoleLogger::Error(std::string message)
{
	std::cout << "[ERROR] " << message << std::endl;
}
