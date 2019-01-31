#include "pch.h"
#include "IdGenerator.h"
#include "Vector3.h"
#include <boost/format.hpp>
#include "imgui_custom.h"

using namespace std;
using namespace Hypodermic;

shared_ptr<Container> _container = nullptr;

template <class T>
class ContainerBase
{
protected:
	vector<shared_ptr<T>> _items{};
public:
	void Add(const shared_ptr<T>& item)
	{
		_items.push_back(item);
	}

	vector<shared_ptr<T>>& All()
	{
		return _items;
	}

	// todo: remove those marked as delete
};

class IGui
{
public:
	virtual void Render() = 0;
};

class GuiContainer : public ContainerBase<IGui>
{
};


// GuiRenderer?
class Gui
{
private:
	bool _showDemoWindow = true;
	bool _showAnotherWindow = false;
	ImVec4 _clearColor = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
	vector<std::shared_ptr<IGui>> _guis;
	shared_ptr<GuiContainer> _guiContainer;

public:
	Gui(const vector<std::shared_ptr<IGui>>& guis,
	    const shared_ptr<GuiContainer>& guiContainer) : _guis(guis), _guiContainer(std::move(guiContainer))
	{
	}

	void Render()
	{
		// 1. Show the big demo window (Most of the sample code is in ImGui::ShowDemoWindow()! You can browse its code to learn more about Dear ImGui!).
		if (_showDemoWindow)
			ImGui::ShowDemoWindow(&_showDemoWindow);

		// 2. Show a simple window that we create ourselves. We use a Begin/End pair to created a named window.
		{
			static float f = 0.0f;
			static int counter = 0;

			ImGui::Begin("Hello, world!"); // Create a window called "Hello, world!" and append into it.

			ImGui::Text("This is some useful text."); // Display some text (you can use a format strings too)
			ImGui::Checkbox("Demo Window", &_showDemoWindow); // Edit bools storing our window open/close state
			ImGui::Checkbox("Another Window", &_showAnotherWindow);

			ImGui::SliderFloat("float", &f, 0.0f, 1.0f); // Edit 1 float using a slider from 0.0f to 1.0f
			ImGui::ColorEdit3("clear color", (float*)&_clearColor); // Edit 3 floats representing a color

			if (ImGui::Button("Button"))
				// Buttons return true when clicked (most widgets return true when edited/activated)
				counter++;
			ImGui::SameLine();
			ImGui::Text("counter = %d", counter);

			ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate,
			            ImGui::GetIO().Framerate);
			ImGui::End();
		}

		// 3. Show another simple window.
		if (_showAnotherWindow)
		{
			ImGui::Begin("Another Window", &_showAnotherWindow);
			// Pass a pointer to our bool variable (the window will have a closing button that will clear the bool when clicked)
			ImGui::Text("Hello from another window!");
			if (ImGui::Button("Close Me"))
				_showAnotherWindow = false;
			ImGui::End();
		}

		// todo: test keyboard and mouse
		// auto&& io = ImGui::GetIO();
		for (auto&& gui : _guis)
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

class IInitializable
{
public:
	virtual ~IInitializable() = default;
	virtual void Initialize() = 0;
};


class IObject
{
	// bounding box, scale, position, rotation
protected:
	Vector3<float> _scale{0, 0, 0};
	Vector3<float> _boundingBox{ 0,0,0 };
	Vector3<float> _position{ 0,0,0 };
	Vector3<float> _rotation{ 0,0,0 };
	Vector3<float> _delta{ 0,0,0 };

	// id is property-injected
	unsigned int _id = 0;

	void ApplyTranformations()
	{
		glTranslatef(_position.x, _position.y, _position.z);
		glRotatef(_rotation.x, 1, 0, 0);
		glRotatef(_rotation.y, 0, 1, 0);
		glRotatef(_rotation.z, 0, 0, 1);
		glScalef(_scale.x, _scale.y, _scale.z);
	}

public:
	unsigned int Id() const { return _id; }
	void Id(unsigned int value) { _id = value; }

	Vector3<float>& BoundingBox() { return _boundingBox; }
	Vector3<float>& Scale() { return _scale; }
	Vector3<float>& Position() { return _position; }
	Vector3<float>& Rotation() { return _rotation; }
	Vector3<float>& Delta() { return _delta; }

	virtual ~IObject() = default;
	virtual void Render() = 0;
};

template <class TObject, class = IsBaseOf<TObject, IObject>>
class ObjectGuiBase : public IGui
{
protected:
	shared_ptr<IObject> _object;

public:
	// the object is property-injected
	shared_ptr<IObject> Object() const { return _object; }
	void Object(shared_ptr<IObject> value) { _object = value; }

	virtual ~ObjectGuiBase() = default;
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
		ApplyTranformations();

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


class ObjectContainer : public ContainerBase<IObject>
{
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

class Game : public IInitializable
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
					object->Render();
					glPopMatrix();
				}

				glColor3f(0.0, 0.0, 1.0);
				glutSolidCube(1);
			}
			glPopMatrix();
		}
		glPopMatrix();
	}

	void Initialize() override
	{
	}
};

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

		ImGui::End();
	}
};

void Loop()
{
	if (_container == nullptr) return;

	_container->resolve<Game>()->Render();

	ImGui_ImplOpenGL2_NewFrame();
	ImGui_ImplFreeGLUT_NewFrame();

	_container->resolve<Gui>()->Render();
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
	builder.registerType<Gui>()
	       .singleInstance();

	builder.registerType<Game>()
	       .as<IInitializable>()
	       .asSelf()
	       .singleInstance();

	builder.registerType<ObjectContainer>()
	       .singleInstance();
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
	auto&& initializables = _container->resolveAll<IInitializable>();
	for (auto&& init : initializables)
	{
		init->Initialize();
	}
	_container->resolve<ObjectFactory>()->Make<Triangle>();

	// todo: add new controller for spawning objects

	glutMainLoop();
	Cleanup();
	return 0;
}
