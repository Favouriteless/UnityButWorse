#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Transform {
public:
	glm::vec3 getPosition();
	glm::vec3 getRotation();
	glm::vec3 getScale();

	void setPosition(glm::vec3 _position); // Sets position -- Mark as dirty
	void setRotation(glm::vec3 _rotation); // Sets rotation -- Mark as dirty
	void setScale(glm::vec3 _scale); // Sets scale -- Mark as dirty

	void translate(glm::vec3 _offset); // Position += offset

	glm::mat4 getTransformMatrix(); // Handles transform dirty flag before returning

	Transform(glm::vec3 _position, glm::vec3 _rotation, glm::vec3 _scale);

private:
	glm::vec3 position;
	glm::vec3 rotation;
	glm::vec3 scale;

	bool transformIsDirty = false, positionIsDirty = false, rotationIsDirty = false, scaleIsDirty = false; // Recalculate matrix if true

	glm::mat4 positionMatrix;
	glm::mat4 rotationMatrix;
	glm::mat4 scaleMatrix;

	glm::mat4 transformMatrix; // Final output to vertex shader

	void recalculatePositionMatrix(); // Mark as dirty
	void recalculateRotationMatrix(); // Mark as dirty
	void recalculateScaleMatrix(); // Mark as dirty

	void recalculateTransformMatrix(); // Handle dirty flags before recalculating
};

#endif