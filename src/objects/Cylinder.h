#pragma once
#include "IObject.h"

class Cylinder : public IObject
{
private:
	Vector3<float> _diffuse{1, 1, 1};
public:
	void Render() override
	{
		Apply();

		glPushAttrib(GL_LIGHTING_BIT);
		glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, (float*)&_diffuse);
		glColor3f(1, 1, 1);


		glRotatef(90, 1, 0, 0);
		glutSolidCylinder(1, 1, 64, 64);


		glPopAttrib();

		// glDisable(GL_LIGHT2);
	}
};
