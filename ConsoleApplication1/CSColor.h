#pragma once

struct CSColor
{
public:
	float r, g, b, a;
	constexpr CSColor(float cr, float cg, float cb, float ca=1) : r(cr), g(cg), b(cb), a(ca) {}
	CSColor() {};
	~CSColor() {}

	static const CSColor red() { return CSColor(1, 0, 0, 0); }
};

