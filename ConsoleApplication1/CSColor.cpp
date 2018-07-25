#include "stdafx.h"
#include "CSColor.h"

CSColor CSColor::operator+(const CSColor & right) const
{
	CSColor res(r + right.r, g + right.r, b + right.r, a + right.r);
	return res;
}

CSColor CSColor::operator-(const CSColor & right) const
{
	CSColor res(r - right.r, g - right.g, b - right.b, a - right.a);
	return res;
}

CSColor CSColor::operator*(float v) const
{
	CSColor res(r*v, g *v, b*v, a*v);
	return res;
}

const CSColor CSColor::Lerp(const CSColor & c1, const CSColor & c2, float t)
{

	return c1 + (c2 - c1)*t;
}

const CSColor CSColor::ColorRefToColor(COLORREF c)
{
	return CSColor((float)(c&0xFF)/255.0f, (float)((c & 0xFF00)>>8)/255.0f, (float)((c & 0xFF0000) >> 16) / 255.0f);
}

const COLORREF CSColor::ColorToColorRef(CSColor c)
{
	return RGB(255 * c.r, 255 * c.g, 255 * c.b);
}


