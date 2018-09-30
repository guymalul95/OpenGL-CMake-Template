#pragma once
#include <memory>
#include "opengl.h"
#include "shader.hpp"
#include "scene.hpp"
#include "stb_image.h"

class DemoScene : public Scene
{
private:
	std::unique_ptr<Shader> m_shader;
	GLuint VBO;
	GLuint VAO;
	GLuint EBO;
	unsigned int sample_texture;

public:
	DemoScene() : m_shader(new Shader())
	{
	}

	virtual ~DemoScene()
	{
		m_shader.release();
		glDeleteVertexArrays(1, &VAO);
		glDeleteBuffers(1, &VBO);
		glDeleteBuffers(1, &EBO);
		glDeleteTextures(1, &sample_texture);
	}

	void init() override;
	void draw() override;
	void update() override;
};
