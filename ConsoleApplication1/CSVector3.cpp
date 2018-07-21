#include "stdafx.h"
#include "CSVector3.h"



CSVector3::~CSVector3()
{
}

CSVector3 CSVector3::operator + (const CSVector3& right) const {
	CSVector3 v(x + right.x, y + right.y, z + right.z);
	return v;
}
CSVector3 CSVector3::operator - (const CSVector3& right) const {
	CSVector3 v(x - right.x, y - right.y, z - right.z);
	return v;
}
CSVector3 CSVector3::operator * (float v) const {
	CSVector3 res(x *v, y *v, z *v);
	return res;
}
CSVector3 CSVector3::operator / (float v) const {
	CSVector3 res(x /v, y /v, z /v);
	return res;
}

std::ostream& operator<<(std::ostream& os, const CSVector3& v) {
	os <<"("<<v.x<<", "<<v.y<<", "<<v.z<<")"<< std::endl;
	return os;
}