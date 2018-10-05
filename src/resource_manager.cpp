#include "resource_manager.hpp"

int ResourceManager::init()
{
	stbi_set_flip_vertically_on_load(true);
	return 0;
}

Texture2D* ResourceManager::loadTexture2D(const std::string textureAsset) const
{
    int width, height, nrChannels;

	Texture2D* texture = Texture2D::create();
	texture->bind();
	
	// set the texture wrapping/filtering options (on the currently bound texture object)
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	const std::string textureAssetPath = getAbsolutePath(textureAsset);

	std::cout << "Loading texture2D: ";
	std::cout << textureAssetPath << std::endl;

	unsigned char *data = stbi_load(textureAssetPath.c_str(), &width, &height, &nrChannels, 0);
	if (data)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		stbi_image_free(data);
	}
	else
	{
		std::cout << textureAssetPath << std::endl;
		exit(EXIT_FAILURE);
        return nullptr;
	}
	
	texture->unbind();

	return texture;
}

Shader* ResourceManager::loadShader(const std::string vertexShader,const std::string fragmentShader) const
{
	Shader* shader = new Shader();
	std::string vertexShaderPath = getAbsolutePath(vertexShader);
	std::string fragmentShaderPath = getAbsolutePath(fragmentShader);

	std::cout << "Loading shader:";
	std::cout << vertexShaderPath;
	std::cout << ", ";
	std::cout << fragmentShaderPath << std::endl;

	int err = shader->init(vertexShaderPath,fragmentShaderPath,"");

	if(EXIT_FAILURE == err) 
	{
		std::cout << "Shader error: " + err << std::endl;
		exit(err);
	}

	return shader;
}