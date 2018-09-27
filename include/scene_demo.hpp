#pragma once
#include <memory>
#include "opengl.h"
#include "shader.hpp"
#include "scene.hpp"

class DemoScene : public Scene
{
private:
	std::unique_ptr<Shader> m_shader;
	GLuint VBO;
	GLuint VAO;

public:
	DemoScene() : m_shader(new Shader())
	{
	}

	virtual ~DemoScene()
	{
		m_shader.release();
		glDeleteVertexArrays(1, &VAO);
		glDeleteBuffers(1, &VBO);
	}

	void init() override;
	void draw() override;
	void update() override;
};
