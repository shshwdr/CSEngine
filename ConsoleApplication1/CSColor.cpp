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
