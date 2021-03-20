#include "Transform.h"



Transform::Transform(glm::vec3 _position, float _rotation, glm::vec3 _scale)
{
	setPosition(_position);
	setRotation(_rotation);
	setScale(_scale);
}

glm::vec3 Transform::getPosition()
{
	return position;
}

float Transform::getRotation()
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
	isDirty = true;
}

void Transform::setRotation(float _rotation)
{
	rotation = _rotation;
	recalculateRotationMatrix();
}

void Transform::setScale(glm::vec3 _scale)
{
	scale = _scale;
	isDirty = true;
}

void Transform::translate(glm::vec3 _offset)
{
	setPosition(position + _offset);
}

void Transform::recalculatePositionMatrix()
{
	positionMatrix = glm::translate(glm::mat4(1.0f), position);
	isDirty = true;
}

void Transform::recalculateRotationMatrix()
{
	rotationMatrix = glm::rotate(glm::mat4(1.0f), rotation, glm::vec3(0.0f, 0.0f, 1.0f));
	isDirty = true;
}

void Transform::recalculateScaleMatrix()
{
	scaleMatrix = glm::scale(glm::mat4(1.0f), scale);
	isDirty = true;
}

void Transform::recalculateTransformMatrix()
{
	transformMatrix = glm::mat4(1.0f);
	transformMatrix *= scaleMatrix;
	transformMatrix *= rotationMatrix;
	transformMatrix *= positionMatrix;
}

glm::mat4 Transform::getTransformMatrix()
{
	if (isDirty)
		recalculateTransformMatrix();
	return transformMatrix;
}