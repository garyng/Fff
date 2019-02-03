#include "pch.h"
#include "AmbientLight.h"

void AmbientLight::Render()
{
	// todo: should call apply in ambient light?
	Apply();
	glLightfv(GL_LIGHT0, GL_DIFFUSE, (float*)&_diffuse);
	float position[]{_position.x, _position.y, _position.z, 0};
	glLightfv(GL_LIGHT0, GL_POSITION, position);
}
