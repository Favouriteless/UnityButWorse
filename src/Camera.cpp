#include <Camera.h>

void Camera::setFov(float _fov)
{
	fov = _fov;
}

glm::mat4 Camera::getViewMatrix()
{
	if (transform.getDirty())
		recalculateViewMatrix();
	return viewMatrix;
}

void Camera::recalculateViewMatrix()
{
	viewMatrix = glm::inverse(transform.getTransformMatrix());
}

Camera::Camera(glm::vec3 _position, glm::vec3 _rotation, float _fov)
	: transform(_position, _rotation, glm::vec3(1.0f)),
	fov{ _fov }
{
	recalculateViewMatrix();
}