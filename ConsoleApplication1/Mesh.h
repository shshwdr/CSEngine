#pragma once
#include "Vertext.h"
#include "Device.h"
#include <vector>
#include "Model.h"
class Mesh
{
private:
	std::vector<Vertex> vertexBuffer;
	std::vector<int> indexBuffer;
	Model *model;

	void DrawElement(Device* device);
	void DrawFaces(Device* device);
	void DrawArray(Device* device);

public:
	Mesh();
	~Mesh();
	static Mesh* CreateTriangle();
	static Mesh* CreatePlane();
	static Mesh* CreateCube();
	//TODO: sphere

	void AddVertexData(const Vector3& pos, float u, float v, const Color& color = Color::None());
	void AddVertexData(float px, float py, float pz, float u, float v, const Color& color = Color::None());

	static Mesh * CreateModel(const char * filename);

	void DrawMesh(Device* device);
};



