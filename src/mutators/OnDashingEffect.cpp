#include "pch.h"
#include "OnDashingEffect.h"
#include "objects/Chevron.h"

void OnDashingEffect::OnInit()
{
	_player = std::static_pointer_cast<Player>(_target);

	_initialDeltaMovement = _player->DeltaMovement();
	_player->DeltaMovement() = { 0.5, 0.5, 0.5 };
	_chevron = _objectFactory->Make<Chevron>();

	_chevron->Position().y += _player->BoundingBoxMax().y;
	_chevron->MinPosition().y += _player->BoundingBoxMax().y;
	_chevron->MaxPosition().y += _player->BoundingBoxMax().y + _player->Dimension().y;

	_startTime = _gameService->TotalTimeElapsed();
}

void OnDashingEffect::OnDetach()
{
	_player->DeltaMovement() = _initialDeltaMovement;
	_chevron->CanRemove(true);
}

void OnDashingEffect::Apply()
{
	_chevron->Position().x = _player->Position().x;
	_chevron->Position().z = _player->Position().z;
}

bool OnDashingEffect::CanDetach()
{
	return _gameService->TotalTimeElapsed() - _startTime > 5;
}
