#include "pch.h"
#include "OnFoodEffect.h"
#include "objects/IObject.h"
#include "objects/Particle.h"

void OnFoodEffect::Apply()
{
	_particle->Position() = {_target->Position().x, _particle->Position().y, _target->Position().z};
}

bool OnFoodEffect::CanDetach()
{
	return _particle->Position().y >= _target->BoundingBoxMax().y + 5;
}

void OnFoodEffect::OnInit()
{
	_particle = _objectFactory->Make<Particle>();
	_particle->DeltaPosition() = {0, 20, 0};
	_particle->MaxPosition() = {0, _target->BoundingBoxMax().y + 5, 0};
	_particle->Dimension() = _target->Dimension();
	_particle->Position() = { _target->Position().x, _target->BoundingBoxMax().y, _target->Position().z };
}

void OnFoodEffect::OnDetach()
{
	_particle->CanRemove(true);
}
