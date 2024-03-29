﻿#pragma once
#include "Vectors.h"
#include "GameService.h"
#include "objects/ObjectContainer.h"
#include "config/Config.h"
#include "TextureService.h"
#include "collision/CollisionService.h"

class GameRenderer // : public IOnInit
{
private:
	Vector3<float> _eye{0.0f, 1.0f, 40.0f};
	Vector3<float> _center{0.0f, 0.0f, 0.0f};
	Vector3<float> _scale{1.0f, 1.0f, 1.0f};
	Vector3<float> _rotation{30.0f, 4.0f, 0.0f};
	Vector3<float> _position{2.0f, 5.0f, -45.0f};
	Vector3<float> _up{0.0f, 1.0f, 0.0f};

	float _zNear = 0.1f;
	float _zFar = 500.0f;
	float _fieldOfView = 60.0f;
	float _aspectRatio = 1;

	std::shared_ptr<ObjectContainer> _objectContainer;
	std::shared_ptr<GameService> _gameService;
	std::shared_ptr<Config> _config;
	std::shared_ptr<TextureService> _textureService;
	std::shared_ptr<ILogger> _logger;
	std::shared_ptr<CollisionService> _collisionService;

public:

	float& ZNear() { return _zNear; }
	float& ZFar() { return _zFar; }
	float& FieldOfView() { return _fieldOfView; }

	Vector3<float>& Eye() { return _eye; }
	Vector3<float>& Center() { return _center; }
	Vector3<float>& Scale() { return _scale; }
	Vector3<float>& Rotation() { return _rotation; }
	Vector3<float>& Position() { return _position; }
	Vector3<float>& Up() { return _up; }

	GameRenderer(const std::shared_ptr<ObjectContainer>& objectContainer,
	             const std::shared_ptr<Config>& config,
	             const std::shared_ptr<TextureService>& textureService,
	             const std::shared_ptr<CollisionService>& collisionService,
	             const std::shared_ptr<ILogger>& logger,
	             const std::shared_ptr<GameService>& gameService) :
		_objectContainer(objectContainer),
		_gameService(gameService),
		_config(config),
		_textureService(textureService),
		_collisionService(collisionService),
		_logger(logger)
	{
		_aspectRatio = float(config->ViewportDimension.x) / float(config->ViewportDimension.y);
	}

	void Render();

	void Mutate();

	void OnMouse();
	void OnKeyboard();
	void BoundingBox(Vector3<float> min, Vector3<float> max);

	/*void OnInit() override
	{
	}*/
};
