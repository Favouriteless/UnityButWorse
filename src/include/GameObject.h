#pragma once

#include <Transform.h>
#include <vector>
#include <Component.h>

class GameObject {
public:
	Transform transform;

	template <typename T>
	T getComponent();
	template <typename T>
	void addComponent(T component);
private:
	std::vector<Component> components;
};
