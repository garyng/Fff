#pragma once
#include "objects/IObject.h"

class ILight : public IObject
{
protected:
	Vector3<float> _direction{0, 0, 1};
	Vector3<float> _diffuse{1, 1, 1};
	Vector3<float> _ambient{0, 0, 0};
	Vector3<float> _specular{1, 1, 1};
	float _spotCutoff = 45;
	float _spotExponent = 10;
	float _constantAttenuation = 1;
	float _linearAttenuation = 0.05f;
	float _quadraticAttenuation = 0;

public:
	Vector3<float>& Direction() { return _direction; }
	Vector3<float>& Diffuse() { return _diffuse; }
	Vector3<float>& Ambient() { return _ambient; }
	Vector3<float>& Specular() { return _specular; }
	float& SpotCutoff() { return _spotCutoff; }
	float& SpotExponent() { return _spotExponent; }
	float& ConstantAttenuation() { return _constantAttenuation; }
	float& LinearAttenuation() { return _linearAttenuation; }
	float& QuadraticAttenuation() { return _quadraticAttenuation; }
};
