#include "stdafx.h"
#include <algorithm>
#include <assert.h>
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
void CSDevice::DrawLine(int x0, int y0, int x1, int y1, CSColor c = CSColor::red())
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
			DrawPixel(x0, y0,c);
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
			DrawPixel(x0, y0,c);
			y0 += stepy;
			errorValue += dx2;
			if (errorValue >= 0) {
				errorValue -= dy2;
				x0 += stepx;
			}
		}
	}
}
//anti clock wise, (x0,y0) is the top
void CSDevice::DrawBottomFlatTriangle(int x0, int y0, int x1, int y1, int x2, int y2, CSColor c) {
	for (int y = y0;y <= y1;y++) {
		int xl = (x1 - x0)*(y - y0) / (y1 - y0) + x0;
		int xr = (x2 - x0)*(y - y0) / (y2 - y0) + x0;
		DrawLine(xl, y, xr, y,c);
	}
}
//(x2,y2) is the bottom
void CSDevice::DrawTopFlatTriangle(int x0, int y0, int x1, int y1, int x2, int y2, CSColor c) {
	for (int y = y0;y <= y2;y++) {
		int xl = (x1 - x2)*(y - y2) / (y1 - y2) + x2;
		int xr = (x0 - x2)*(y - y2) / (y0 - y2) + x2;
		DrawLine(xl, y, xr, y,c);
	}
}

void CSDevice::DrawTriangle(int x0, int y0, int x1, int y1, int x2, int y2, CSColor c) {
	//sort three point based on y
	if (y0 > y2) {
		std::swap(x0, x2);
		std::swap(y0, y2);
	}
	if (y0 > y1) {
		std::swap(x0, x1);
		std::swap(y0, y1);
	}
	if (y1 > y2) {
		std::swap(x1, x2);
		std::swap(y1, y2);
	}
	assert(y0 <= y1);
	assert(y1 <= y2);
	if (y0 == y1) {
		DrawTopFlatTriangle(x0,y0,x1,y1,x2,y2,c);
	}
	else if (y1 == y2) {
		DrawBottomFlatTriangle(x0, y0, x1, y1, x2, y2, c);
	}
	else {
		int y3 = y1;
		//put y1 into line (x0,y0) to (x2,y2)
		int x3 = (x0 - x2)*(y3 - y2) / (y0 - y2) + x2;
		//sort x1 and x3, we want x1<x3, so 013 and 312 are the triangles we get
		if (x1 > x3) {
			std::swap(x1, x3);
			std::swap(y1, y3);
		}
		DrawBottomFlatTriangle(x0, y0, x1, y1, x3, y3, c);
		DrawTopFlatTriangle(x3, y3, x1, y1, x2, y2, c);
	}
}

inline void CSDevice::DrawPixel(int x, int y, CSColor c = CSColor::red())
{
	SetPixel(screenHDC, x, y, RGB(255 * c.r, 255 * c.g, 255 * c.b));
}