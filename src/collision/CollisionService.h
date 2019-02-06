#pragma once
#include "objects/ObjectContainer.h"
#include "objects/ObjectFactory.h"
#include "game/GameService.h"
#include "ITestCollision.h"
#include "objects/player/Player.h"
#include "objects/food/IFood.h"
#include "mutators/JumpMutator.h"
#include "mutators/OnFoodEffect.h"
#include "objects/powerup/IPowerUp.h"

class CollisionService
{
private:
	std::shared_ptr<ObjectContainer> _objectContainer;
	std::shared_ptr<ObjectFactory> _objectFactory;
	std::shared_ptr<GameService> _gameService;
	std::shared_ptr<FoodService> _foodService;
	std::shared_ptr<ILogger> _logger;
	std::shared_ptr<MutatorFactory> _mutatorFactory;

public:


	CollisionService(const std::shared_ptr<ObjectContainer>& objectContainer,
	                 const std::shared_ptr<ObjectFactory>& objectFactory,
	                 const std::shared_ptr<GameService>& gameService,
	                 const std::shared_ptr<FoodService>& foodService, const std::shared_ptr<ILogger>& logger,
	                 const std::shared_ptr<MutatorFactory>& mutatorFactory)
		: _objectContainer(objectContainer),
		  _objectFactory(objectFactory),
		  _gameService(gameService),
		  _foodService(foodService),
		  _logger(logger),
		  _mutatorFactory(mutatorFactory)
	{
	}

	void TestWithPlayers(std::shared_ptr<IObject> object)
	{
		std::shared_ptr<ITestCollision> target = std::dynamic_pointer_cast<ITestCollision>(object);
		if (target == nullptr) return;

		for (std::shared_ptr<Player> player : _objectContainer->AllOfBase<Player>())
		{
			bool intersecting = IsIntersecting(player->BoundingBoxMin(), player->BoundingBoxMax(),
			                                   object->BoundingBoxMin(), object->BoundingBoxMax());
			if (!intersecting) continue;
			_logger->Debug("Collision: %1% [#%2%] with %3% [#%4%]",
			               {
				               nameof(*player), std::to_string(player->Id()),
				               nameof(*object), std::to_string(object->Id())
			               });

			Collide(player, object);
		}
	}


	void Collide(std::shared_ptr<Player> player, std::shared_ptr<IObject> item)
	{
		std::shared_ptr<IFood> food = std::dynamic_pointer_cast<IFood>(item);
		if (food != nullptr)
		{
			OnFood(player, food);
			return;
		}
		std::shared_ptr<IPowerUp> powerup = std::dynamic_pointer_cast<IPowerUp>(item);
		// todo: fill in powerup
	}

	void OnFood(std::shared_ptr<Player> player, std::shared_ptr<IFood> food)
	{
		_mutatorFactory->Attach<OnFoodEffect>(player);
		player->Score(player->Score() + 1);
		food->CanRemove(true);
		_foodService->New();
	}

	// AABB collision test
	// https://developer.mozilla.org/en-US/docs/Games/Techniques/3D_collision_detection
	bool IsIntersecting(Vector3<float> aMin, Vector3<float> aMax, Vector3<float> bMin, Vector3<float> bMax)
	{
		return (aMin.x <= bMax.x && aMax.x >= bMin.x) &&
			(aMin.y <= bMax.y && aMax.y >= bMin.y) &&
			(aMin.z <= bMax.z && aMax.z >= bMin.z);
	}
};
