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
	// Get rid of first dummy error
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // uncomment this statement to fix compilation on OS X
#endif

#ifdef _DEBUG
	glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GL_TRUE);
#endif

	m_window = glfwCreateWindow(m_viewport.width, m_viewport.height, "OpenGL Template", NULL, NULL);

	if (m_window == NULL)
		return EXIT_FAILURE;

	glfwMakeContextCurrent(m_window);
	glfwSwapInterval(0);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		return EXIT_FAILURE;

#ifdef _DEBUG
	if (GLAD_GL_ARB_debug_output)
	{
		glGetError();
		glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS_ARB);
		glDebugMessageCallbackARB(sysevents::OpenGLMessageCallback, 0);
		glDebugMessageControlARB(GL_DEBUG_SOURCE_API_ARB, GL_DEBUG_TYPE_ERROR_ARB, GL_DEBUG_SEVERITY_HIGH_ARB, 0, nullptr, GL_TRUE);
	}
#endif


	glViewport(0, 0, m_viewport.width, m_viewport.height);

	return EXIT_SUCCESS;
}

void RenderSystem::update()
{
}

void RenderSystem::preFrame()
{
	glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
	glClear(CLEAR_FLAGS);
}

void RenderSystem::postFrame()
{
	glfwSwapBuffers(m_window);
}
