#pragma once

#include <memory>

class GameObject;

class Component {
public:
	std::weak_ptr<GameObject> parent;

	void Update();

	Component(GameObject parent);
private:
};