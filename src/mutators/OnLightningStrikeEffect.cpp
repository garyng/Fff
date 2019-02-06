#include "pch.h"
#include "OnLightningStrikeEffect.h"
#include "objects/IObject.h"
#include "objects/Cylinder.h"

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

	_cylinder = _objectFactory->Make<Cylinder>();

	float radius = std::max(_target->Dimension().x, _target->Dimension().z) / 2;
	_cylinder->Scale() = {radius, _config->WorldDimension.y / 2, radius};
	_cylinder->Position() = {_target->Position().x, _config->WorldMax.y, _target->Position().z};
	_cylinder->MinPosition() = {0, 0, 0};
	_cylinder->MaxPosition() = {0, _config->WorldMax.y, 0};
	_cylinder->DeltaPosition() = {0, -300, 0};
}

void OnLightningStrikeEffect::OnDetach()
{
	_target->DeltaRotation() = _initialDeltaRotation;
	_target->MaxRotation() = _initialMaxRotation;
	_target->MinRotation() = _initialMinRotation;
	_target->Rotation() = _initialRotation;
	_cylinder->CanRemove(true);
}

void OnLightningStrikeEffect::Apply()
{
	_cylinder->Position() = {_target->Position().x, _cylinder->Position().y, _target->Position().z};
	if (_cylinder->Position().y <= _config->WorldMin.y)
	{
		_cylinder->CanRemove(true);
	}
}

bool OnLightningStrikeEffect::CanDetach()
{
	return _gameService->TotalTimeElapsed() - _startTime > 5;
}
