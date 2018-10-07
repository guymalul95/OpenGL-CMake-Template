#pragma once
#include "opengl.h"
#include <memory>
namespace sysevents {
	// Private variables and functions
	namespace {
		// EventDispatcher object
		// std::weak_ptr<EventDispatcher> _eventDispatcher;
	}
	// void set_event_dispatcher(std::weak_ptr<EventDispatcher> eventDispatcher);
	void framebuffer_size_callback(GLFWwindow* window, int width, int height);
	void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
}