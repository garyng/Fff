﻿#pragma once
#include "Vector3.h"
#include "GameService.h"
#include "objects/ObjectContainer.h"

class GameRenderer // : public IOnInit
{
private:
	// todo: move window size into config
	int height = 720;
	int width = 1280;

	Vector3<float> _eye{ 0.0, 1.0, 40.0 };
	Vector3<float> _center{ 0.0, 0.0, 0.0 };
	Vector3<float> _scale{ 1.0, 1.0, 1.0 };
	Vector3<float> _rotation{ 0.0, 0.0, 0.0 };
	Vector3<float> _position{ 0.0, 0.0, 0.0 };
	Vector3<float> _up{ 0.0, 1.0, 0.0 };

	float zNear = 0.1;
	float zFar = 500.0;
	float fieldOfView = 60.0;
	float aspectRatio = static_cast<GLdouble>(width) / height;

	std::shared_ptr<ObjectContainer> _objectContainer;
	std::shared_ptr<GameService> _gameService;

public:

	Vector3<float>& Eye() { return _eye; }
	Vector3<float>& Center() { return _center; }
	Vector3<float>& Scale() { return _scale; }
	Vector3<float>& Rotation() { return _rotation; }
	Vector3<float>& Position() { return _position; }
	Vector3<float>& Up() { return _up; }

	GameRenderer(const std::shared_ptr<ObjectContainer>& objectContainer,
		const std::shared_ptr<GameService>& gameService) : _objectContainer(objectContainer),
		_gameService(gameService)
	{
	}

	void Render();

	void Mutate();

	/*void OnInit() override
	{
	}*/
};
