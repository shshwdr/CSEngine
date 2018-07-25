#pragma once
#include "Vertext.h"
#include "Device.h"
#include <vector>
class Mesh
{
private:
	std::vector<Vertex> vertexBuffer;
	std::vector<int> indexBuffer;

	void DrawElement(Device* device);
	void DrawArray(Device* device);

public:
	Mesh();
	~Mesh();
	static Mesh* CreateTriangle();
	static Mesh* CreatePlane();
	static Mesh* CreateCube();
	//TODO: sphere

	void AddVertexData(const Vector3& pos, float u, float v, const Color& color = Color::red());
	void AddVertexData(float px, float py, float pz, float u, float v, const Color& color = Color::red());

	void DrawMesh(Device* device);
};

