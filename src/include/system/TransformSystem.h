#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class TransformSystem {
public:
	void setPosition(glm::vec3 _position); // Mark as dirty
	void setRotation(glm::vec3 _rotation); // Mark as dirty
	void setScale(glm::vec3 _scale); // Mark as dirty

	glm::vec3 getPosition();
	glm::vec3 getRotation();
	glm::vec3 getScale();
	glm::mat4 getTransformMatrix(); // Handles transform dirty flag before returning
	bool getDirty();

	void translate(glm::vec3 _offset); // Position += offset

	TransformSystem(glm::vec3 _position, glm::vec3 _rotation, glm::vec3 _scale);

private:

};