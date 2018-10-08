#include "scene_demo.hpp"

void DemoScene::init()
{
	// Gen
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	// Vertex Array Object
	glBindVertexArray(VAO);

	// Data
	float vertices[] = {
	 0.5f,  0.5f, 0.0f, 1.0f, 0.9f, 0.5f, 0.9f, 1.0f, 1.0f, 1.0f,
	 0.5f, -0.5f, 0.0f, 1.0f, 0.9f, 0.5f, 0.5f, 1.0f, 1.0f, 0.0f,
	-0.5f, -0.5f, 0.0f, 1.0f, 0.5f, 0.5f, 0.9f, 1.0f, 0.0f, 0.0f,
	-0.5f,  0.5f, 0.0f, 1.0f, 0.9f, 0.5f, 0.9f, 1.0f, 0.0f, 1.0f
	};
	unsigned int indices[] = {
		0, 1, 3,
		1, 2, 3 
	};

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// Position (X,Y,Z,W)
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 10 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	// Color (R,G,B,A)
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 10 * sizeof(float), (void*)(4 * sizeof(float)));
	glEnableVertexAttribArray(1);

	// Texture Coords (U,V)
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 10 * sizeof(float), (void*)(8 * sizeof(float)));
	glEnableVertexAttribArray(2);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

    m_shader = getResourceManager().loadShader("shaders/vertex/default.glsl","shaders/fragment/default.glsl");

	m_textureSuccItJinYang = getResourceManager().loadTexture2D("textures/suckit.jpg");
}

void DemoScene::draw()
{
	m_shader->use();
	m_shader->setInt("texture0", 0);

	m_textureSuccItJinYang->activate();
	m_textureSuccItJinYang->bind();

	glBindVertexArray(VAO);

	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

	glBindVertexArray(0);

	m_textureSuccItJinYang->unbind();
}

void DemoScene::update()
{
}

