#include "pch.h"
#include "JumpMutator.h"

void JumpMutator::Apply()
{
}

bool JumpMutator::CanDetach()
{
	return _gameService->TotalTimeElapsed() - _startTime > 1;
}

void JumpMutator::OnInit()
{
	_initialMinY = _target->MinPosition().y;
	_initialMaxY = _target->MaxPosition().y;
	_target->MinPosition().y = 0;
	_target->MaxPosition().y = 1;
	_target->DeltaPosition().y = 2;
	_startTime = _gameService->TotalTimeElapsed();
}

void JumpMutator::OnDetach()
{
	_target->MinPosition().y = _initialMinY;
	_target->MaxPosition().y = _initialMaxY;
	_target->Position().y = 0;
	_target->DeltaPosition().y = 0;
}
