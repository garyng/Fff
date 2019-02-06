#include "pch.h"
#include "SceneSpotLight.h"

void SceneSpotLight::Render()
{
	glLightfv(GL_LIGHT1, GL_AMBIENT, (float*)&_ambient);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, (float*)&_diffuse);
	glLightfv(GL_LIGHT1, GL_SPECULAR, (float*)&_specular);
	glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, _spotCutoff);
	glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, _spotExponent);
	glLightf(GL_LIGHT1, GL_CONSTANT_ATTENUATION, _constantAttenuation);
	glLightf(GL_LIGHT1, GL_LINEAR_ATTENUATION, _linearAttenuation);
	glLightf(GL_LIGHT1, GL_QUADRATIC_ATTENUATION, _quadraticAttenuation);

	Apply();

	float position[]{_position.x, _position.y, _position.z, 1};
	glLightfv(GL_LIGHT1, GL_POSITION, position);

	float direction[]{_direction.x, _direction.y, _direction.z, 1};
	glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, direction);
	glPushAttrib(GL_LIGHTING_BIT);
	glMaterialfv(GL_FRONT, GL_EMISSION, (float*)&_diffuse);
	glutSolidSphere(1, 64, 64);
	glPopAttrib();
}
