#pragma once
#include <Windows.h>
struct Color
{
public:
	float r, g, b, a;
	constexpr Color(float cr, float cg, float cb, float ca=1) : r(cr), g(cg), b(cb), a(ca) {}
	Color() {};
	~Color() {}


	Color operator +(const Color& right)const;
	Color operator -(const Color& right)const;
	Color operator *(float v)const;

	static const Color red() { return Color(1, 0, 0, 1); }
	static const Color None() { return Color(0, 0, 0, 0); }
	static const Color Lerp(const Color& c1, const Color& c2, float t);
	static const Color ColorRefToColor(COLORREF colorRef);
	static const COLORREF ColorToColorRef(Color colorRef);
};

