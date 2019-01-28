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
		//DrawElement(device);
	}
	else if (model) {
		DrawFaces(device);
	}
	else {
		//DrawArray(device);
	}
}

IShader::~IShader() {}

Matrix mvp;
struct Shader : public IShader {
	Model *model;

	Vertex v[3];
	//Matrix varying_uv;  // triangle uv coordinates, written by the vertex shader, read by the fragment shader
	//Matrix varying_tri; // triangle coordinates (clip coordinates), written by VS, read by FS
	//Matrix varying_nrm; // normal per vertex to be interpolated by FS
	//Matrix ndc_tri;     // triangle in normalized device coordinates

	virtual Vector3 vertex(int iface, int nthvert) {


		//v1.pos = v1.pos*mvp;
		//v2.pos = v2.pos*mvp;
		//v3.pos = v3.pos*mvp;
		//v1.norm = Vector3::Normalize(v1.norm*mvp);
		//v2.norm = Vector3::Normalize(v2.norm*mvp);
		//v3.norm = Vector3::Normalize(v3.norm*mvp);

		//get info of j-th vector on i-th face
		Vector3 v1 = model->getUV(iface, nthvert);
		Vector3 norm = model->getNorm(iface, nthvert);
		Vertex p1(model->getVertice(iface, nthvert)*mvp, Color::None(), v1.x, v1.y, Vector3::Normalize(model->getNorm(iface, nthvert)*mvp));
		v[nthvert] = p1;
		return v1;
		//varying_uv.set_col(nthvert, model->uv(iface, nthvert));
		//varying_nrm.set_col(nthvert, proj<3>((Projection*ModelView).invert_transpose()*embed<4>(model->normal(iface, nthvert), 0.f)));
		//Vec4f gl_Vertex = Projection * ModelView*embed<4>(model->vert(iface, nthvert));
		//varying_tri.set_col(nthvert, gl_Vertex);
		//ndc_tri.set_col(nthvert, proj<3>(gl_Vertex / gl_Vertex[3]));
		//return gl_Vertex;
	}

	virtual bool fragment(Vector3 bar, TGAColor &color) {
		color = TGAColor(1, 1, 1, 1);
		return false;
	}
};


void Mesh::DrawFaces(Device* device) {
	mvp = device->GetMVPMatrix();
	device->model = model;
	try {
		Shader shader;
		shader.model = model;
		for (int i = 0;i < model->faceCount() / 3;i += 1) {
			for (int j = 0;j < 3;j++) {
				//vertex shader
				shader.vertex(i, j);

			}
			//Vertex p2 = vertexBuffer[faceBuffer[i + 1].x];
			//Vertex p3 = vertexBuffer[faceBuffer[i + 2].x];

			device->DrawPrimitive(shader,shader.v);
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


