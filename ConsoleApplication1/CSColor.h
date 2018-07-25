#pragma once
#include <Windows.h>
struct CSColor
{
public:
	float r, g, b, a;
	constexpr CSColor(float cr, float cg, float cb, float ca=1) : r(cr), g(cg), b(cb), a(ca) {}
	CSColor() {};
	~CSColor() {}


	CSColor operator +(const CSColor& right)const;
	CSColor operator -(const CSColor& right)const;
	CSColor operator *(float v)const;

	static const CSColor red() { return CSColor(1, 0, 0, 1); }
	static const CSColor None() { return CSColor(0, 0, 0, 0); }
	static const CSColor Lerp(const CSColor& c1, const CSColor& c2, float t);
	static const CSColor ColorRefToColor(COLORREF colorRef);
	static const COLORREF ColorToColorRef(CSColor colorRef);
};

