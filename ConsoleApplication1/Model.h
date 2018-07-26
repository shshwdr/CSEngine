#pragma once
#include<vector>
#include "Vector3.h"
class Model
{
private:
	
public:
	std::vector<Vector3> verts;
	std::vector<int> faces;
	Model(const char* filename);
	~Model();
	int vertCount();
	int faceCount();
	//Vector3 vert(int i);
	//std::vector<int> face(int i);
};

