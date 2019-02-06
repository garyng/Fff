#include "pch.h"
#include "ObjectsDebugGui.h"
#include "objects/player/Player1.h"
#include "objects/player/Player2.h"
#include "objects/Triangle.h"
#include "objects/Cube.h"
#include "objects/Floor.h"
#include "lights/SceneSpotLight.h"
#include "objects/food/IceCream.h"
#include "objects/Grid.h"
#include "objects/food/Apple.h"
#include "objects/food/Pizza.h"
#include "objects/food/Soda.h"
#include "objects/food/Chocolate.h"
#include "objects/food/Sandwich.h"
#include "objects/food/Dango.h"
#include "objects/powerup/Thunder.h"
#include "objects/powerup/Star.h"
#include "objects/powerup/Magnet.h"
#include "objects/powerup/Dash.h"


void ObjectsDebugGui::Render()
{
	ImGui::BeginDefault("Objects");
	ImGui::Text("Food");
	RenderButton<Sandwich>();
	RenderButton<Chocolate>();
	RenderButton<Soda>();
	RenderButton<Pizza>();
	RenderButton<Apple>();
	RenderButton<IceCream>();
	RenderButton<Dango>();
	ImGui::Separator();

	ImGui::Text("Powerups");
	RenderButton<Thunder>();
	RenderButton<Star>();
	RenderButton<Magnet>();
	RenderButton<Dash>();

	ImGui::Separator();
	ImGui::Text("Others");
	RenderButton<Cube>();
	RenderButton<Triangle>();
	RenderButton<Floor>();
	RenderButton<Player1>();
	RenderButton<Player2>();
	RenderButton<SceneSpotLight>();
	RenderButton<Grid>();

	ImGui::End();
}
