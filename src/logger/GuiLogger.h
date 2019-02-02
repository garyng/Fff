#pragma once
#include "IChildLogger.h"
#include "gui/IGui.h"


class GuiLogger : public IChildLogger, public IGui
{
private:
	std::vector<std::string> _messages{};
	bool _scrollToBottom = false;
public:
	void Debug(std::string message) override;
	void Info(std::string message) override;
	void Warn(std::string message) override;
	void Error(std::string message) override;

	void Render() override;
};
