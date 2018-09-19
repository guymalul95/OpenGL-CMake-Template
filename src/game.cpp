#include "game.h"

int Game::init()
{
	if (!glfwInit()) {
		return EXIT_FAILURE;
	}

	int err = m_render->init();

	if (err) return EXIT_FAILURE;

	return EXIT_SUCCESS;
}

void Game::mainloop()
{
	while (isGameRunning()) {
		m_render->preFrame();



		m_render->postFrame();
		glfwPollEvents();
	}
}

void Game::shutdown()
{
	SAFE_DELETE(m_render);
	glfwTerminate();
}
