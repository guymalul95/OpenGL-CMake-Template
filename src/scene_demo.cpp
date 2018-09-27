#include "scene_demo.hpp"

void DemoScene::init()
{
	// Gen
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	// Vertex Array Object
	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	// Data
	float data[] = {
	 0.5f,  0.5f, 0.0f, 1.0f,   0.3f, 0.3f, 0.3f, 1.0f,   0.0f, 0.0f,
	 0.5f, -0.5f, 0.0f, 1.0f,   0.7f, 0.7f, 0.7f, 1.0f,   0.0f, 0.0f,
	-0.5f,  0.5f, 0.0f, 1.0f,   0.5f, 0.5f, 0.5f, 1.0f,   0.0f, 0.0f
	};
	glBufferData(GL_ARRAY_BUFFER, sizeof(data), data, GL_STATIC_DRAW);

	// Position (X,Y,Z,W)
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 10 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	// Color (R,G,B,A)
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 10 * sizeof(float), (void*)(4 * sizeof(float)));
	glEnableVertexAttribArray(1);

	// Texture Coords (U,V)
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 10 * sizeof(float), (void*)(8 * sizeof(float)));
	glEnableVertexAttribArray(2);

	glBindBuffer(GL_ARRAY_BUFFER, NULL);
	glBindVertexArray(NULL);

    m_shader->initShader(
		"assets/shaders/vertex/default.vs", 
		"assets/shaders/fragment/default.fs"
	);
}

void DemoScene::draw()
{
	m_shader->use();
	glBindVertexArray(VAO);

	glDrawArrays(GL_TRIANGLES, 0, 3);

	glBindVertexArray(NULL);
	glBindBuffer(GL_ARRAY_BUFFER, NULL);
}

void DemoScene::update()
{
}

