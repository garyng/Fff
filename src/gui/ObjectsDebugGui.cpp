#include "pch.h"
#include "ObjectsDebugGui.h"
#include "objects/player/Player1.h"
#include "objects/player/Player2.h"
#include "objects/Triangle.h"
#include "objects/Cube.h"
#include "objects/Floor.h"
#include "lights/SceneSpotLight.h"


void ObjectsDebugGui::Render()
{
	ImGui::BeginDefault("Objects");
	RenderButton<Cube>();
	RenderButton<Triangle>();
	RenderButton<Floor>();
	RenderButton<Player1>();
	RenderButton<Player2>();
	RenderButton<SceneSpotLight>();
	ImGui::End();
}
