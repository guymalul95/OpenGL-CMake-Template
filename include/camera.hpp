#pragma once
#include <glm\glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Camera {
private:
	glm::mat4 m_viewMat;
public:
	Camera() {}
	~Camera() {}

	void update()
	{
		// TODO: calculate view matrix
	}

	inline glm::vec4 getViewMatrix() 
	{
		return m_viewMat;
	}
};