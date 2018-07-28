#pragma once
#include<vector>
#include "Vector3.h"
#include "TGAImage.h"
class Model
{
private:
	void load_texture(std::string filename, const char* suffix, TGAImage &image);
public:
	std::vector<Vector3> verts;
	std::vector<Vector3> uv;//TODO: vector 2 is enough
	std::vector<Vector3> norms;
	TGAImage diffuseMap;
	//vector3 contains vertex,uv and norm index
	std::vector<Vector3> faces;//TODO: vector3 int is enough


	Model(const char* filename);
	~Model();
	int vertCount();
	int faceCount();
	//Vector3 vert(int i);
	//std::vector<int> face(int i);
	//Vector3 uv(int iface, int nvert);
	Vector3 getVertice(int iface, int ipoint);
};

