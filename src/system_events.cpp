#include "system_events.h"
/*
void set_event_dispatcher(std::weak_ptr<EventDispatcher> eventDispatcher)
{
	_eventDispatcher = eventDispatcher;
}
*/

void sysevents::framebuffer_size_callback(GLFWwindow* window, int width, int height)
{

}

void sysevents::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, true);
	}
}

void GLAPIENTRY sysevents::OpenGLMessageCallback(GLenum source,
	GLenum type,
	GLuint id,
	GLenum severity,
	GLsizei length,
	const GLchar* message,
	const void* userParam)
{
	printf( "GL CALLBACK: %s type = 0x%x, severity = 0x%x, message = %s\n",
		(type == GL_DEBUG_TYPE_ERROR_ARB ? "** GL ERROR **" : ""),
		type, severity, message);
}