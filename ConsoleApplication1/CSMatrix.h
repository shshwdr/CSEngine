#pragma once

#include <iostream>
class CSMatrix
{
public:
	float value[4][4];
	CSMatrix();
	CSMatrix(const float v[4][4]);
	~CSMatrix();
	CSMatrix operator + (const CSMatrix& right) const;
	CSMatrix operator - (const CSMatrix& right) const;
	CSMatrix operator * (const CSMatrix& right) const;
	CSMatrix operator * (float k) const;
	void Transpose();
	static const CSMatrix Identity() {
		float v[4][4] = { { 1,0,0,0 },{ 0,1,0,0 },{ 0,0,1,0 },{ 0,0,0,1 } };
		return CSMatrix(v);
	}
	friend std::ostream& operator<< (std::ostream& os, const CSMatrix& m);
};

