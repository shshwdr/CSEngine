#include "stdafx.h"
#include "Vertext.h"


Vertex::Vertex()
{
}


Vertex::~Vertex()
{
}

void Vertex::LerpVertexData(const Vertex & left, const Vertex & right, float t)
{
	pos.z = LerpFloat(left.pos.z, right.pos.z, t);
	color = Color::Lerp(left.color, right.color, t);
	u = LerpFloat(left.u, right.u, t);
	v = LerpFloat(left.v, right.v, t);
}
