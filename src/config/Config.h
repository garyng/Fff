#pragma once
#include "Vectors.h"

struct PlayerKeysBinding
{
	int Up;
	int Down;
	int Left;
	int Right;
};

class Config
{
private:
	bool _isTerminalEnabled = true;
	bool _isWireframeEnabled = false;
	bool _isLightingEnabled = true;
	bool _isTextureEnabled = true;
	bool _isGridEnabled = false;
	bool _isBoundingBoxEnabled = true;
	bool _showObjectsGui = true;
	std::shared_ptr<ILogger> _logger;


	void LogBoolean(std::string name, bool value, std::string whenTrue = "enabled", std::string whenFalse = "disabled")
	{
		_logger->Debug("%1%: %2%", {name, (value ? whenTrue : whenFalse)});
	}

public:
	// the size of the window
	const Vector2<int> ViewportDimension{1280, 720};
	const Vector3<float> WorldDimension{100, 100, 100};
	const Vector3<float> WorldMin{-50, 0, -50};
	const Vector3<float> WorldMax{50, 100, 50};


	const PlayerKeysBinding Player1Keys{'w', 's', 'a', 'd'};
	const PlayerKeysBinding Player2Keys{357, 359, 356, 358}; // arrow keys
	const int ToggleTerminalKey = 96; // `
	const int ToggleObjectsGui = '1'; // 1
	const int ToggleWireFrameModeKey = 257; // F1
	const int ToggleLightingKey = 258; // F2
	const int ToggleTextureKey = 259; // F3
	const int ToggleGridKey = 260; // F4
	const int ToggleBoundingBoxKey = 261; // F5
	const int StartRestartGameKey = ' '; // Space

	const std::string BrickTexturePath = "textures/brick.jpg";
	const std::string SandTexturePath = "textures/sand.jpg";
	const std::string MarbleTexturePath = "textures/marble.jpg";
	const std::string AsphaltTexturePath = "textures/asphalt.jpg";


	bool IsTerminalEnabled() const { return _isTerminalEnabled; }
	void IsTerminalEnabled(bool value)
	{
		_isTerminalEnabled = value;
		LogBoolean("Terminal", value);
	}

	bool IsWireframeEnabled() const { return _isWireframeEnabled; }
	void IsWireframeEnabled(bool value)
	{
		_isWireframeEnabled = value;
		LogBoolean("Wireframe mode", value);
	}

	bool IsLightingEnabled() const { return _isLightingEnabled; }
	void IsLightingEnabled(bool value)
	{
		_isLightingEnabled = value;
		LogBoolean("Lighting", value);
	}

	bool IsTextureEnabled() const { return _isTextureEnabled; }
	void IsTextureEnabled(bool value)
	{
		_isTextureEnabled = value;
		LogBoolean("Texture", value);
	}

	bool IsGridEnabled() const { return _isGridEnabled; }
	void IsGridEnabled(bool value)
	{
		_isGridEnabled = value;
		LogBoolean("Grid", value);
	}


	Config(const std::shared_ptr<ILogger>& logger)
		: _logger(logger)
	{
	}

	bool IsBoundingBoxEnabled() const { return _isBoundingBoxEnabled; }
	void IsBoundingBoxEnabled(bool value)
	{
		_isBoundingBoxEnabled = value;
		LogBoolean("Bounding box", value);
	}

	bool ShowObjectsGui() const { return _showObjectsGui; }
	void ShowObjectsGui(bool value) { _showObjectsGui = value; }
	
	


	// game duration
	// disable mouse input on game
};
