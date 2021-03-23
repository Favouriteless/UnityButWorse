#pragma once

#include <Transform.h>
#include <memory>

class Camera {
public:
	void setFov(float _fov);

	glm::mat4 getViewMatrix();

	Camera(glm::vec3 _position, glm::vec3 _rotation, float _fov);

private:
	glm::mat4 viewMatrix;
	float fov; // Currently no use -- need to implement this

	void recalculateViewMatrix(); // Handle dirty flags before recalculating
};