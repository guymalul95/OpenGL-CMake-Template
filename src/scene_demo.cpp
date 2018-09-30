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
		0, 1, 3,   // first triangle
		1, 2, 3    // second triangle
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

	glBindBuffer(GL_ARRAY_BUFFER, NULL);
	glBindVertexArray(NULL);

    m_shader->initShader(
		"assets/shaders/vertex/default.glsl",
		"assets/shaders/fragment/default.glsl"
	);

	// 2d Texture
	glGenTextures(1, &sample_texture);
	glBindTexture(GL_TEXTURE_2D, sample_texture);
	
	// set the texture wrapping/filtering options (on the currently bound texture object)
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	int width, height, nrChannels;
	stbi_set_flip_vertically_on_load(true);
	unsigned char *data = stbi_load("assets/textures/suckit.jpg", &width, &height, &nrChannels, 0);
	if (data)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
	}
	else
	{
		std::cout << "Failed to load texture" << std::endl;
	}
	stbi_image_free(data);

	glBindTexture(GL_TEXTURE_2D, NULL);
}

void DemoScene::draw()
{
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, sample_texture);

	m_shader->use();
	m_shader->setInt("texture0", 0);

	glBindVertexArray(VAO);

	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

	glBindVertexArray(NULL);
	glBindBuffer(GL_ARRAY_BUFFER, NULL);
	glBindTexture(GL_TEXTURE_2D, NULL);
}

void DemoScene::update()
{
}

