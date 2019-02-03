#include "pch.h"
#include "ObjectsDebugGui.h"
#include "objects/Player1.h"
#include "objects/Player2.h"
#include "objects/Triangle.h"
#include "objects/Cube.h"
#include "objects/Floor.h"

void ObjectsDebugGui::Render()
{
	ImGui::BeginDefault("Objects");
	RenderButton<Cube>();
	RenderButton<Triangle>();
	RenderButton<Floor>();
	RenderButton<Player1>();
	RenderButton<Player2>();
	ImGui::End();
}
