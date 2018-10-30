#pragma once
#include <stdlib.h>
#include <glad\glad.h>
#include "opengl.h"
#include "viewport.hpp"
#include "macros.h"
#include "system_events.h"

class RenderSystem
{
private:
	static const int CLEAR_FLAGS = GL_COLOR_BUFFER_BIT;
	GLFWwindow *m_window;
	Viewport m_viewport;

	void shutdown();

	NONCOPYABLE(RenderSystem);
public:
	RenderSystem() : m_viewport(800, 600)
	{
	}
	~RenderSystem() { shutdown(); }

	int init();
	void preFrame();
	void update();
	void postFrame();

	inline bool getIsWindowAlive() const
	{
		return !glfwWindowShouldClose(m_window);
	}
};