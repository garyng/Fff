#pragma once
#include "config/Config.h"

class TextureService
{
private:
	std::shared_ptr<Config> _config;
	std::shared_ptr<ILogger> _logger;
	unsigned int _brick;
	unsigned int _sand;
	unsigned int _marble;
	unsigned int _asphalt;

public:
	unsigned int Brick() const { return _brick; }
	unsigned int Sand() const { return _sand; }
	unsigned int Marble() const { return _marble; }
	unsigned int Asphalt() const { return _asphalt; }


	TextureService(const std::shared_ptr<Config>& config, const std::shared_ptr<ILogger>& logger)
		: _config(config),
		_logger(logger)
	{
	}

	void LoadAll();
	unsigned int Load(std::string filepath);
};
