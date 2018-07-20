#include "stdafx.h"

#include "CSDevice.h"


CSDevice::CSDevice() {}
CSDevice::~CSDevice() {}
void CSDevice::InitDevice(HDC hdc, int screenWidtch, int screenHeight) {
	screenHDC = hdc;
}

//void CSDevice::DrawLine_outdated(int x0, int y0, int x1, int y1)
//{
//	//Bresenham with division
//	//slope = dy/dx
//	int dx = x1 - x0;
//	int dy = y1 - y0;
//	float errorValue = 0;
//	for (int x = x0, y = y0;x <= x1;x++) {
//		DrawPixel(x, y);
//		errorValue += (float)dy / dx;
//		if (errorValue > 0.5) {
//			errorValue -= 1;
//			y++;
//		}
//	}
//}


////https://zhuanlan.zhihu.com/p/20213658
void CSDevice::DrawLine(int x0, int y0, int x1, int y1)
{
	//Bresenham with division
	//e = old_e - 0.5  we only need to check e > 0
	//e *= dx so we can do e+=dy and e-=dx, then e = -0.5*dx
	//then we do d *=2 so e = -dx, e+=2dy,e-=2dx
	int dx = x1 - x0;
	int dy = y1 - y0;
	int stepx = 1;
	int stepy = 1;
	if (dx < 0) {
		stepx = -1;
		dx = -dx;
	}
	if (dy < 0) {
		stepy = -1;
		dy = -dy;
	}
	int dx2 = dx<<1;
	int dy2 = dy<<1;
	float errorValue = 0;
	if (dx > dy) {
		errorValue =  - dx;
		for (int i = 0;i <= dx;i++) {
			DrawPixel(x0, y0);
			x0 += stepx;
			errorValue += dy2;
			if (errorValue >= 0) {
				errorValue -= dx2;
				y0 += stepy;
			}
		}
	}
	else {
		errorValue = -dy;
		for (int i = 0;i <= dy;i++) {
			DrawPixel(x0, y0);
			y0 += stepy;
			errorValue += dx2;
			if (errorValue >= 0) {
				errorValue -= dy2;
				x0 += stepx;
			}
		}
	}
}


inline void CSDevice::DrawPixel(int x, int y)
{
	SetPixel(screenHDC, x, y, RGB(255, 0, 0));
}