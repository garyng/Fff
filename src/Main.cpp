// For Hypodermic
template<class ArgumentType, class ResultType>
struct unary_function
{
	typedef ArgumentType argument_type;
	typedef ResultType result_type;
};


#include <imgui.h>
#include <bindings/imgui_impl_freeglut.h>
#include <bindings/imgui_impl_opengl2.h>
#include <GL/freeglut.h>
#include <Hypodermic/ContainerBuilder.h>

#ifdef _MSC_VER
#pragma warning (disable: 4505) // unreferenced local function has been removed
#endif

using namespace std;
using namespace Hypodermic;

shared_ptr<Container> _container = nullptr;


class Gui
{
private:
	bool _showDemoWindow = true;
	bool _showAnotherWindow = false;
	ImVec4 _clearColor = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
public:
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

		auto&& io = ImGui::GetIO();
	}
};


void drawScene()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	// add code here to draw scene objects
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_TRIANGLES);
	glVertex3f(-1.0, -1.0, 0.0);
	glVertex3f(1.0, -1.0, 0.0);
	glVertex3f(0.0, 1.0, 0.0);
	glEnd();
}

void Loop()
{
	if (_container == nullptr) return;

	// move this into Game
	drawScene();

	// Start the Dear ImGui frame
	ImGui_ImplOpenGL2_NewFrame();
	ImGui_ImplFreeGLUT_NewFrame();

	_container->resolve<Gui>()->Render();

	// Rendering
	ImGui::Render();
	ImGuiIO& io = ImGui::GetIO();
	glViewport(0, 0, (GLsizei)io.DisplaySize.x, (GLsizei)io.DisplaySize.y);
	// glClearColor(clear_color.x, clear_color.y, clear_color.z, clear_color.w);
	// glClear(GL_COLOR_BUFFER_BIT);
	// glUseProgram(0); // You may want this if using this code in an OpenGL 3+ context where shaders may be bound, but prefer using the GL3+ code.
	ImGui_ImplOpenGL2_RenderDrawData(ImGui::GetDrawData());


	glutSwapBuffers();
	glutPostRedisplay();
}

void Init(int& argc, char** argv)
{
	// Create GLUT window
	glutInit(&argc, argv);
	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_MULTISAMPLE);
	glutInitWindowSize(1280, 720);
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

	_container = builder.build();

	glutMainLoop();
	Cleanup();
	return 0;
}
