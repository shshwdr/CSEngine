#pragma once

struct CSColor
{
public:
	float r, g, b, a;
	constexpr CSColor(float cr, float cg, float cb, float ca) : r(cr), g(cg), b(cb), a(ca) {}
	~CSColor() {}

	static const CSColor red() { return CSColor(1, 0, 0, 0); }
};

