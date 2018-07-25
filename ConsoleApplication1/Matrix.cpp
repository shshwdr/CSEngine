#include "stdafx.h"
#include "Matrix.h"


Matrix::Matrix()
{
	for (int i = 0;i < 4;i++) {
		for (int j = 0;j < 4;j++) {
			value[i][j] = 0;
		}
	}
}


Matrix::Matrix(const float v[4][4]) {
	for (int i = 0;i < 4;i++) {
		for (int j = 0;j < 4;j++) {
			value[i][j] = v[i][j];
		}
	}
}

Matrix::~Matrix()
{
}

Matrix Matrix::operator + (const Matrix& right) const {
	Matrix m;
	for (int i = 0;i < 4;i++) {
		for (int j = 0;j < 4;j++) {
			m.value[i][j] = value[i][j] + right.value[i][j];
		}
	}
	return m;
}
Matrix Matrix::operator - (const Matrix& right) const {
	Matrix m;
	for (int i = 0;i < 4;i++) {
		for (int j = 0;j < 4;j++) {
			m.value[i][j] = value[i][j] - right.value[i][j];
		}
	}
	return m;
}
Matrix Matrix::operator * (const Matrix& right) const {
	Matrix m;
	for (int i = 0;i < 4;i++) {
		for (int j = 0;j < 4;j++) {
			for (int k = 0;k < 4;k++) {
				m.value[i][j] += value[i][k] * right.value[k][j];
			}
		}
	}
	return m;
}
Matrix Matrix::operator * (float k) const {
	Matrix m;
	for (int i = 0;i < 4;i++) {
		for (int j = 0;j < 4;j++) {
			m.value[i][j] = value[i][j] * k;
		}
	}
	return m;
}

void Matrix::Transpose() {
	for (int i = 0;i < 4;i++) {
		for (int j = 0;j < 4;j++) {
			std::swap(value[i][j], value[j][i]);
		}
	}
}

std::ostream& operator<< (std::ostream& os, const Matrix& m) {
	for (int i = 0;i < 4;i++) {
		for (int j = 0;j < 4;j++) {
			os << "[" << m.value[i][j] << "] ";
		}
		os << std::endl;
	}
	return os;
}