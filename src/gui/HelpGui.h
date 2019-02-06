#pragma once
#include "IGui.h"
#include "config/Config.h"

class HelpGui : public IGui
{
private:
	std::shared_ptr<Config> _config;
public:
	HelpGui(const std::shared_ptr<Config>& config)
		: _config(config)
	{
	}

	void Render() override;
};
