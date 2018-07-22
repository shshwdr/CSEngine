#pragma once
#include "CSVector3.h"
#include "CSColor.h"
class Vertext
{
private:
	CSVector3 pos;
	CSColor color;
	float u, v;
public:
	Vertext();
	Vertext(const CSVector3& p, const CSColor& c, float fu, float fv) :pos(p), color(c), u(fu), v(fv) {};
	~Vertext();

	static float LerpFloat(float v1, float v2, float t) {
		return v1 + (v2 - v1)*t;
	}
};

