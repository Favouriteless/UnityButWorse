#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Transform {
public:
	glm::vec3 getPosition();
	float getRotation();
	glm::vec3 getScale();

	void setPosition(glm::vec3 _position); // Sets position -- Recalculate position matrix
	void setRotation(float _rotation); // Sets rotation -- Recalculate rotation matrix
	void setScale(glm::vec3 _scale); // Sets scale -- Recalculate scale matrix

	void translate(glm::vec3 _offset); // Position += offset

	glm::mat4 getTransformMatrix();

	Transform(glm::vec3 _position, float _rotation, glm::vec3 _scale);

private:
	glm::vec3 position;
	float rotation;
	glm::vec3 scale;

	bool isDirty; // Recalculate final transform matrix if true

	glm::mat4 positionMatrix;
	glm::mat4 rotationMatrix;
	glm::mat4 scaleMatrix;

	glm::mat4 transformMatrix; // Final output to vertex shader

	void recalculatePositionMatrix(); // Mark as dirty
	void recalculateRotationMatrix(); // Mark as dirty
	void recalculateScaleMatrix(); // Mark as dirty

	void recalculateTransformMatrix();
};

#endif