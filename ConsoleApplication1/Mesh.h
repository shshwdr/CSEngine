#pragma once
#include "Vertext.h"
#include "CSDevice.h"
#include <vector>
class Mesh
{
private:
	std::vector<Vertex> vertexBuffer;
	std::vector<int> indexBuffer;

	void DrawElement(CSDevice* device);
	void DrawArray(CSDevice* device);

public:
	Mesh();
	~Mesh();
	static Mesh* CreateTriangle();
	static Mesh* CreatePlane();
	static Mesh* CreateCube();
	//TODO: sphere

	void AddVertexData(const CSVector3& pos, float u, float v, const CSColor& color = CSColor::red());
	void AddVertexData(float px, float py, float pz, float u, float v, const CSColor& color = CSColor::red());

	void DrawMesh(CSDevice* device);
};

