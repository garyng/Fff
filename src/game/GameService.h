#pragma once
#include "FoodService.h"

class GameService
{
private:
	float _totalTime = 0;
	std::shared_ptr<FoodService> _foodService;
public:


	GameService(const std::shared_ptr<FoodService>& foodService)
		: _foodService(foodService)
	{
	}

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
		_foodService->New();
	}

	// Game is over
	void End()
	{
	}

	// Seconds since last game start
	float TotalTime() const { return _totalTime; }
};
