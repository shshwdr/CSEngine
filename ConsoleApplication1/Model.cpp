#include "stdafx.h"
#include "Model.h"
#include <fstream>
#include <sstream>
#include <string>
#include <assert.h>


void Model::load_texture(std::string filename, const char * suffix, TGAImage & image)
{
	std::string texfile(filename);
	size_t dot = texfile.find_last_of(".");
	if (dot != std::string::npos) {
		texfile = texfile.substr(0, dot) + std::string(suffix);
		bool loadSuccessfully = image.read_tga_file(texfile.c_str());
		assert(loadSuccessfully);
		//image.flip_vertically();
	}
}

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
		else if (!line.compare(0, 2, "vt")) {
			iss >> c >> c;//get rid of v and t
			Vector3 v;
			iss >> v.x;
			iss >> v.y;
			iss >> v.z;
			uv.push_back(v);
		}
		else if (!line.compare(0, 2, "vn")) {
			iss >> c >> c;
			Vector3 v;
			iss >> v.x;
			iss >> v.y;
			iss >> v.z;
			norms.push_back(v);
		}
		else if (!line.compare(0, 2, "f ")) {
			int fv,fvt,fvn;
			iss >> c;
			while (iss >> fv>>c>>fvt>>c>>fvn) {
				Vector3 v(fv-1, fvt-1, fvn-1);
				faces.push_back(v);
			}
		}
	}


	load_texture(filename, "_diffuse.tga", diffuseMap);
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

Vector3 Model::getVertice(int iface, int ipoint)
{
	
	Vector3 faceV = faces[iface * 3 + ipoint];
	Vector3 res(verts[faceV.x].x, verts[faceV.x].y, verts[faceV.x].z);
	return res;

}
