#pragma once
#define GLFW_INCLUDE_NONE
#include <stdlib.h>
#include "render_system.h"
#include "macros.h"

class Game {
private:
	RenderSystem* m_render;

	int init();
	void mainloop();
	void shutdown();

	inline bool isGameRunning() const { return m_render->getIsWindowAlive(); }

	// Copy is not allowed
	Game(const Game&) = delete;
	Game& operator=(const Game&) = delete;
public:
	Game() {
		m_render = new RenderSystem();
	}
	
	~Game() { shutdown(); }

	void run() {
		int err = init();

		if (EXIT_SUCCESS == err) {
			mainloop();
		}
	}
};