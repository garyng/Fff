#pragma once
#include <GL/glut.h>
#include "IObject.h"

class Cube : public IObject
{
private:
	Vector3<float> _color{ 1.0, 1.0, 0.0 };
public:
	Vector3<float>& Color() { return _color; }

	void Render() override
	{
		ApplyTransformations();
		glColor3f(_color.x, _color.y, _color.z);
		glutSolidCube(1);
	}
};
