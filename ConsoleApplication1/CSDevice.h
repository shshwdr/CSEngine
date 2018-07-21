#pragma once
#include "stdafx.h"
#include <windows.h>

#include "CSColor.h"

class CSDevice
{
private:
	int deviceWidth;
	int deviceHeight;
	HDC screenHDC;

	void DrawBottomFlatTriangle(int x0, int y0, int x1, int y1, int x2, int y2, CSColor c = CSColor::red());
	void DrawTopFlatTriangle(int x0, int y0, int x1, int y1, int x2, int y2, CSColor c = CSColor::red());

public:
	CSDevice();
	~CSDevice();
	void InitDevice(HDC hdc, int screenWidtch, int screenHeight);
	void DrawLine(int x0, int y0, int x1, int y1, CSColor c);
	void DrawTriangle(int x0, int y0, int x1, int y1, int x2, int y2, CSColor c = CSColor::red());
	void DrawPixel(int x0, int y0, CSColor c);

	//mvp
	//CSMatrix GenScaleMatrix(const CSVector3& v);
};