#include "pch.h"
#include "WinningMutator.h"

void WinningMutator::Apply()
{
}

bool WinningMutator::CanDetach()
{
	return _gameService->GameState() != GameStates::Ended;
}

void WinningMutator::OnInit()
{
	_initialMaxRotation = _target->MaxRotation().y;
	_initialRotationBehaviour = _target->RotationWrappingBehaviour();
	_target->MaxRotation().y = 360;
	_target->RotationWrappingBehaviour(WrappingBehaviour::Wrap);
	_target->DeltaRotation().y = 360;
}

void WinningMutator::OnDetach()
{
	_target->MaxRotation().y = _initialMaxRotation;
	_target->RotationWrappingBehaviour(_initialRotationBehaviour);
	_target->DeltaRotation().y = 0;
}
