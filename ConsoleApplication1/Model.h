#pragma once
#include<vector>
#include "Vector3.h"
class Model
{
private:
	std::vector<Vector3> verts;
	std::vector<std::vector<int>> faces;
public:
	Model(const char* filename);
	~Model();
	int vertCount();
	int faceCount();
	//Vector3 vert(int i);
	//std::vector<int> face(int i);
};

