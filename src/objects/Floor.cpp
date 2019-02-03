#include "pch.h"
#include "Floor.h"

void Floor::Render()
{
	Apply();
	glColor3f(1, 1, 1);
	int xCount = _dimension.x / _quadDimension.x;
	int zCount = _dimension.z / _quadDimension.z;

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _texture->Brick());

	for (size_t z = 0; z < zCount; z++)
	{
		for (size_t x = 0; x < xCount; x++)
		{
			glPushMatrix();
			glTranslatef(x * _quadDimension.x, 0, z * _quadDimension.z);
			DrawQuad();
			glPopMatrix();
		}
	}
}

void Floor::DrawQuad()
{
	glBegin(GL_QUADS);
	glNormal3f(0.0f, 1.0f, 0.0f); // point upwards
	glTexCoord2f(0, 1);
	glVertex3f(0, 0, _quadDimension.z);
	glTexCoord2f(1, 1);
	glVertex3f(_quadDimension.x, 0, _quadDimension.z);
	glTexCoord2f(1, 0);
	glVertex3f(_quadDimension.x, 0, 0);
	glTexCoord2f(0, 0);
	glVertex3f(0, 0, 0);
	glEnd();
}
