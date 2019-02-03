#include "pch.h"
#include "GameRenderer.h"

void GameRenderer::Mutate()
{
	auto&& io = ImGui::GetIO();
	if (io.WantCaptureMouse) return;

	float deltaX = io.MouseDelta.x;
	float deltaY = io.MouseDelta.y;
	float deltaZ = io.MouseWheel;

	if (ImGui::IsMouseDown(0)) // left button
	{
		_rotation.x += deltaY;
		_rotation.y += deltaX;
	}
	if (ImGui::IsMouseDown(1)) // right button
	{
		_position.x += -deltaX * 0.1;
		_position.y += deltaY * 0.1;
	}
	_position.z += deltaZ;
}

void GameRenderer::Render()
{
	glPushMatrix();
	{
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(_fieldOfView,
					   _aspectRatio,
					   _zNear,
					   _zFar);

		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		gluLookAt(_eye.x, _eye.y, _eye.z,
				  _center.x, _center.y, _center.z,
				  _up.x, _up.y, _up.z);

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glPushMatrix();
		{
			Mutate();
			_gameService->IncrementTime();

			glTranslatef(_position.x, _position.y, _position.z);
			glRotatef(_rotation.x, 1, 0, 0);
			glRotatef(_rotation.y, 0, 1, 0);
			glRotatef(_rotation.z, 0, 0, 1);
			glScalef(_scale.x, _scale.y, _scale.z);

			glPushMatrix();
			{
				for (auto&& object : _objectContainer->All())
				{
					glPushMatrix();
					object->Elapsed(_gameService->DeltaTime());
					object->Mutate();
					object->Render();
					object->TryDetach();
					glPopMatrix();
				}
			}
			glPopMatrix();
		}
		glPopMatrix();
	}
	glPopMatrix();

	// todo: extract this to hud
	glPushAttrib(GL_VIEWPORT_BIT);

	auto&& io = ImGui::GetIO();
	float width = io.DisplaySize.x;
	float height = io.DisplaySize.y;

	glViewport(width - 64, 0, 64, 64);
	glPushMatrix();
	{
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluOrtho2D(-1, 1, -1, 1);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		glRotatef(_rotation.x, 1, 0, 0);
		glRotatef(_rotation.y, 0, 1, 0);
		glRotatef(_rotation.z, 0, 0, 1);

		float xlen = _scale.x;
		float ylen = _scale.y;
		float zlen = _scale.z;

		glPushAttrib(GL_ENABLE_BIT);
		glDisable(GL_DEPTH_TEST);
		glDisable(GL_LIGHTING);

		glBegin(GL_LINES);
		//x-axis
		glColor3f(1, 0, 0);

		glVertex3f(0.0, 0.0, 0.0);
		glVertex3f(xlen, 0.0, 0.0);
		//x-axis arrow
		glVertex3f(xlen, 0.0, 0.0);
		glVertex3f(0.9 * xlen, 0.0, 0.05 * xlen);
		glVertex3f(xlen, 0.0, 0.0);
		glVertex3f(0.9 * xlen, 0.0, -0.05 * xlen);

		//y-axis
		glColor3f(0, 1, 0);
		glVertex3f(0.0, 0.0, 0.0);
		glVertex3f(0.0, ylen, 0.0);
		//y-axis arrow
		glVertex3f(0.0, ylen, 0.0);
		glVertex3f(0.05 * ylen, 0.9 * ylen, 0.0);
		glVertex3f(0.0, ylen, 0.0);
		glVertex3f(-0.05 * ylen, 0.9 * ylen, 0.0);

		//z-axis
		glColor3f(0, 0, 1);
		glVertex3f(0.0, 0.0, 0.0);
		glVertex3f(0.0, 0.0, zlen);
		//z-axis arrow
		glVertex3f(0.0, 0.0, zlen);
		glVertex3f(0.05 * zlen, 0.0, 0.9 * zlen);
		glVertex3f(0.0, 0.0, zlen);
		glVertex3f(-0.05 * zlen, 0.0, 0.9 * zlen);

		glEnd();

		glPopAttrib();
		glPopAttrib();
	}
	glPopMatrix();
	glPopAttrib();
}
