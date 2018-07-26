#include "stdafx.h"
#include "Color.h"

Color Color::operator+(const Color & right) const
{
	Color res(r + right.r, g + right.g, b + right.b, a + right.a);
	return res;
}

Color Color::operator-(const Color & right) const
{
	Color res(r - right.r, g - right.g, b - right.b, a - right.a);
	return res;
}

Color Color::operator*(float v) const
{
	Color res(r*v, g *v, b*v, a*v);
	return res;
}

const Color Color::Lerp(const Color & c1, const Color & c2, float t)
{

	return c1 + (c2 - c1)*t;
}

const Color Color::ColorRefToColor(COLORREF c)
{
	return Color((float)(c&0xFF)/255.0f, (float)((c & 0xFF00)>>8)/255.0f, (float)((c & 0xFF0000) >> 16) / 255.0f);
}

const COLORREF Color::ColorToColorRef(Color c)
{
	return RGB(255 * c.r, 255 * c.g, 255 * c.b);
}


