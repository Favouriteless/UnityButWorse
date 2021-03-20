#ifndef MESH_H
#define MESH_H

#include "Texture.h"
#include "Transform.h"
#include <vector>

class Mesh {
public:
	Mesh(float vertices[], int indices[]);
	void addTransform(Transform& transform);
	void removeTransform(Transform& transform);
private:
	std::vector<float> vertices;
	std::vector<int> indices;
	std::vector<Transform&> transforms;

	Texture& texture;
};

#endif