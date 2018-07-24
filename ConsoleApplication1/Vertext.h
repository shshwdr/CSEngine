#pragma once
#include "CSVector3.h"
#include "CSColor.h"
class Vertex
{
private:

public:
	CSVector3 pos;
	CSColor color;
	float u, v;
	Vertex();
	Vertex(const CSVector3& p, const CSColor& c, float fu, float fv) :pos(p), color(c), u(fu), v(fv) {};
	Vertex(const CSVector3& p) :pos(p), color(CSColor::None()), u(0), v(0) {};
	~Vertex();

	static float LerpFloat(float v1, float v2, float t) {
		return v1 + (v2 - v1)*t;
	}

	void LerpVertexData(const Vertex& left, const Vertex& right, float t);
};

