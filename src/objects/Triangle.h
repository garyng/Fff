#pragma once
#include <GL/glut.h>
#include "IObject.h"

class Triangle : public IObject
{
public:
	void Render() override
	{
		ApplyTransformations();

		glColor3f(1.0, 0.0, 0.0);
		glBegin(GL_TRIANGLES);
		glVertex3f(-1.0, -1.0, 0.0);
		glVertex3f(1.0, -1.0, 0.0);
		glVertex3f(0.0, 1.0, 0.0);
		glEnd();
	}
};
