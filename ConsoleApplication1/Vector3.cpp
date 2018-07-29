#include "stdafx.h"
#include "Vector3.h"



Vector3::~Vector3()
{
}

Vector3 Vector3::operator + (const Vector3& right) const {
	Vector3 v(x + right.x, y + right.y, z + right.z);
	return v;
}
Vector3 Vector3::operator - (const Vector3& right) const {
	Vector3 v(x - right.x, y - right.y, z - right.z);
	return v;
}
Vector3 Vector3::operator * (float v) const {
	Vector3 res(x *v, y *v, z *v);
	return res;
}
Vector3 Vector3::operator / (float v) const {
	Vector3 res(x / v, y / v, z / v);
	return res;
}

Vector3 Vector3::operator * (const Matrix& m) const {
	float fx = x * m.value[0][0] + y * m.value[1][0] + z * m.value[2][0] + w * m.value[3][0];
	float fy = x * m.value[0][1] + y * m.value[1][1] + z * m.value[2][1] + w * m.value[3][1];
	float fz = x * m.value[0][2] + y * m.value[1][2] + z * m.value[2][2] + w * m.value[3][2];
	float fw = x * m.value[0][3] + y * m.value[1][3] + z * m.value[2][3] + w * m.value[3][3];
	return Vector3(fx, fy, fz, fw);
}

void Vector3::Normalize() {
	*this = *this / Magnitude();
}
float Vector3::SquareMagnitude() const {
	return Dot(*this, *this);
}
float Vector3::Magnitude() const {
	return sqrt(SquareMagnitude());
}

Vector3 Vector3::Normalize(const Vector3& v) {
	float a = v.SquareMagnitude();
	return v / v.Magnitude();
}
float Vector3::Dot(const Vector3& left, const Vector3& right) {
	return left.x*right.x + left.y*right.y + left.z*right.z;
}
Vector3 Vector3::Cross(const Vector3& left, const Vector3& right) {
	Vector3 res(left.y*right.z - left.z*right.y, left.z*right.x - left.x*right.z, left.x*right.y - left.y*right.x);
	return res;
}

inline Vector3 Vector3::Lerp(const Vector3& left, const Vector3& right, float t) {
	return left + (right - left)*t;
}

std::ostream& operator<<(std::ostream& os, const Vector3& v) {
	os << "(" << v.x << ", " << v.y << ", " << v.z << ")" << std::endl;
	return os;
}