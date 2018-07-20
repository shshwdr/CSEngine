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

public:
	CSDevice();
	~CSDevice();
	void InitDevice(HDC hdc, int screenWidtch, int screenHeight);
	void DrawLine(int x0, int y0, int x1, int y1, CSColor c);
	void DrawPixel(int x0, int y0, CSColor c);
};