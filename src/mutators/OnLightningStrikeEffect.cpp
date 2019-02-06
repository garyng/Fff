#include "pch.h"
#include "OnLightningStrikeEffect.h"
#include "objects/IObject.h"

void OnLightningStrikeEffect::OnInit()
{
	_startTime = _gameService->TotalTimeElapsed();

	_initialDeltaRotation = _target->DeltaRotation();
	_initialMaxRotation = _target->MaxRotation();
	_initialMinRotation = _target->MinRotation();
	_initialRotation = _target->Rotation();

	_target->DeltaRotation() = {0, 0, 60};
	_target->MaxRotation() = {0, 0, 30};
	_target->MinRotation() = {0, 0, -30};
}

void OnLightningStrikeEffect::OnDetach()
{

	_target->DeltaRotation() = _initialDeltaRotation;
	_target->MaxRotation() = _initialMaxRotation;
	_target->MinRotation() = _initialMinRotation;
	_target->Rotation() = _initialRotation;
}

void OnLightningStrikeEffect::Apply()
{
}

bool OnLightningStrikeEffect::CanDetach()
{
	return _gameService->TotalTimeElapsed() - _startTime > 5;
}
