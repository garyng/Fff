#include "pch.h"
#include "Grid.h"

void Grid::Render()
{
	if (!_config->IsGridEnabled()) return;

	Apply();
	glColor3f(1, 1, 1);

	glCallList(_quadsListId);
}

void Grid::DrawQuads()
{
	glNewList(_quadsListId, GL_COMPILE);
	{
		glTranslatef(-_dimension.x / 2, 0, -_dimension.z / 2);

		int xCount = _dimension.x / _quadDimension.x;
		int zCount = _dimension.z / _quadDimension.z;
		for (size_t z = 0; z < zCount; z++)
		{
			for (size_t x = 0; x < xCount; x++)
			{
				glPushMatrix();
				glTranslatef(x * _quadDimension.x, 0, z * _quadDimension.z);
				float trueX = x - _dimension.x / 2;
				float trueZ = z - _dimension.z / 2;
				if (trueX >= _gridMin.x && trueX <= _gridMax.x &&
					trueZ >= _gridMin.z && trueZ <= _gridMax.z)
				{
					glPushMatrix();
					{
						glRotatef(-90, 1, 0, 0);
						glScalef(0.001f, 0.001f, 0.001f);
						std::string coordinate = (boost::format("(%1%, %2%)")
							% trueX
							% trueZ).str();
						glutStrokeString(GLUT_STROKE_ROMAN, (unsigned char*)coordinate.c_str());
					}
					glPopMatrix();
				}
				DrawQuad();
				glPopMatrix();
			}
		}
	}
	glEndList();
}

void Grid::DrawQuad()
{
	glBegin(GL_QUADS);
	glVertex3f(0, 0, _quadDimension.z);
	glVertex3f(_quadDimension.x, 0, _quadDimension.z);
	glVertex3f(_quadDimension.x, 0, 0);
	glVertex3f(0, 0, 0);
	glEnd();
}
