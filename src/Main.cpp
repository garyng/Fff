#include "pch.h"
#include "imgui_custom.h"
#include "config/Config.h"
#include "game/GameGui.h"
#include "game/GameRenderer.h"
#include "game/TextureService.h"
#include "gui/AmbientLightGui.h"
#include "gui/CubeGui.h"
#include "gui/DebugGui.h"
#include "gui/DockSpaceGui.h"
#include "gui/FloorGui.h"
#include "gui/GuiContainer.h"
#include "gui/GuiRenderer.h"
#include "gui/IGui.h"
#include "gui/ImGuiDemoGui.h"
#include "gui/ObjectsDebugGui.h"
#include "gui/player/PlayerGuiBase.h"
#include "gui/SceneSpotLightGui.h"
#include "gui/TriangleGui.h"
#include "IdGenerator.h"
#include "init/IOnInit.h"
#include "lights/SceneSpotLight.h"
#include "logger/CompositeLogger.h"
#include "logger/ConsoleLogger.h"
#include "logger/GuiLogger.h"
#include "logger/ILogger.h"
#include "mutators/FreezedMutator.h"
#include "mutators/MutatorFactory.h"
#include "mutators/PlayerKeyboardMutator.h"
#include "objects/Cube.h"
#include "objects/Floor.h"
#include "objects/food/IceCream.h"
#include "objects/Grid.h"
#include "objects/ObjectFactory.h"
#include "objects/ObjectGuiBase.h"
#include "objects/player/Player1.h"
#include "objects/player/Player2.h"
#include "objects/Triangle.h"
#include "FoodService.h"

using namespace Hypodermic;
using namespace std;

std::shared_ptr<Container> _container = nullptr;

void Loop()
{
	if (_container == nullptr) return;

	_container->resolve<GameRenderer>()->Render();

	ImGui_ImplOpenGL2_NewFrame();
	ImGui_ImplFreeGLUT_NewFrame();

	_container->resolve<GuiRenderer>()->Render();
	ImGui::Render();
	ImGuiIO& io = ImGui::GetIO();
	glViewport(0, 0, (GLsizei)io.DisplaySize.x, (GLsizei)io.DisplaySize.y);
	ImGui_ImplOpenGL2_RenderDrawData(ImGui::GetDrawData());


	glutSwapBuffers();
	glutPostRedisplay();
}

void Init(int& argc, char** argv)
{
	glutInit(&argc, argv);
	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_MULTISAMPLE | GLUT_DEPTH);

	const int height = 720;
	const int width = 1280;

	glutInitWindowSize(width, height);
	glutCreateWindow("Fff: Fight For Food");

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glFrontFace(GL_CCW);
	glShadeModel(GL_SMOOTH);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	glDisable(GL_CULL_FACE);

	glEnable(GL_LIGHTING);
	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_NORMALIZE);

	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
	glEnable(GL_LIGHT2);
	glEnable(GL_LIGHT3);
	glEnable(GL_LIGHT4);
	glEnable(GL_LIGHT5);
	glEnable(GL_LIGHT6);
	glEnable(GL_LIGHT7);

	glutDisplayFunc(Loop);
}

void InitImGui()
{
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
	ImGui::StyleColorsDark();
	ImGui_ImplFreeGLUT_Init();
	ImGui_ImplFreeGLUT_InstallFuncs();
	ImGui_ImplOpenGL2_Init();
}

void Cleanup()
{
	ImGui_ImplOpenGL2_Shutdown();
	ImGui_ImplFreeGLUT_Shutdown();
	ImGui::DestroyContext();
}

template <class TObject, class TGui, class = IsBaseOf<TObject, IObject>, class = IsBaseOf<TGui, ObjectGuiBase<TObject>>>
void registerObjectWithCustomGui(ContainerBuilder& builder)
{
	builder.registerType<TObject>();
	builder.registerType<TGui>()
	       .template as<ObjectGuiBase<TObject>>();
}

template <class TObject, class = IsBaseOf<TObject, IObject>>
void registerObject(ContainerBuilder& builder)
{
	builder.registerType<TObject>();
	builder.registerType<ObjectGuiBase<TObject>>();
}


template <class TObject, class = IsBaseOf<TObject, Player>>
void registerPlayer(ContainerBuilder& builder)
{
	builder.registerType<TObject>();
	builder.registerType<PlayerGuiBase<TObject>>()
	       .template as<ObjectGuiBase<TObject>>();
}


int main(int argc, char** argv)
{
	Init(argc, argv);
	InitImGui();

	ContainerBuilder builder;
	builder.registerType<GuiRenderer>()
	       .singleInstance();

	builder.registerType<GameRenderer>()
	       // .as<IOnInit>()
	       // .asSelf()
	       .singleInstance();

	builder.registerType<ObjectContainer>()
	       .singleInstance();
	builder.registerType<GuiContainer>()
	       .singleInstance();
	builder.registerType<ObjectFactory>()
	       .singleInstance();
	builder.registerType<GameService>()
	       .singleInstance();
	builder.registerType<FoodService>()
	       .singleInstance();
	builder.registerType<CollisionService>()
	       .singleInstance();
	builder.registerType<TextureService>()
	       .singleInstance();

	builder.registerType<IdGenerator>()
	       .singleInstance();

	builder.registerType<Config>()
	       .singleInstance();

	// DockSpace Gui must be the first
	builder.registerType<DockSpaceGui>()
	       .singleInstance()
	       .as<IGui>();

	builder.registerType<DebugGui>()
	       .singleInstance()
	       .as<IGui>();
	builder.registerType<ImGuiDemoGui>()
	       .singleInstance()
	       .as<IGui>();
	builder.registerType<ObjectsDebugGui>()
	       .singleInstance()
	       .as<IGui>();

	builder.registerType<ConsoleLogger>()
	       .as<IChildLogger>();
	builder.registerType<GuiLogger>()
	       .as<IGui>()
	       .as<IChildLogger>()
	       .singleInstance();
	builder.registerType<CompositeLogger>()
	       .as<ILogger>();

	registerObjectWithCustomGui<Triangle, TriangleGui>(builder);
	registerObjectWithCustomGui<Cube, CubeGui>(builder);
	registerObjectWithCustomGui<Floor, FloorGui>(builder);
	registerObjectWithCustomGui<AmbientLight, AmbientLightGui>(builder);
	registerObjectWithCustomGui<SceneSpotLight, SceneSpotLightGui>(builder);
	registerObject<IceCream>(builder);
	registerObject<Grid>(builder);
	registerPlayer<Player1>(builder);
	registerPlayer<Player2>(builder);


	builder.registerInstanceFactory([&](ComponentContext& context)
	{
		return make_shared<GameGui>(context.resolve<GameRenderer>());
	}).as<IGui>();

	_container = builder.build();

	// todo: try this initialization
	auto&& initializables = _container->resolveAll<IOnInit>();
	for (auto&& init : initializables)
	{
		init->OnInit();
	}

	// todo: start only when user pressed key?
	_container->resolve<TextureService>()->LoadAll();

	// _container->resolve<ObjectFactory>()->Make<Triangle>();
	// _container->resolve<ObjectFactory>()->Make<Cube>();
	_container->resolve<ObjectFactory>()->Make<Floor>();
	_container->resolve<ObjectFactory>()->Make<Grid>();
	_container->resolve<ObjectFactory>()->Make<Player1>();
	_container->resolve<ObjectFactory>()->Make<Player2>();
	//_container->resolve<ObjectFactory>()->Make<IceCream>();
	//_container->resolve<ObjectFactory>()->Make<AmbientLight>();	// seems better without ambient light
	_container->resolve<ObjectFactory>()->Make<SceneSpotLight>();

	// todo: attach all
	// _container->resolve<MutatorFactory>()->Attach<KeyboardMutator, Cube>();
	// _container->resolve<MutatorFactory>()->Attach<FreezedMutator, Cube>();
	_container->resolve<MutatorFactory>()->Attach<PlayerKeyboardMutator, Player1>();
	_container->resolve<MutatorFactory>()->Attach<PlayerKeyboardMutator, Player2>();

	_container->resolve<GameService>()->Start();

	glutMainLoop();
	Cleanup();
	return 0;
}
