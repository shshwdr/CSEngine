#pragma once

#include <iostream>
class Matrix
{
public:
	float value[4][4];
	Matrix();
	Matrix(const float v[4][4]);
	~Matrix();
	Matrix operator + (const Matrix& right) const;
	Matrix operator - (const Matrix& right) const;
	Matrix operator * (const Matrix& right) const;
	Matrix operator * (float k) const;
	void Transpose();
	static const Matrix Identity() {
		float v[4][4] = { { 1,0,0,0 },{ 0,1,0,0 },{ 0,0,1,0 },{ 0,0,0,1 } };
		return Matrix(v);
	}
	friend std::ostream& operator<< (std::ostream& os, const Matrix& m);
};

