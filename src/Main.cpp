#include "pch.h"
#include "Vector3.h"
#include <boost/format.hpp>
#include "imgui_custom.h"
#include "ContainerBase.h"
#include "IGui.h"
#include "GuiContainer.h"
#include "IObject.h"
#include "ObjectContainer.h"
#include "IdGenerator.h"
#include "ObjectGuiBase.h"

using namespace std;
using namespace Hypodermic;

shared_ptr<Container> _container = nullptr;

class GuiRenderer
{
private:
	bool _showDemoWindow = true;
	vector<std::shared_ptr<IGui>> _globalGuis;
	shared_ptr<GuiContainer> _guiContainer;

public:
	GuiRenderer(const vector<std::shared_ptr<IGui>>& globalGuis,
	            const shared_ptr<GuiContainer>& guiContainer) : _globalGuis(globalGuis),
	                                                            _guiContainer(guiContainer)
	{
	}

	void Render()
	{
		if (_showDemoWindow)
			ImGui::ShowDemoWindow(&_showDemoWindow);

		// todo: test keyboard and mouse
		// auto&& io = ImGui::GetIO();
		for (auto&& gui : _globalGuis)
		{
			// render global gui
			gui->Render();
		}
		for (auto&& gui : _guiContainer->All())
		{
			// render gui that has object
			gui->Render();
		}
	}
};

class IOnInit
{
public:
	virtual ~IOnInit() = default;
	virtual void OnInit() = 0;
};


class Triangle : public IObject
{
public:
	Triangle()
	{
		_scale = Vector3<float>{1, 1, 1};
	}

	void Render() override
	{
		ApplyTransformations();

		glColor3f(1.0, 0.0, 0.0);
		glBegin(GL_TRIANGLES);
		glVertex3f(-1.0, -1.0, 0.0);
		glVertex3f(1.0, -1.0, 0.0);
		glVertex3f(0.0, 1.0, 0.0);
		glEnd();
	}
};

class TriangleGui : public ObjectGuiBase<Triangle>
{
public:

	void Render() override
	{
		const string name = "Triangle #" + to_string(_object->Id());
		ImGui::BeginDefaultResizableWindow(name);


		ImGui::Text("Scale");
		ImGui::DragFloat("x##Scale", &_object->Scale().x, 0.05, 0, 100);
		ImGui::DragFloat("y##Scale", &_object->Scale().y, 0.05, 0, 100);
		ImGui::DragFloat("z##Scale", &_object->Scale().z, 0.05, 0, 100);


		ImGui::Text("Rotation");
		ImGui::DragFloat("x##Rotation", &_object->Rotation().x, 0.05, 0, 360);
		ImGui::DragFloat("y##Rotation", &_object->Rotation().y, 0.05, 0, 360);
		ImGui::DragFloat("z##Rotation", &_object->Rotation().z, 0.05, 0, 360);

		ImGui::Text("Position");
		ImGui::DragFloat("x##Position", &_object->Position().x, 0.05, -100, 100);
		ImGui::DragFloat("y##Position", &_object->Position().y, 0.05, -100, 100);
		ImGui::DragFloat("z##Position", &_object->Position().z, 0.05, -100, 100);

		ImGui::End();
	}
};


class ObjectFactory
{
private:
	// todo: mutator

	shared_ptr<Container> _container;
	shared_ptr<ObjectContainer> _objectContainer;
	shared_ptr<GuiContainer> _guiContainer;
	shared_ptr<IdGenerator> _idGenerator;
public:
	ObjectFactory(const shared_ptr<Container>& container,
	              const shared_ptr<ObjectContainer>& objectContainers,
	              const shared_ptr<GuiContainer>& guiContainer,
	              const shared_ptr<IdGenerator>& idGenerator)
		: _container(container),
		  _objectContainer(objectContainers),
		  _guiContainer(guiContainer), _idGenerator(idGenerator)
	{
	}

	template <class TObject, class = IsBaseOf<TObject, IObject>>
	void Make()
	{
		shared_ptr<IObject> object = _container->resolve<TObject>();
		object->Id(_idGenerator->Next());

		shared_ptr<ObjectGuiBase<TObject>> gui = _container->resolve<ObjectGuiBase<TObject>>();
		gui->Object(object);
		_objectContainer->Add(object);
		_guiContainer->Add(gui);
	}
};

class IMutator
{
public:
	virtual ~IMutator() = default;
	virtual void Mutate() = 0;
};

//class MutatorContainer : public ContainerBase<IMutator>
//{
//};

class Game : public IOnInit
{
private:
	// move into config
	int height = 720;
	int width = 1280;

	Vector3<float> _eye{0.0, 1.0, 40.0};
	Vector3<float> _center{0.0, 0.0, 0.0};
	Vector3<float> _scale{1.0, 1.0, 1.0};
	Vector3<float> _rotation{0.0, 0.0, 0.0};
	Vector3<float> _position{0.0, 0.0, 0.0};
	Vector3<float> _up{0.0, 1.0, 0.0};

	float zNear = 0.1;
	float zFar = 500.0;
	float fieldOfView = 60.0;
	float aspectRatio = static_cast<GLdouble>(width) / height;
	shared_ptr<ObjectContainer> _objectContainer;

public:

	Vector3<float>& Eye() { return _eye; }
	Vector3<float>& Center() { return _center; }
	Vector3<float>& Scale() { return _scale; }
	Vector3<float>& Rotation() { return _rotation; }
	Vector3<float>& Position() { return _position; }
	Vector3<float>& Up() { return _up; }

	Game(const shared_ptr<ObjectContainer>& objectContainer) : _objectContainer(objectContainer)
	{
	}

	void Render()
	{
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(fieldOfView,
		               aspectRatio,
		               zNear,
		               zFar);

		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		gluLookAt(_eye.x, _eye.y, _eye.z,
		          _center.x, _center.y, _center.z,
		          _up.x, _up.y, _up.z);

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glPushMatrix();
		{
			Mutate();

			glTranslatef(_position.x, _position.y, _position.z);
			glRotatef(_rotation.x, 1, 0, 0);
			glRotatef(_rotation.y, 0, 1, 0);
			glRotatef(_rotation.z, 0, 0, 1);
			glScalef(_scale.x, _scale.y, _scale.z);

			// todo: apply mutator
			glPushMatrix();
			{
				for (auto&& object : _objectContainer->All())
				{
					glPushMatrix();
					// must apply before an object renders, not on one shot
					// object->Mutate(); ->Attach() , ->Detach(), Mutator->Apply()
					object->Render();
					glPopMatrix();
				}
			}
			glPopMatrix();
		}
		glPopMatrix();
	}

	void Mutate()
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
		_position.z += deltaZ * 0.1;
	}

	void OnInit() override
	{
	}
};

//
//class GameMutator : public IMutator
//{
//private:
//	std::shared_ptr<Game> _game;
//public:
//	// todo: get iobject from objectfactory
//	GameMutator(std::shared_ptr<Game> game) : _game(game)
//	{
//	}
//};


class GameGui : public IGui
{
private:
	std::shared_ptr<Game> _game;

public:
	GameGui(std::shared_ptr<Game> game) : _game(game)
	{
	}

	void Render()
	{
		ImGui::BeginDefaultResizableWindow("Game");

		ImGui::Text("Eye");
		ImGui::DragFloat("x##Eye", &_game->Eye().x, 0.05, 0, 100);
		ImGui::DragFloat("y##Eye", &_game->Eye().y, 0.05, 0, 100);
		ImGui::DragFloat("z##Eye", &_game->Eye().z, 0.05, 0, 100);

		ImGui::Text("Center");
		ImGui::DragFloat("x##Center", &_game->Center().x, 0.05, 0, 100);
		ImGui::DragFloat("y##Center", &_game->Center().y, 0.05, 0, 100);
		ImGui::DragFloat("z##Center", &_game->Center().z, 0.05, 0, 100);

		ImGui::Text("Scale");
		ImGui::DragFloat("x##Scale", &_game->Scale().x, 0.05, 1, 10);
		ImGui::DragFloat("y##Scale", &_game->Scale().y, 0.05, 1, 10);
		ImGui::DragFloat("z##Scale", &_game->Scale().z, 0.05, 1, 10);

		ImGui::Text("Rotation");
		ImGui::DragFloat("x##Rotation", &_game->Rotation().x, 0.05, 0, 100);
		ImGui::DragFloat("y##Rotation", &_game->Rotation().y, 0.05, 0, 100);
		ImGui::DragFloat("z##Rotation", &_game->Rotation().z, 0.05, 0, 100);

		ImGui::Text("Position");
		ImGui::DragFloat("x##Position", &_game->Position().x, 0.05, -100, 100);
		ImGui::DragFloat("y##Position", &_game->Position().y, 0.05, -100, 100);
		ImGui::DragFloat("z##Position", &_game->Position().z, 0.05, -100, 100);


		ImGui::End();
	}
};

class DebugGui : public IGui
{
private:
	shared_ptr<ObjectFactory> _objectFactory;
public:
	DebugGui(const shared_ptr<ObjectFactory>& objectFactory): _objectFactory(objectFactory)
	{
	}

	void Render() override
	{
		ImGui::BeginDefaultResizableWindow("Debug");

		if (ImGui::Button("Spawn new Triangle"))
		{
			_objectFactory->Make<Triangle>();
		}

		ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate,
		            ImGui::GetIO().Framerate);

		ImGuiIO& io = ImGui::GetIO();

		ImGui::Text("WantCaptureMouse: %d", io.WantCaptureMouse);
		ImGui::Text("WantCaptureKeyboard: %d", io.WantCaptureKeyboard);
		ImGui::Text("WantTextInput: %d", io.WantTextInput);
		ImGui::Text("WantSetMousePos: %d", io.WantSetMousePos);

		if (ImGui::IsMousePosValid())
			ImGui::Text("Mouse pos: (%g, %g)", io.MousePos.x, io.MousePos.y);
		else
			ImGui::Text("Mouse pos: <INVALID>");
		ImGui::Text("Mouse delta: (%g, %g)", io.MouseDelta.x, io.MouseDelta.y);
		ImGui::Text("Mouse down:");
		for (int i = 0; i < IM_ARRAYSIZE(io.MouseDown); i++)
			if (io.MouseDownDuration[i] >= 0.0f)
			{
				ImGui::SameLine();
				ImGui::Text("b%d (%.02f secs)", i, io.MouseDownDuration[i]);
			}
		ImGui::Text("Mouse clicked:");
		for (int i = 0; i < IM_ARRAYSIZE(io.MouseDown); i++)
			if (ImGui::IsMouseClicked(i))
			{
				ImGui::SameLine();
				ImGui::Text("b%d", i);
			}
		ImGui::Text("Mouse dbl-clicked:");
		for (int i = 0; i < IM_ARRAYSIZE(io.MouseDown); i++)
			if (ImGui::IsMouseDoubleClicked(i))
			{
				ImGui::SameLine();
				ImGui::Text("b%d", i);
			}
		ImGui::Text("Mouse released:");
		for (int i = 0; i < IM_ARRAYSIZE(io.MouseDown); i++)
			if (ImGui::IsMouseReleased(i))
			{
				ImGui::SameLine();
				ImGui::Text("b%d", i);
			}
		ImGui::Text("Mouse wheel: %.1f", io.MouseWheel);

		ImGui::Text("Keys down:");
		for (int i = 0; i < IM_ARRAYSIZE(io.KeysDown); i++)
			if (io.KeysDownDuration[i] >= 0.0f)
			{
				ImGui::SameLine();
				ImGui::Text("%d (%.02f secs)", i, io.KeysDownDuration[i]);
			}
		ImGui::Text("Keys pressed:");
		for (int i = 0; i < IM_ARRAYSIZE(io.KeysDown); i++)
			if (ImGui::IsKeyPressed(i))
			{
				ImGui::SameLine();
				ImGui::Text("%d", i);
			}
		ImGui::Text("Keys release:");
		for (int i = 0; i < IM_ARRAYSIZE(io.KeysDown); i++)
			if (ImGui::IsKeyReleased(i))
			{
				ImGui::SameLine();
				ImGui::Text("%d", i);
			}
		ImGui::Text("Keys mods: %s%s%s%s", io.KeyCtrl ? "CTRL " : "", io.KeyShift ? "SHIFT " : "",
		            io.KeyAlt ? "ALT " : "", io.KeySuper ? "SUPER " : "");

		ImGui::End();
	}
};

void Loop()
{
	if (_container == nullptr) return;

	_container->resolve<Game>()->Render();

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
	// Create GLUT window
	glutInit(&argc, argv);
	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_MULTISAMPLE | GLUT_DEPTH);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glFrontFace(GL_CCW);
	glShadeModel(GL_SMOOTH);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	// glEnable(GL_CULL_FACE);

	const int height = 720;
	const int width = 1280;


	glutInitWindowSize(width, height);
	glutCreateWindow("Fff: Fight For Food");
	glutDisplayFunc(Loop);
}

void InitImGui()
{
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	(void)io;
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

int main(int argc, char** argv)
{
	Init(argc, argv);
	InitImGui();

	ContainerBuilder builder;
	builder.registerType<GuiRenderer>()
	       .singleInstance();

	builder.registerType<Game>()
	       .as<IOnInit>()
	       .asSelf()
	       .singleInstance();

	builder.registerType<ObjectContainer>()
	       .singleInstance();
	/*builder.registerType<MutatorContainer>()
	       .singleInstance();*/
	builder.registerType<GuiContainer>()
	       .singleInstance();
	builder.registerType<ObjectFactory>()
	       .singleInstance();

	builder.registerType<IdGenerator>()
	       .singleInstance();
	builder.registerType<DebugGui>()
	       .singleInstance()
	       .as<IGui>();

	// todo: extract to register function (+gui, +mutator etc)

	// default lifetime is transient
	builder.registerType<Triangle>();
	builder.registerType<TriangleGui>()
	       .as<ObjectGuiBase<Triangle>>();
	// .as<IGui>();


	builder.registerInstanceFactory([&](ComponentContext& context)
	{
		return make_shared<GameGui>(context.resolve<Game>());
	}).as<IGui>();

	_container = builder.build();

	// todo: try this initialization
	auto&& initializables = _container->resolveAll<IOnInit>();
	for (auto&& init : initializables)
	{
		init->OnInit();
	}
	_container->resolve<ObjectFactory>()->Make<Triangle>();

	// todo: move to mutatorfactory: attach() <- resolve object from container then add, add() <- add to container
	// _container->resolve<MutatorContainer>()->Add(make_shared<GameMutator>(_container->resolve<Game>()));

	glutMainLoop();
	Cleanup();
	return 0;
}
