#include "pch.h"
#include "Floor.h"

void Floor::Render()
{
	if (_config->IsGridEnabled()) return;

	Apply();
	glColor3f(1, 1, 1);

	if (_config->IsTextureEnabled())
	{
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, _texture->Marble());
	}
	else
	{
		glDisable(GL_TEXTURE_2D);
	}

	Vector3<float> scale{_textureDimension.x / _dimension.x, 0, _textureDimension.z / _dimension.z};
	for (float z1 = BoundingBoxMin().z; z1 < BoundingBoxMax().z; z1 += _quadDimension.z)
	{
		for (float x1 = BoundingBoxMin().x; x1 < BoundingBoxMax().x; x1+= _quadDimension.x)
		{
			Vector3<float> p1{x1, 0, z1};
			Vector3<float> p2{x1 + _quadDimension.x, 0, z1 + _quadDimension.z};

			Vector3<float> t1{
				scale.x * (p1.x - BoundingBoxMin().x),
				0,
				scale.z * (p1.z - BoundingBoxMin().z)
			};
			Vector3<float> t2{
				scale.x * (p2.x - BoundingBoxMin().x),
				0,
				scale.z * (p2.z - BoundingBoxMin().z)
			};

			glBegin(GL_QUADS);
			glNormal3f(0.0f, 1.0f, 0.0f); // point upwards
			glTexCoord2f(t1.x, t1.z);
			glVertex3f(p1.x, 0, p1.z);

			glTexCoord2f(t1.x, t2.z);
			glVertex3f(p1.x, 0, p2.z);

			glTexCoord2f(t2.x, t2.z);
			glVertex3f(p2.x, 0, p2.z);

			glTexCoord2f(t2.x, t1.z);
			glVertex3f(p2.x, 0, p1.z);

			glEnd();
		}
	}
}
