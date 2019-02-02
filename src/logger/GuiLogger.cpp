#include "pch.h"
#include "GuiLogger.h"

void GuiLogger::Debug(std::string message)
{
	_messages.push_back("[DEBUG] " + message);
	_scrollToBottom = true;
}

void GuiLogger::Info(std::string message)
{
	_messages.push_back("[INFO] " + message);
	_scrollToBottom = true;
}

void GuiLogger::Warn(std::string message)
{
	_messages.push_back("[WARN] " + message);
	_scrollToBottom = true;
}

void GuiLogger::Error(std::string message)
{
	_messages.push_back("[ERROR] " + message);
	_scrollToBottom = true;
}

void GuiLogger::Render()
{
	ImGui::Begin("Logs");
	if (ImGui::Button("Clear"))
	{
		_messages.clear();
	}
	ImGui::BeginChild("Logs");
	{
		for (auto&& message : _messages)
		{
			ImGui::Text(message.c_str());
		}
		if (_scrollToBottom)
		{
			ImGui::SetScrollHereY(1);
			_scrollToBottom = false;
		}
	}
	ImGui::EndChild();
	ImGui::End();
}
