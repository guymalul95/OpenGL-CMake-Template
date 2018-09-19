#pragma once
#include <stdlib.h>
#include "opengl.h"
#include "viewport.h"

class RenderSystem {
private:
	GLFWwindow* m_window;
	Viewport m_viewport;

	void shutdown();

	// Copy is not allowed
	RenderSystem(const RenderSystem&) = delete;
	RenderSystem& operator=(const RenderSystem&) = delete;
public:
	RenderSystem() : m_viewport(800,600) {}
	~RenderSystem() { shutdown(); }

	int init();
	void preFrame();
	void postFrame();

	inline bool getIsWindowAlive() const {
		return !glfwWindowShouldClose(m_window);
	}
};