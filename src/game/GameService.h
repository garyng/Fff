#pragma once

class GameService
{
private:
	float _totalTime = 0;
public:
	// Seconds elapsed since last frame
	float DeltaTime()
	{
		auto&& io = ImGui::GetIO();
		return io.DeltaTime;
	}

	void IncrementTime()
	{
		_totalTime += DeltaTime();
	}

	void Start()
	{
	}

	// Game is over
	void End()
	{
	}

	// Seconds since last game start
	float TotalTime() const { return _totalTime; }
};