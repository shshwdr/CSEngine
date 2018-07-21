#pragma once
#include <iostream>
class CSVector3
{
public:
	float x, y, z, w;
	CSVector3(float fx, float fy, float fz) :x(fx), y(fy), z(fz) {}
	~CSVector3();

	CSVector3 operator + (const CSVector3& right) const;
	CSVector3 operator - (const CSVector3& right) const;
	CSVector3 operator * (float v) const;
	CSVector3 operator / (float v) const;

	friend std::ostream& operator<<(std::ostream& os, const CSVector3& v);

};

