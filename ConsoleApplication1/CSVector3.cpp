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
	CSVector3 res(x / v, y / v, z / v);
	return res;
}

void CSVector3::Normalize() {
	*this = *this / Magnitude();
}
float CSVector3::SquareMagnitude() {
	return Dot(*this, *this);
}
float CSVector3::Magnitude() {
	return sqrt(SquareMagnitude());
}

CSVector3 CSVector3::Normalize(CSVector3& v) {
	float a = v.SquareMagnitude();
	return v / v.Magnitude();
}
float CSVector3::Dot(const CSVector3& left, const CSVector3& right) {
	return left.x*right.x + left.y*right.y + left.z*right.z;
}
CSVector3 CSVector3::Cross(const CSVector3& left, const CSVector3& right) {
	CSVector3 res(left.y*right.z - left.z*right.y, left.z*right.x - left.x*right.z, left.x*right.y - left.y*right.x);
	return res;
}

inline CSVector3 CSVector3::Lerp(const CSVector3& left, const CSVector3& right, float t) {
	return left + (right - left)*t;
}

std::ostream& operator<<(std::ostream& os, const CSVector3& v) {
	os << "(" << v.x << ", " << v.y << ", " << v.z << ")" << std::endl;
	return os;
}