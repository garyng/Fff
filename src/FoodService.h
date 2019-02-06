#pragma once
#include "objects/ObjectFactory.h"
#include "config/Config.h"
#include <random>
#include "objects/food/IceCream.h"
#include "objects/food/Sandwich.h"
#include "objects/food/Chocolate.h"
#include "objects/food/Soda.h"
#include "objects/food/Pizza.h"
#include "objects/food/Apple.h"
#include "objects/food/Dango.h"

#include <random>
#include <iterator>
#include "objects/powerup/Thunder.h"
#include "objects/powerup/Star.h"
#include "objects/powerup/Magnet.h"
#include "objects/powerup/Dash.h"

template <typename RandomGenerator = std::default_random_engine>
struct random_selector
{
	// from https://gist.github.com/cbsmith/5538174
	//On most platforms, you probably want to use std::random_device("/dev/urandom")()
	random_selector(RandomGenerator g = RandomGenerator(std::random_device()()))
		: gen(g)
	{
	}

	template <typename Iter>
	Iter select(Iter start, Iter end)
	{
		std::uniform_int_distribution<> dis(0, std::distance(start, end) - 1);
		std::advance(start, dis(gen));
		return start;
	}

	//convenience function
	template <typename Iter>
	Iter operator()(Iter start, Iter end)
	{
		return select(start, end);
	}

	//convenience function that works on anything with a sensible begin() and end(), and returns with a ref to the value type
	template <typename Container>
	auto operator()(const Container& c) -> decltype(*begin(c))&
	
	{
		return *select(begin(c), end(c));
	}

private:
	RandomGenerator gen;
};

class FoodService
{
private:
	std::shared_ptr<ObjectFactory> _objectFactory;
	std::shared_ptr<Config> _config;
	std::random_device _device{};
	std::vector<std::function<void(Vector3<float>)>> _foodFactory{};
	std::vector<std::function<void(Vector3<float>)>> _powerupFactory{};
	std::mt19937 _generator{_device()};
	std::uniform_real_distribution<float> _x;
	std::uniform_real_distribution<float> _z;
	std::bernoulli_distribution _powerUp{ 0.5 };


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
			},
			[&](Vector3<float> position)
			{
				auto&& object = _objectFactory->Make<Sandwich>();
				object->Position() = position;
			},
			[&](Vector3<float> position)
			{
				auto&& object = _objectFactory->Make<Chocolate>();
				object->Position() = position;
			},
			[&](Vector3<float> position)
			{
				auto&& object = _objectFactory->Make<Soda>();
				object->Position() = position;
			},
			[&](Vector3<float> position)
			{
				auto&& object = _objectFactory->Make<Pizza>();
				object->Position() = position;
			},
			[&](Vector3<float> position)
			{
				auto&& object = _objectFactory->Make<Apple>();
				object->Position() = position;
			},
			[&](Vector3<float> position)
			{
				auto&& object = _objectFactory->Make<Dango>();
				object->Position() = position;
			}
		};

		_powerupFactory = std::vector<std::function<void(Vector3<float>)>>{
			[&](Vector3<float> position)
			{
				auto&& object = _objectFactory->Make<Thunder>();
				object->Position() = position;
			},
			[&](Vector3<float> position)
			{
				auto&& object = _objectFactory->Make<Star>();
				object->Position() = position;
			},
			[&](Vector3<float> position)
			{
				auto&& object = _objectFactory->Make<Magnet>();
				object->Position() = position;
			},
			[&](Vector3<float> position)
			{
				auto&& object = _objectFactory->Make<Dash>();
				object->Position() = position;
			}
		};
		_x = std::uniform_real_distribution<float>{_config->WorldMin.x, _config->WorldMax.x};
		_z = std::uniform_real_distribution<float>{_config->WorldMin.z, _config->WorldMax.z};
	}

	void New()
	{
		RandomOf(_foodFactory);
		RandomPowerUp();
	}

	void RandomPowerUp()
	{
		if (!_powerUp(_generator)) return;
		RandomOf(_powerupFactory);
	}

	template <class T>
	void RandomOf(std::vector<T> elements)
	{
#ifdef __GNUC__
		// std::sample under gcc is very weird..
		srand(time(nullptr));
		int index = rand() % elements.size();
		elements[index](RandomVector());
#else
		std::vector<std::function<void(Vector3<float>)>> items;
		std::sample(elements.begin(), elements.end(), std::back_inserter(items),
			1, std::mt19937{ std::random_device{}() });
		items[0](RandomVector());
#endif
	}
};
