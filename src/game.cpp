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

	// Hookup system events callbacks
	GLFWwindow *window = m_render->getGLFWwindow();

	glfwSetFramebufferSizeCallback(window, sysevents::framebuffer_size_callback);
	glfwSetKeyCallback(window, sysevents::key_callback);

	return EXIT_SUCCESS;
}

void Game::mainloop()
{
	while (isGameRunning())
	{
		m_render->preFrame();

		m_render->update();
		m_render->draw();

		m_render->postFrame();
		
		glfwPollEvents();
	}
}

void Game::shutdown()
{
	SAFE_DELETE(m_render);
	glfwTerminate();
}
