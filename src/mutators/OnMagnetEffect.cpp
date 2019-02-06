#include "pch.h"
#include "OnMagnetEffect.h"
#include "objects/food/IFood.h"
#include "objects/ObjectContainer.h"

void OnMagnetEffect::OnInit()
{
	for (auto food : _objectContainer->AllOfBase<IFood>())
	{
		food->Position().x = std::min(_target->BoundingBoxMax().x + 5, _config->WorldMax.x);
		food->Position().z = _target->Position().z;
	}
	_canDetach = true;
}

void OnMagnetEffect::Apply()
{
}

bool OnMagnetEffect::CanDetach()
{
	return _canDetach;
}
