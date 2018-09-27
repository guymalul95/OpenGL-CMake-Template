#pragma once
#include <stdlib.h>
#include "opengl.h"
#include "viewport.hpp"
#include "scene.hpp"
#include "scene_demo.hpp"
#include "macros.h"

class RenderSystem
{
private:
	GLFWwindow *m_window;
	Viewport m_viewport;
	Scene *m_currentScene;

	void shutdown();

	// Copy is not allowed
	RenderSystem(const RenderSystem &) = delete;
	RenderSystem &operator=(const RenderSystem &) = delete;

public:
	RenderSystem() : m_viewport(800, 600)
	{
		m_currentScene = nullptr;
	}
	~RenderSystem() { shutdown(); }

	int init();
	void preFrame();
	void update();
	void draw();
	void postFrame();

	inline bool getIsWindowAlive() const
	{
		return !glfwWindowShouldClose(m_window);
	}
};