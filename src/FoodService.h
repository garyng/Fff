#pragma once
#include "objects/ObjectFactory.h"
#include "config/Config.h"
#include <random>
#include "objects/food/IceCream.h"

class FoodService
{
private:
	std::shared_ptr<ObjectFactory> _objectFactory;
	std::shared_ptr<Config> _config;
	std::random_device _device{};
	std::vector<std::function<void(Vector3<float>)>> _foodFactory{};
	std::mt19937 _generator{_device()};
	std::uniform_real_distribution<float> _x;
	std::uniform_real_distribution<float> _z;


	Vector3<float> RandomVector()
	{
		return {_x(_generator), 0, _z(_generator)};
	}

public:


	FoodService(const std::shared_ptr<ObjectFactory>& objectFactory, const std::shared_ptr<Config>& config)
		: _objectFactory(objectFactory),
		  _config(config)
	{
		_foodFactory = std::vector<std::function<void(Vector3<float>)>>{
			[&](Vector3<float> position)
			{
				auto&& object = _objectFactory->Make<IceCream>();
				object->Position() = position;
			}
		};
		_x = std::uniform_real_distribution<float>{_config->WorldMin.x, _config->WorldMax.x};
		_z = std::uniform_real_distribution<float>{_config->WorldMin.z, _config->WorldMax.z};
	}

	void New()
	{
		std::vector<std::function<void(Vector3<float>)>> food;
#ifdef __GNUC__
		std::experimental::sample(_foodFactory.begin(), _foodFactory.end(), std::back_inserter(food),
			1, std::mt19937{ std::random_device{}() });
#else
		std::sample(_foodFactory.begin(), _foodFactory.end(), std::back_inserter(food),
		            1, std::mt19937{std::random_device{}()});
#endif

		food[0](RandomVector());
	}
};
