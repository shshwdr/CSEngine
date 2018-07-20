#include "stdafx.h"

#include "CSDevice.h"


CSDevice::CSDevice() {}
CSDevice::~CSDevice() {}
void CSDevice::InitDevice(HDC hdc, int screenWidtch, int screenHeight) {
	screenHDC = hdc;
}

void CSDevice::DrawLine(int x0, int y0, int x1, int y1)
{
	//Bresenham
	//slope = dy/dx
	int dx = x1 - x0;
	int dy = y1 - y0;
	float errorValue = 0;
	for (int x = x0, y = y0;x <= x1;x++) {
		DrawPixel(x, y);
		errorValue += (float)dy / dx;
		if (errorValue > 0.5) {
			errorValue -= 1;
			y++;
		}
	}
}

inline void CSDevice::DrawPixel(int x, int y)
{
	SetPixel(screenHDC, x, y, RGB(255, 0, 0));
}