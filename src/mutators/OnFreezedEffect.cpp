#include "pch.h"
#include "OnFreezedEffect.h"
#include "objects/IObject.h"

void OnFreezedEffect::OnInit()
{
	_initialPosition = _target->Position();
	_initialDeltaPosition = _target->DeltaPosition();
	_initialMaxPosition = _target->MaxPosition();
	_initialMinPosition = _target->MinPosition(); 

	_initialRotation = _target->Rotation();
	_initialDeltaRotation = _target->DeltaRotation();
	_startTime = _gameService->TotalTimeElapsed();
	_initialWrappingBehaviour = _target->PositionWrappingBehaviour();

	_target->DeltaPosition() = {10, 0, 10};
	_target->PositionWrappingBehaviour(WrappingBehaviour::Bounce);

	_target->MaxPosition().x = _target->Position().x + 1;
	_target->MaxPosition().z = _target->Position().z + 1;
	_target->MinPosition().x = _target->Position().x - 1;
	_target->MinPosition().z = _target->Position().z - 1;
}

void OnFreezedEffect::OnDetach()
{
	_target->Rotation() = _initialRotation;
	_target->DeltaRotation() = _initialDeltaRotation;

	_target->Position() = _initialPosition;
	_target->DeltaPosition() = _initialDeltaPosition;
	_target->MinPosition() = _initialMinPosition;
	_target->MaxPosition() = _initialMaxPosition;
	_target->PositionWrappingBehaviour(_initialWrappingBehaviour);
}

void OnFreezedEffect::Apply()
{
}

bool OnFreezedEffect::CanDetach()
{
	return _gameService->TotalTimeElapsed() - _startTime > 5;
}
