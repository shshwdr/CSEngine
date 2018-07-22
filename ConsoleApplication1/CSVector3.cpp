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

CSVector3 CSVector3::operator * (const CSMatrix& m) const {
	float fx = x * m.value[0][0] + y * m.value[1][0] + z * m.value[2][0] + w * m.value[3][0];
	float fy = x * m.value[0][1] + y * m.value[1][1] + z * m.value[2][1] + w * m.value[3][1];
	float fz = x * m.value[0][2] + y * m.value[1][2] + z * m.value[2][2] + w * m.value[3][2];
	float fw = x * m.value[0][3] + y * m.value[1][3] + z * m.value[2][3] + w * m.value[3][3];
	return CSVector3(fx,fy,fz,fw);
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