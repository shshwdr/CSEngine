#pragma once
#include <iostream>
class CSVector3
{
public:
	//w = 1 means vector is a point
	//w = 0 means vector is a vector, transform won't change vector
	float x, y, z, w;
	CSVector3(float fx, float fy, float fz) :x(fx), y(fy), z(fz) {}
	~CSVector3();

	CSVector3 operator + (const CSVector3& right) const;
	CSVector3 operator - (const CSVector3& right) const;
	CSVector3 operator * (float v) const;
	CSVector3 operator / (float v) const;

	void Normalize();

	float SquareMagnitude();
	float Magnitude();

	CSVector3 static Normalize(CSVector3& v);
	float static Dot(const CSVector3& left, const CSVector3& right);
	CSVector3 static Cross(const CSVector3& left, const CSVector3& right);
	inline CSVector3 static Lerp(const CSVector3& left, const CSVector3& right, float t);

	friend std::ostream& operator<<(std::ostream& os, const CSVector3& v);

};

