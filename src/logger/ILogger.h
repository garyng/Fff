#pragma once
#include <boost/format.hpp>

class ILogger
{
protected:
	std::string format(std::string message, std::initializer_list<std::string> items)
	{
		auto&& f = boost::format(message);
		for (auto&& str : items)
		{
			f = f % str;
		}
		return f.str();
	}

public:
	virtual ~ILogger() = default;
	virtual void Debug(std::string message) = 0;

	virtual void Debug(std::string message, std::initializer_list<std::string> items)
	{
		Debug(format(message, items));
	}

	virtual void Info(std::string message) = 0;

	virtual void Info(std::string message, std::initializer_list<std::string> items)
	{
		Info(format(message, items));
	}

	virtual void Warn(std::string message) = 0;

	virtual void Warn(std::string message, std::initializer_list<std::string> items)
	{
		Warn(format(message, items));
	}

	virtual void Error(std::string message) = 0;

	virtual void Error(std::string message, std::initializer_list<std::string> items)
	{
		Error(format(message, items));
	}
};
