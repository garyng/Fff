#include "pch.h"
#include "GameRenderer.h"

void GameRenderer::Mutate()
{
	OnMouse();
	OnKeyboard();
}

void GameRenderer::OnMouse()
{
	auto&& io = ImGui::GetIO();
	if (io.WantCaptureMouse) return;

	float deltaX = io.MouseDelta.x;
	float deltaY = io.MouseDelta.y;
	float deltaZ = io.MouseWheel * (io.KeyCtrl ? 5 : 1);

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

void GameRenderer::OnKeyboard()
{
	auto&& io = ImGui::GetIO();
	if (io.WantCaptureKeyboard) return;

	if (ImGui::IsKeyPressed(_config->ToggleGridKey, false))
	{
		_config->IsGridEnabled(!_config->IsGridEnabled());
		_config->IsWireframeEnabled(_config->IsGridEnabled());
		_config->IsLightingEnabled(!_config->IsGridEnabled());
		_config->IsTextureEnabled(!_config->IsGridEnabled());
	}
	if (ImGui::IsKeyPressed(_config->ToggleWireFrameModeKey, false))
	{
		_config->IsWireframeEnabled(!_config->IsWireframeEnabled());
	}
	if (ImGui::IsKeyPressed(_config->ToggleLightingKey, false))
	{
		_config->IsLightingEnabled(!_config->IsLightingEnabled());
	}
	if (ImGui::IsKeyPressed(_config->ToggleTextureKey, false))
	{
		_config->IsTextureEnabled(!_config->IsTextureEnabled());
	}


	if (_config->IsWireframeEnabled())
	{
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	}
	else
	{
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	}

	if (_config->IsLightingEnabled())
	{
		glEnable(GL_LIGHTING);
	}
	else
	{
		glDisable(GL_LIGHTING);
	}
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


		//// light
		//float diffuse[]{ 1, 0, 0 };
		//float specular[]{ 1, 0, 0 };
		//float direction[]{ 0, 0, -1 };
		//glLightfv(GL_LIGHT3, GL_DIFFUSE, diffuse);
		//glLightfv(GL_LIGHT3, GL_SPECULAR, specular);
		//glLightf(GL_LIGHT3, GL_SPOT_CUTOFF, 45);
		//glLightf(GL_LIGHT3, GL_SPOT_EXPONENT, 10);
		//glLightf(GL_LIGHT3, GL_CONSTANT_ATTENUATION, 1);
		//glLightf(GL_LIGHT3, GL_LINEAR_ATTENUATION, 0.05f);
		//float p[]{0, 0, 0, 1};
		//glLightfv(GL_LIGHT3, GL_POSITION, p);
		//glLightfv(GL_LIGHT3, GL_SPOT_DIRECTION, direction);

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
					glPushAttrib(GL_CURRENT_BIT);
					object->Elapsed(_gameService->DeltaTime());
					object->Mutate();
					object->Render();
					object->TryDetach();
					glPopAttrib();
					glPopMatrix();
				}
				_objectContainer->Purge();
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
