#include "render_system.hpp"

void RenderSystem::shutdown()
{
	if (m_window)
	{
		glfwDestroyWindow(m_window);
		m_window = NULL;
	}
}

int RenderSystem::init()
{
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // uncomment this statement to fix compilation on OS X
#endif

	m_window = glfwCreateWindow(m_viewport.width, m_viewport.height, "OpenGL Template", NULL, NULL);

	if (m_window == NULL)
		return EXIT_FAILURE;

	glfwMakeContextCurrent(m_window);
	glfwSwapInterval(0);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		return EXIT_FAILURE;

	glGetError();
	glEnable(GL_DEPTH_TEST);
	glViewport(0, 0, m_viewport.width, m_viewport.height);

	return EXIT_SUCCESS;
}

void RenderSystem::update()
{
}

void RenderSystem::preFrame()
{
	glClearColor(0.6f, 0.8f, 0.9f, 1.0f);
	glClear(CLEAR_FLAGS);
}

void RenderSystem::postFrame()
{
	glfwSwapBuffers(m_window);
}
