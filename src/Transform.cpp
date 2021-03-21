#include "Transform.h"



Transform::Transform(glm::vec3 _position, glm::vec3 _rotation, glm::vec3 _scale)
{
	setPosition(_position);
	setRotation(_rotation);
	setScale(_scale);
}

glm::vec3 Transform::getPosition()
{
	return position;
}

glm::vec3 Transform::getRotation()
{
	return rotation;
}

glm::vec3 Transform::getScale()
{
	return scale;
}

void Transform::setPosition(glm::vec3 _position)
{
	position = _position;
	positionIsDirty = true;
	transformIsDirty = true;
}

void Transform::setRotation(glm::vec3 _rotation)
{
	rotation = _rotation;
	rotationIsDirty = true;
	transformIsDirty = true;
}

void Transform::setScale(glm::vec3 _scale)
{
	scale = _scale;
	scaleIsDirty = true;
	transformIsDirty = true;
}

void Transform::translate(glm::vec3 _offset)
{
	setPosition(position + _offset);
}

void Transform::recalculatePositionMatrix()
{
	positionMatrix = glm::translate(glm::mat4(1.0f), position);
	positionIsDirty = false;
}

void Transform::recalculateRotationMatrix()
{
	rotationMatrix = glm::rotate(glm::mat4(1.0f), rotation.z, glm::vec3(0.0f, 0.0f, 1.0f));
	rotationMatrix = glm::rotate(rotationMatrix, rotation.y, glm::vec3(0.0f, 1.0f, 0.0f));
	rotationMatrix = glm::rotate(rotationMatrix, rotation.x, glm::vec3(1.0f, 0.0f, 0.0f));
	rotationIsDirty = false;
}

void Transform::recalculateScaleMatrix()
{
	scaleMatrix = glm::scale(glm::mat4(1.0f), scale);
	scaleIsDirty = false;
}

void Transform::recalculateTransformMatrix()
{
	if (positionIsDirty)
		recalculatePositionMatrix();
	if (rotationIsDirty)
		recalculateRotationMatrix();
	if (scaleIsDirty)
		recalculateScaleMatrix();

	transformMatrix = glm::mat4(1.0f);
	transformMatrix *= scaleMatrix;
	transformMatrix *= rotationMatrix;
	transformMatrix *= positionMatrix;
	transformIsDirty = false;
}

glm::mat4 Transform::getTransformMatrix()
{
	if (transformIsDirty)
		recalculateTransformMatrix();
	return transformMatrix;
}