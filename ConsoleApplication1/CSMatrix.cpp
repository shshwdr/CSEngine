#include "stdafx.h"
#include "CSMatrix.h"


CSMatrix::CSMatrix()
{
	for (int i = 0;i < 4;i++) {
		for (int j = 0;j < 4;j++) {
			value[i][j] = 0;
		}
	}
}


CSMatrix::CSMatrix(const float v[4][4]) {
	for (int i = 0;i < 4;i++) {
		for (int j = 0;j < 4;j++) {
			value[i][j] = v[i][j];
		}
	}
}

CSMatrix::~CSMatrix()
{
}

CSMatrix CSMatrix::operator + (const CSMatrix& right) const {
	CSMatrix m;
	for (int i = 0;i < 4;i++) {
		for (int j = 0;j < 4;j++) {
			m.value[i][j] = value[i][j] + right.value[i][j];
		}
	}
	return m;
}
CSMatrix CSMatrix::operator - (const CSMatrix& right) const {
	CSMatrix m;
	for (int i = 0;i < 4;i++) {
		for (int j = 0;j < 4;j++) {
			m.value[i][j] = value[i][j] - right.value[i][j];
		}
	}
	return m;
}
CSMatrix CSMatrix::operator * (const CSMatrix& right) const {
	CSMatrix m;
	for (int i = 0;i < 4;i++) {
		for (int j = 0;j < 4;j++) {
			for (int k = 0;k < 4;k++) {
				m.value[i][j] += value[i][k] * right.value[k][j];
			}
		}
	}
	return m;
}
CSMatrix CSMatrix::operator * (float k) const {
	CSMatrix m;
	for (int i = 0;i < 4;i++) {
		for (int j = 0;j < 4;j++) {
			m.value[i][j] = value[i][j] * k;
		}
	}
	return m;
}

void CSMatrix::Transpose() { 
	for (int i = 0;i < 4;i++) {
		for (int j = 0;j < 4;j++) {
			std::swap(value[i][j], value[j][i]);
		}
	}
}

std::ostream& operator<< (std::ostream& os, const CSMatrix& m) {
	for (int i = 0;i < 4;i++) {
		for (int j = 0;j < 4;j++) {
			os << "[" << m.value[i][j] << "] ";
		}
		os << std::endl;
	}
	return os;
}