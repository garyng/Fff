#pragma once
#include <GL/glut.h>
#include "IObject.h"

class Triangle : public IObject
{
private:
	Vector3<float> _color{ 1.0, 1.0, 0.0 };
public:
	Vector3<float>& Color() { return _color; }

	void Render() override
	{
		Transform();

		glColor3f(_color.x, _color.y, _color.z);
		glBegin(GL_TRIANGLES);
		glVertex3f(-1.0, -1.0, 0.0);
		glVertex3f(1.0, -1.0, 0.0);
		glVertex3f(0.0, 1.0, 0.0);
		glEnd();
	}
};
