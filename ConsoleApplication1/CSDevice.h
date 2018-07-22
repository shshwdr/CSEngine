#pragma once
#include "stdafx.h"
#include <windows.h>

#include "CSColor.h"
#include "CSMatrix.h"
#include "CSVector3.h"

//https://blog.csdn.net/puppet_master/article/details/80317178
class CSDevice
{
private:
	int deviceWidth;
	int deviceHeight;
	HDC screenHDC;

	void DrawBottomFlatTriangle(int x0, int y0, int x1, int y1, int x2, int y2, CSColor c = CSColor::red());
	void DrawTopFlatTriangle(int x0, int y0, int x1, int y1, int x2, int y2, CSColor c = CSColor::red());

	CSMatrix GenRotateMatrixMatrixOnOneAxis(float angle, int i1, int i2);

public:
	CSDevice();
	~CSDevice();
	void InitDevice(HDC hdc, int screenWidtch, int screenHeight);
	void DrawLine(int x0, int y0, int x1, int y1, CSColor c);
	void DrawTriangle(int x0, int y0, int x1, int y1, int x2, int y2, CSColor c = CSColor::red());
	void DrawPixel(int x0, int y0, CSColor c);

	//mvp
	CSMatrix GenScaleMatrix(const CSVector3& v);
	CSMatrix GenRotateMatrix(const CSVector3& v);
	CSMatrix GenTranslateMatrix(const CSVector3& v);
	CSMatrix GenCameraMatrix(const CSVector3& eyePos, const CSVector3& lookPos, const CSVector3& upAxis = CSVector3(0, 1, 0));
	CSMatrix GenProjectionMatrix(float fov, float aspect, float nearPlane, float farPlane);
};