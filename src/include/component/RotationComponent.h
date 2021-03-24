#pragma once

#include <glm/gtc/type_ptr.hpp>
#include <component/TransformComponent.h>

struct RotationComponent : TransformComponent {
public:
	glm::vec3 rotation;
};