#include "pch.h"
#include "FreezedMutator.h"

void FreezedMutator::Apply()
{
	_target->Position().x = _initialPosition.x;
	_target->Position().y = _initialPosition.y;
	_target->Position().z = _initialPosition.z;
}

bool FreezedMutator::CanDetach()
{
	return _gameService->TotalTimeElapsed() > 10;
}

void FreezedMutator::OnInit()
{
	_initialPosition = _target->Position();
}

void FreezedMutator::OnDetach()
{
	_logger->Debug("Detach %1% from %2% [#%3%]", {nameof(*this), nameof(*_target), std::to_string(_target->Id())});
}
