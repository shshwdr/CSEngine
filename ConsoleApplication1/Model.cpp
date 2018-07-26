#include "stdafx.h"
#include "Model.h"
#include <fstream>
#include <sstream>
#include <string>


Model::Model(const char* filename) {
	std::ifstream in;
	in.open(filename, std::ifstream::in);
	if (in.fail()) {
		throw("file load fail");
		return;
	}
	std::string line;
	while (!in.eof()) {
		std::getline(in, line);
		std::istringstream iss(line.c_str());
		char c;
		if (!line.compare(0, 2, "v ")) { //compare, when has value means they are different..
			iss >> c;
			Vector3 v;
			iss >> v.x;
			iss >> v.y;
			iss >> v.z;
			verts.push_back(v);
		}
		else if (!line.compare(0, 2, "f ")) {
			int fv,fvt,fvn;
			iss >> c;
			while (iss >> fv>>c>>fvt>>c>>fvn) {
				fv--;
				faces.push_back(fv);
			}

		}
	}

}


Model::~Model()
{
}

int Model::vertCount()
{
	return verts.size();
}

int Model::faceCount()
{
	return faces.size();
}
