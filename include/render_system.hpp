#pragma once
#include <stdlib.h>
#include "opengl.h"
#include "viewport.hpp"
#include "macros.h"

class RenderSystem
{
private:
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