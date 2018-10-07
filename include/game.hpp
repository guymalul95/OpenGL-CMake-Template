#pragma once
#define GLFW_INCLUDE_NONE
#include <stdlib.h>
#include <memory>
#include "render_system.hpp"
#include "resource_manager.hpp"
#include "macros.h"
#include "scene.hpp"
#include "scene_demo.hpp"

class Game
{
  private:
	std::unique_ptr<RenderSystem> m_render;
	std::unique_ptr<ResourceManager> m_resourceManager;
	Scene *m_currentScene;

	int init();
	void mainloop();
	void shutdown();

	inline bool isGameRunning() const { return m_render->getIsWindowAlive(); }

	NONCOPYABLE(Game);

  public:
	Game() : m_render(new RenderSystem()), m_resourceManager(new ResourceManager("assets/"))
	{
	}

	~Game() { shutdown(); }

	void run()
	{
		int err = init();

		if (EXIT_SUCCESS == err)
		{
			mainloop();
		}
	}
};