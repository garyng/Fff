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
public:
	// the size of the window
	const Vector2<int> ViewportDimension{1280, 720};
	const Vector3<float> WorldDimension{100, 100, 100};
	const Vector3<float> WorldMin{-50, -50, -50};
	const Vector3<float> WorldMax{50, 50, 50};


	const PlayerKeysBinding Player1{'w', 's', 'a', 's'};
	const PlayerKeysBinding Player2{357, 359, 356, 358}; // arrow keys
	const int ToggleTerminalKey = 96; // `
	// duration in seconds before a key is registered as key press
	const float KeyDownDuration = 0.2f;

	// game duration
	// disable mouse input on game
};
