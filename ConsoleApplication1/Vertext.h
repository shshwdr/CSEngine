#pragma once
#include "Vector3.h"
#include "Color.h"
class Vertex
{
private:

public:
	Vector3 pos;
	Color color;
	float u, v;
	Vector3 norm;
	float intense;
	Vertex();
	Vertex(const Vector3& p, const Color& c, float fu, float fv, Vector3 n = Vector3(),float inten = 1) :pos(p), color(c), u(fu), v(fv) ,norm(n),intense(inten){};
	Vertex(const Vector3& p) :pos(p), color(Color::None()), u(0), v(0) {};
	~Vertex();

	static float LerpFloat(float v1, float v2, float t) {
		return v1 + (v2 - v1)*t;
	}

	void LerpVertexData(const Vertex& left, const Vertex& right, float t);
};

