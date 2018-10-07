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