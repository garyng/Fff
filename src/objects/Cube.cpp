#include <pch.h>
#include <GL/glut.h>
#include "Cube.h"

void Cube::Render()
{
	ApplyDeltas();
	ApplyTransformations();

	glColor3f(_color.x, _color.y, _color.z);
	glutSolidCube(1);
}
