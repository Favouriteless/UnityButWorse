#pragma once

#include <glm/gtc/type_ptr.hpp>
#include <component/TransformComponent.h>

struct PositionComponent : TransformComponent {
public:
	glm::vec3 position;
};