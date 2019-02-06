#pragma once
#include "IObject.h"

class Particle : public IObject
{
public:
	Particle()
	{
		_deltaPosition = Vector3<float>{0, 5, 0};
		_minPosition = Vector3<float>{0, 0, 0};
		_maxPosition = Vector3<float>{0, 10, 0};
	}

	void Render() override
	{
		// +--x--+
		// |     |
		// x     x
		// |	 |
		// +--x--+

		Apply();
		glColor3f(0.5f, 0.5f, 0.5f);
		glutSolidSphere(0.5, 64, 64);
		glPushMatrix();
		{
			
			glTranslatef(-0.5, 0, 0);
			glutSolidSphere(0.5, 64, 64);
		}
		glPopMatrix();
		glPushMatrix();
		{
			glTranslatef(0.5, 0, 0);
			glutSolidSphere(0.5, 64, 64);
		}
		glPopMatrix();

		glPushMatrix();
		{
			glTranslatef(0, 0, 0.5);
			glutSolidSphere(0.5, 64, 64);
		}
		glPopMatrix();

		glPushMatrix();
		{
			glTranslatef(0, 0, -0.5);
			glutSolidSphere(0.5, 64, 64);
		}
		glPopMatrix();

	}
};
