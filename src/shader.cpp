#include "shader.h"

int Shader::initShader(const std::string vertexPath, const std::string fragmentPath, const std::string geometryPath)
{
	std::string strVertexCode;
	std::string strFragmentCode;
	std::string strGeometryCode;

	try
	{
		std::ifstream vShaderFile;
		std::ifstream fShaderFile;
		std::ifstream gShaderFile;
		std::stringstream vShaderStream;
		std::stringstream fShaderStream;
		std::stringstream gShaderStream;

		// ensure ifstream objects can throw exceptions:
		vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
		fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
		gShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

		// open files
		vShaderFile.open(vertexPath);
		vShaderStream << vShaderFile.rdbuf();
		vShaderFile.close();
		strVertexCode = vShaderStream.str();

		fShaderFile.open(fragmentPath);
		fShaderStream << fShaderFile.rdbuf();
		fShaderFile.close();
		strFragmentCode = fShaderStream.str();

		if (!geometryPath.empty())
		{
			gShaderFile.open(geometryPath);
			gShaderStream << gShaderFile.rdbuf();
			gShaderFile.close();
			strGeometryCode = gShaderStream.str();
		}
	}
	catch (std::ifstream::failure e)
	{
		std::cout << "[ERROR] SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;

		return EXIT_FAILURE;
	}

	const char* vertexCode = strVertexCode.c_str();
	const char* fragmentCode = strFragmentCode.c_str();
	const char* geometryCode = nullptr;

	if (!strGeometryCode.empty()) {
		geometryCode = strGeometryCode.c_str();
	}

	return this->compile(vertexCode, fragmentCode, geometryCode);
}

int Shader::compile(const char* vertexSource, const char* fragmentSource, const char* geometrySource)
{
	GLuint sVertex, sFragment, sGeomentry;
	int exitStatus = EXIT_SUCCESS;

	// Vertex Shader
	sVertex = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(sVertex, 1, &vertexSource, NULL);
	glCompileShader(sVertex);
	exitStatus = exitStatus | checkCompileErrors(sVertex, "VERTEX");

	// Fragment Shader
	sFragment = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(sFragment, 1, &fragmentSource, NULL);
	glCompileShader(sFragment);
	exitStatus = exitStatus | checkCompileErrors(sFragment, "FRAGMENT");

	// If geometry shader source code is given, also compile geometry shader
	if (geometrySource != nullptr)
	{
		sGeomentry = glCreateShader(GL_GEOMETRY_SHADER);
		glShaderSource(sGeomentry, 1, &geometrySource, NULL);
		glCompileShader(sGeomentry);
		exitStatus = exitStatus | checkCompileErrors(sGeomentry, "GEOMETRY");
	}

	// Shader Program
	m_programID = glCreateProgram();
	glAttachShader(this->ID(), sVertex);
	glAttachShader(this->ID(), sFragment);

	if (geometrySource != nullptr)
		glAttachShader(this->ID(), sGeomentry);

	glLinkProgram(this->ID());
	exitStatus = exitStatus | checkCompileErrors(this->ID(), "PROGRAM");

	// Delete the shaders as they're linked into our program now and no longer necessery
	glDeleteShader(sVertex);
	glDeleteShader(sFragment);

	if (geometrySource != nullptr)
		glDeleteShader(sGeomentry);

	return exitStatus;
}

int Shader::checkCompileErrors(GLuint object, std::string type)
{
	GLint success;
	GLchar infoLog[1024];
	if (type != "PROGRAM")
	{
		glGetShaderiv(object, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(object, 1024, NULL, infoLog);
			std::cout << "| ERROR::SHADER: Compile-time error: Type: " << type << "\n"
				<< infoLog << "\n -- ----------------------------------------------------- "
				<< std::endl;
			return EXIT_FAILURE;
		}
	}
	else
	{
		glGetProgramiv(object, GL_LINK_STATUS, &success);
		if (!success)
		{
			glGetProgramInfoLog(object, 1024, NULL, infoLog);
			std::cout << "| ERROR::SHADER: Link-time error: Type: " << type << "\n"
				<< infoLog << "\n -- ----------------------------------------------------- "
				<< std::endl;
			return EXIT_FAILURE;
		}
	}

	return EXIT_SUCCESS;
}