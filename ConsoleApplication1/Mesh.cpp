#include "stdafx.h"
#include "Mesh.h"


Mesh::Mesh()
{
}


Mesh::~Mesh()
{
}


void Mesh::AddVertexData(const Vector3& pos, float u, float v, const Color& color) {
	Vertex p(pos, color, u, v);
	vertexBuffer.push_back(p);
}

void Mesh::AddVertexData(float px, float py, float pz, float u, float v, const Color& color) {
	AddVertexData(Vector3(px, py, pz), u, v, color);
}

Mesh* Mesh::CreateModel(const char * filename) {
	Model *model = new Model(filename);
	Mesh *mesh = new Mesh();
	////in obj file, actually face has all the info
	//for (int i = 0;i < model.faceCount();i++) {
	//	
	//}
	//for (Vector3 v : model.verts) {
	//	mesh->AddVertexData(v.x, v.y, v.z, 0, 0);
	//}
	mesh->model = model;
	return mesh;
}


Mesh* Mesh::CreateTriangle() {
	Mesh* mesh = new Mesh();
	mesh->AddVertexData(-1, -1, 0, 0, 0, Color(1, 0, 0));
	mesh->AddVertexData(1, -1, 0, 0, 1, Color(0, 1, 0));
	mesh->AddVertexData(0, 0, 0, 1, 1, Color(0, 0, 1));
	int indexArray[] = { 0,1,2 };
	std::vector<int> index(indexArray, indexArray + sizeof(indexArray) / sizeof(int));
	mesh->indexBuffer = index;
	return mesh;

}
Mesh* Mesh::CreatePlane() {
	Mesh* mesh = new Mesh();
	mesh->AddVertexData(-1, 1, 0, 0, 0, Color(1.0f, 0, 0, 1.0f));
	mesh->AddVertexData(1, 1, 0, 1, 0, Color(0, 1.0f, 0, 1.0f));
	mesh->AddVertexData(1, -1, 0, 1, 1, Color(0, 0, 1.0f, 1.0f));
	mesh->AddVertexData(-1, -1, 0, 0, 1, Color(1.0f, 0, 0, 1.0f));

	int indexArray[] = { 0, 1, 2, 0, 2, 3 };
	//数组直接转vector https://blog.csdn.net/sagittarius_warrior/article/details/54089242
	std::vector<int> index(indexArray, indexArray + sizeof(indexArray) / sizeof(int));
	mesh->indexBuffer = index;
	return mesh;
}

Mesh* Mesh::CreateCube()
{
	Mesh* mesh = new Mesh();
	mesh->AddVertexData(-1.0f, -1.0f, -1.0f, 0.0f, 0.0f);
	mesh->AddVertexData(1.0f, -1.0f, -1.0f, 1.0f, 0.0f);
	mesh->AddVertexData(1.0f, 1.0f, -1.0f, 1.0f, 1.0f);
	mesh->AddVertexData(1.0f, 1.0f, -1.0f, 1.0f, 1.0f);
	mesh->AddVertexData(-1.0f, 1.0f, -1.0f, 0.0f, 1.0f);
	mesh->AddVertexData(-1.0f, -1.0f, -1.0f, 0.0f, 0.0f);

	mesh->AddVertexData(-1.0f, -1.0f, 1.0f, 0.0f, 0.0f);
	mesh->AddVertexData(1.0f, -1.0f, 1.0f, 1.0f, 0.0f);
	mesh->AddVertexData(1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
	mesh->AddVertexData(1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
	mesh->AddVertexData(-1.0f, 1.0f, 1.0f, 0.0f, 1.0f);
	mesh->AddVertexData(-1.0f, -1.0f, 1.0f, 0.0f, 0.0f);

	mesh->AddVertexData(-1.0f, 1.0f, 1.0f, 1.0f, 0.0f);
	mesh->AddVertexData(-1.0f, 1.0f, -1.0f, 1.0f, 1.0f);
	mesh->AddVertexData(-1.0f, -1.0f, -1.0f, 0.0f, 1.0f);
	mesh->AddVertexData(-1.0f, -1.0f, -1.0f, 0.0f, 1.0f);
	mesh->AddVertexData(-1.0f, -1.0f, 1.0f, 0.0f, 0.0f);
	mesh->AddVertexData(-1.0f, 1.0f, 1.0f, 1.0f, 0.0f);

	mesh->AddVertexData(1.0f, 1.0f, 1.0f, 1.0f, 0.0f);
	mesh->AddVertexData(1.0f, 1.0f, -1.0f, 1.0f, 1.0f);
	mesh->AddVertexData(1.0f, -1.0f, -1.0f, 0.0f, 1.0f);
	mesh->AddVertexData(1.0f, -1.0f, -1.0f, 0.0f, 1.0f);
	mesh->AddVertexData(1.0f, -1.0f, 1.0f, 0.0f, 0.0f);
	mesh->AddVertexData(1.0f, 1.0f, 1.0f, 1.0f, 0.0f);

	mesh->AddVertexData(-1.0f, -1.0f, -1.0f, 0.0f, 1.0f);
	mesh->AddVertexData(1.0f, -1.0f, -1.0f, 1.0f, 1.0f);
	mesh->AddVertexData(1.0f, -1.0f, 1.0f, 1.0f, 0.0f);
	mesh->AddVertexData(1.0f, -1.0f, 1.0f, 1.0f, 0.0f);
	mesh->AddVertexData(-1.0f, -1.0f, 1.0f, 0.0f, 0.0f);
	mesh->AddVertexData(-1.0f, -1.0f, -1.0f, 0.0f, 1.0f);

	mesh->AddVertexData(-1.0f, 1.0f, -1.0f, 0.0f, 1.0f);
	mesh->AddVertexData(1.0f, 1.0f, -1.0f, 1.0f, 1.0f);
	mesh->AddVertexData(1.0f, 1.0f, 1.0f, 1.0f, 0.0f);
	mesh->AddVertexData(1.0f, 1.0f, 1.0f, 1.0f, 0.0f);
	mesh->AddVertexData(-1.0f, 1.0f, 1.0f, 0.0f, 0.0f);
	mesh->AddVertexData(-1.0f, 1.0f, -1.0f, 0.0f, 1.0f);
	return mesh;
}
void Mesh::DrawMesh(Device* device) {
	if (indexBuffer.size() > 0) {
		DrawElement(device);
	}
	else if (model) {
		DrawFaces(device);
	}
	else {
		DrawArray(device);
	}
}

void Mesh::DrawFaces(Device* device) {
	Matrix mvp = device->GetMVPMatrix();
	
	try {
		for (int i = 0;i < model->faceCount()/3;i += 1) {
			
			Vertex p1 ( model->getVertice(i, 0),Color::None(),0,0);
			Vertex p2(model->getVertice(i, 1), Color::None(), 0, 0);
			Vertex p3(model->getVertice(i, 2), Color::None(), 0, 0);
			//Vertex p2 = vertexBuffer[faceBuffer[i + 1].x];
			//Vertex p3 = vertexBuffer[faceBuffer[i + 2].x];

			device->DrawPrimitive(p1, p2, p3, mvp);
		}
	}
	catch (const std::exception& e) {
		std::cout << e.what();
	}
}

void Mesh::DrawElement(Device* device) {
	Matrix mvp = device->GetMVPMatrix();
	try {
		for (int i = 0;i < indexBuffer.size();i += 3) {
			
			Vertex p1 = vertexBuffer[indexBuffer[i]];
			Vertex p2 = vertexBuffer[indexBuffer[i + 1]];
			Vertex p3 = vertexBuffer[indexBuffer[i + 2]];

			device->DrawPrimitive(p1, p2, p3, mvp);
		}
	}
	catch (const std::exception& e) {
		std::cout << e.what();
	}
}
void Mesh::DrawArray(Device* device) {
	Matrix mvp = device->GetMVPMatrix();
	for (int i = 0; i < vertexBuffer.size(); i = i + 3)
	{
		Vertex p1 = vertexBuffer[i];
		Vertex p2 = vertexBuffer[i + 1];
		Vertex p3 = vertexBuffer[i + 2];
		device->DrawPrimitive(p1, p2, p3, mvp);
	}
}
