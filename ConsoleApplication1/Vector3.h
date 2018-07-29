#pragma once
#include <iostream>
#include "Matrix.h"
class Vector3
{
public:
	//w = 1 means vector is a point
	//w = 0 means vector is a vector, transform won't change vector
	float x, y, z, w;
	Vector3(float fx, float fy, float fz, float fw) :x(fx), y(fy), z(fz), w(fw) {}
	Vector3(float fx, float fy, float fz) :x(fx), y(fy), z(fz), w(1) {};
	Vector3():x(0), y(0), z(0), w(1) {};
	~Vector3();

	Vector3 operator + (const Vector3& right) const;
	Vector3 operator - (const Vector3& right) const;
	Vector3 operator * (float v) const;
	Vector3 operator / (float v) const;
	Vector3 operator * (const Matrix& m) const;

	void Normalize();

	float SquareMagnitude() const;
	float Magnitude() const;

	Vector3 static Normalize(const Vector3& v);
	// a*b = |a||b|cos(angle)  
	//a*b>0 => accute a*b=0 => right angle 
	//when b is normalized, a*b is length when a project on b
	float static Dot(const Vector3& left, const Vector3& right);
	//axb = |a||b|sin(angle)  
	//axa = 0
	Vector3 static Cross(const Vector3& left, const Vector3& right);
	inline Vector3 static Lerp(const Vector3& left, const Vector3& right, float t);

	friend std::ostream& operator<<(std::ostream& os, const Vector3& v);

};

