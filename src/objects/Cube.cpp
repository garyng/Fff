#include <pch.h>
#include <GL/glut.h>
#include "Cube.h"

void Cube::Render()
{
	ApplyDeltas();
	Wrap();
	Transform();

	glColor3f(_color.x, _color.y, _color.z);
	glutSolidCube(1);
}
