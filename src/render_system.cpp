#include "render_system.h"

void RenderSystem::shutdown()
{
	if (m_window) {
		glfwDestroyWindow(m_window);
		m_window = NULL;
	}
}

int RenderSystem::init()
{
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	m_window = glfwCreateWindow(m_viewport.width, m_viewport.height, "OpenGL Template", NULL, NULL);

	if (m_window == NULL) return EXIT_FAILURE;

	glfwMakeContextCurrent(m_window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) return EXIT_FAILURE;

	glViewport(0, 0, m_viewport.width, m_viewport.height);

	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);

	return EXIT_SUCCESS;
}

void RenderSystem::preFrame()
{
	glClear(GL_COLOR_BUFFER_BIT);
}

void RenderSystem::postFrame()
{
	glfwSwapBuffers(m_window);
}
