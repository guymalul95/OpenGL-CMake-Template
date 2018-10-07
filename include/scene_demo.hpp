#pragma once
#include <memory>
#include "opengl.h"
#include "shader.hpp"
#include "scene.hpp"
#include "texture2d.hpp"

class DemoScene : public Scene
{
private:
	Shader* m_shader;
	Texture2D* m_textureSuccItJinYang;
	GLuint VBO;
	GLuint VAO;
	GLuint EBO;

public:
	DemoScene(const ResourceManager& resourceManager) : Scene(resourceManager),
	m_shader(nullptr)
	{
	}

	virtual ~DemoScene()
	{
		SAFE_DELETE(m_shader);
		SAFE_DELETE(m_textureSuccItJinYang);
		glDeleteVertexArrays(1, &VAO);
		glDeleteBuffers(1, &VBO);
		glDeleteBuffers(1, &EBO);
	}

	void init() override;
	void draw() override;
	void update() override;
};
