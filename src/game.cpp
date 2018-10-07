#include "game.hpp"

int Game::init()
{
	if (!glfwInit())
	{
		return EXIT_FAILURE;
	}

	int err = m_render->init();

	if (err)
		return EXIT_FAILURE;

	m_resourceManager->init();

	m_currentScene = new DemoScene(*m_resourceManager);
	m_currentScene->init();

	return EXIT_SUCCESS;
}

void Game::mainloop()
{
	while (isGameRunning())
	{
		m_render->preFrame();

		m_render->update();

		m_currentScene->update();
		m_currentScene->draw();

		m_render->postFrame();

		glfwPollEvents();
	}
}

void Game::shutdown()
{
	SAFE_DELETE(m_currentScene);
	m_render.release();
	m_resourceManager.release();
	glfwTerminate();
}
