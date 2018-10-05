#pragma once
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "opengl.h"
#include "macros.h"

class Shader
{
  private:
	// Members
	GLuint m_programID;

	// Checks if compilation or linking failed and if so, print the error logs
	int checkCompileErrors(GLuint object, std::string type);
	NONCOPYABLE(Shader);
  public:
	Shader()
	{
		m_programID = 0;
	}

	~Shader()
	{
		if (0 != m_programID)
			glDeleteShader(m_programID);
	}

	// Inits with two file paths
	int init(const std::string vertexPath, const std::string fragmentPath, const std::string geometryPath = std::string());

	// Compiles the shader from given source code
	// Note: geometry source code is optional
	int compile(const char *vertexSource, const char *fragmentSource, const char *geometrySource = nullptr);

	// Return the program ID
	inline GLuint ID()
	{
		return m_programID;
	}

	// sets the current shader as active
	inline void use()
	{
		glUseProgram(this->ID());
	}

	// Utility functions
	inline void setFloat(const GLchar *name, GLfloat value)
	{
		glUniform1f(glGetUniformLocation(this->ID(), name), value);
	}

	inline void setInt(const GLchar *name, GLint value)
	{
		glUniform1i(glGetUniformLocation(this->ID(), name), value);
	}

	inline void setVector2f(const GLchar *name, GLfloat x, GLfloat y)
	{
		glUniform2f(glGetUniformLocation(this->ID(), name), x, y);
	}

	inline void setVector2f(const GLchar *name, const glm::vec2 &value)
	{
		glUniform2f(glGetUniformLocation(this->ID(), name), value.x, value.y);
	}

	inline void setVector3f(const GLchar *name, GLfloat x, GLfloat y, GLfloat z)
	{
		glUniform3f(glGetUniformLocation(this->ID(), name), x, y, z);
	}

	inline void setVector3f(const GLchar *name, const glm::vec3 &value)
	{
		glUniform3f(glGetUniformLocation(this->ID(), name), value.x, value.y, value.z);
	}

	inline void setVector4f(const GLchar *name, GLfloat x, GLfloat y, GLfloat z, GLfloat w)
	{
		glUniform4f(glGetUniformLocation(this->ID(), name), x, y, z, w);
	}

	inline void setVector4f(const GLchar *name, const glm::vec4 &value)
	{
		glUniform4f(glGetUniformLocation(this->ID(), name), value.x, value.y, value.z, value.w);
	}

	inline void setMatrix4(const GLchar *name, const glm::mat4 &matrix)
	{
		glUniformMatrix4fv(glGetUniformLocation(this->ID(), name), 1, GL_FALSE, glm::value_ptr(matrix));
	}
};