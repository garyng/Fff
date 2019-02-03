#include "pch.h"
#include "Vectors.h"
#include "imgui_custom.h"
#include "gui/IGui.h"
#include "gui/GuiContainer.h"
#include "IdGenerator.h"
#include "logger/ILogger.h"
#include "logger/ConsoleLogger.h"
#include "logger/GuiLogger.h"
#include "logger/CompositeLogger.h"
#include "utilities/nameof.h"
#include "gui/GuiRenderer.h"
#include "game/GameRenderer.h"
#include "objects/ObjectGuiBase.h"
#include "objects/ObjectFactory.h"
#include "gui/DebugGui.h"
#include "game/GameGui.h"
#include "mutators/MutatorFactory.h"
#include "objects/Cube.h"
#include "objects/Triangle.h"
#include "gui/ObjectsDebugGui.h"
#include "gui/DockSpaceGui.h"
#include "gui/ImGuiDemoGui.h"
#include "gui/TriangleGui.h"
#include "gui/CubeGui.h"
#include "Config.h"

using namespace Hypodermic;
using namespace std;

std::shared_ptr<Container> _container = nullptr;

class IOnInit
{
public:
	virtual ~IOnInit() = default;
	virtual void OnInit() = 0;
};

class KeyboardMutator : public IMutator
{
private:
	std::shared_ptr<ILogger> _logger;
public:

	KeyboardMutator(const std::shared_ptr<ILogger>& logger)
		: _logger(logger)
	{
	}

	void Apply() override
	{
		auto&& io = ImGui::GetIO();
		if (io.WantCaptureKeyboard) return;

		// todo: extract these into configuration
		if (io.KeysDown['w'])
		{
			_target->Position().z -= 0.01;
		}
		if (io.KeysDown['s'])
		{
			_target->Position().z += 0.01;
		}
		if (io.KeysDown['a'])
		{
			_target->Position().x -= 0.01;
		}
		if (io.KeysDown['d'])
		{
			_target->Position().x += 0.01;
		}
	}

	bool CanDetach() override
	{
		return false;
	}
};

// todo: example of skill
class FreezedMutator : public IMutator
{
private:
	std::shared_ptr<GameService> _gameService;
	std::shared_ptr<ILogger> _logger;

	Vector3<float> _initialPosition;

public:
	FreezedMutator(const std::shared_ptr<GameService>& gameService, const std::shared_ptr<ILogger>& logger)
		: _gameService(gameService), _logger(logger)
	{
	}


	void Apply() override
	{
		_target->Position().x = _initialPosition.x;
	}

	bool CanDetach() override
	{
		return _gameService->TotalTime() > 10;
	}

	void OnInit() override
	{
		_initialPosition = _target->Position();
		_logger->Debug("Saved initial position of %1%", {nameof(*_target)});
	}

	void OnDetach() override
	{
		_logger->Debug("Detach %1% from %2% [#%3%]", {nameof(*this), nameof(*_target), std::to_string(_target->Id())});
	}
};

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
void registerObject(ContainerBuilder& builder)
{
	builder.registerType<TObject>();
	builder.registerType<TGui>()
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

	registerObject<Triangle, TriangleGui>(builder);
	registerObject<Cube, CubeGui>(builder);


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
	_container->resolve<GameService>()->Start();

	_container->resolve<ObjectFactory>()->Make<Triangle>();
	_container->resolve<ObjectFactory>()->Make<Cube>();

	_container->resolve<MutatorFactory>()->Attach<KeyboardMutator, Cube>();
	_container->resolve<MutatorFactory>()->Attach<FreezedMutator, Cube>();


	glutMainLoop();
	Cleanup();
	return 0;
}
