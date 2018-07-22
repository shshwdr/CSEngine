#include "stdafx.h"
#include <algorithm>
#include <assert.h>
#include "CSDevice.h"
#include "CSMathUtil.h"


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
	int dx2 = dx << 1;
	int dy2 = dy << 1;
	float errorValue = 0;
	if (dx > dy) {
		errorValue = -dx;
		for (int i = 0;i <= dx;i++) {
			DrawPixel(x0, y0, c);
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
			DrawPixel(x0, y0, c);
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
		DrawLine(xl, y, xr, y, c);
	}
}
//(x2,y2) is the bottom
void CSDevice::DrawTopFlatTriangle(int x0, int y0, int x1, int y1, int x2, int y2, CSColor c) {
	for (int y = y0;y <= y2;y++) {
		int xl = (x1 - x2)*(y - y2) / (y1 - y2) + x2;
		int xr = (x0 - x2)*(y - y2) / (y0 - y2) + x2;
		DrawLine(xl, y, xr, y, c);
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
		DrawTopFlatTriangle(x0, y0, x1, y1, x2, y2, c);
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

//MVP
//1.world = modeal*SRT
CSMatrix CSDevice::GenScaleMatrix(const CSVector3& v) {
	CSMatrix m = CSMatrix::Identity();
	m.value[0][0] = v.x;
	m.value[1][1] = v.y;
	m.value[2][2] = v.z;
	return m;
}
//http://www.cnblogs.com/luweimy/p/4121789.html#3743809
//x' = r*cos(a+b) = cos(a)x-sin(a)*y
//y' = r*sin(a+b) = sin(a)x+cos(a)*y
// [ cos(a)  sin(a)]  rotations matrix
// [-sin(a)  cos(a)]
CSMatrix CSDevice::GenRotateMatrix(const CSVector3& v) {
	CSMatrix rotX = GenRotateMatrixMatrixOnOneAxis(v.x, 1, 2);
	CSMatrix rotY = GenRotateMatrixMatrixOnOneAxis(v.y, 2, 0);
	CSMatrix rotZ = GenRotateMatrixMatrixOnOneAxis(v.z, 0, 1);
	return rotX * rotY*rotZ;
}

//when rotate on x, wont change x, but put rotation matrix on y and z, same as other two
//pass i1 and i2 as index for the axis that need to change.
CSMatrix CSDevice::GenRotateMatrixMatrixOnOneAxis(float angle, int i1, int i2) {
	CSMatrix m = CSMatrix::Identity();
	float cosValue = cos(angle);
	float sinValue = sin(angle);
	m.value[i1][i1] = cosValue;
	m.value[i1][i2] = sinValue;
	m.value[i2][i1] = -sinValue;
	m.value[i2][i2] = cosValue;
	return m;
}

CSMatrix CSDevice::GenTranslateMatrix(const CSVector3& v) {
	CSMatrix m = CSMatrix::Identity();
	m.value[3][0] = v.x;
	m.value[3][1] = v.y;
	m.value[3][2] = v.z;
	return m;
}

//2.world to camera
//define camera's rotation in two ways: 1.define raw, pitch, roll(rotation for axis x,y,z)
//										2.UVN, U 's initial value is (0,1,0)
// use the second one to define LookAt easier
//transfrom on a point means do T^-1 on its coordinate system
//WTC^-1 = (RT)^-1 = (T^-1)(R^-1)
//T^-1: change x,y,z to reverse value
//R^-1: R is a othogonal matrix, so M*M^T = I  so M^T=M^-1
CSMatrix CSDevice::GenCameraMatrix(const CSVector3& eyePos, const CSVector3& lookPos, const CSVector3& upAxis) {
	//use left hand. thumb is N(look dir,z), index finger is Up, miggle finger is right.
	//when do cross multiply, use right hand's fingers go from thumb to index finger, thumb is the dir
	CSVector3 N = lookPos - eyePos;
	N.Normalize();
	CSVector3 V = CSVector3::Cross(upAxis, N);
	V.Normalize();
	CSVector3 U = CSVector3::Cross(N, V);
	U.Normalize();
	float transX = -CSVector3::Dot(V, eyePos);
	float transY = -CSVector3::Dot(U, eyePos);
	float transZ = -CSVector3::Dot(N, eyePos);
	CSMatrix m;
	m.value[0][0] = V.x; m.value[0][1] = U.x;m.value[0][2] = N.x;
	m.value[1][0] = V.y; m.value[1][1] = U.y;m.value[1][2] = N.y;
	m.value[2][0] = V.z; m.value[2][1] = U.z;m.value[2][2] = N.z;
	m.value[3][0] = transX; m.value[3][1] = transX;m.value[3][2] = transX;m.value[3][3] = 1;
	return m;
}
//return NDC(normalized device coordinates) for different resolution
//x, y projected to (-1,1), z projected to (0,1) (in opengl it is (-1,1)
//when project between N and F, z' is inproportion to 1/z, so (az+b)/z
//put N and F into it, a = F/(F-N) b = NF/(N-F), so m[2][2][ = a, m[3][2] = b
//x'/x  = z'/z x = Nx/Z  
//project from [L,R] to [-1,1], x' = 2*NX/(Z*W), so m[0][0] = 2*N/W  w is the width of screen
//H/2 = tan(0.5*fov) * N m[1][1] = 1/tan(0.5fov)
//W = H*Aspect m[0][0] = 1/(tan(0.5fov)*Aspect)  aspect = screenW/screenH
//fov is pass in as degree
CSMatrix CSDevice::GenProjectionMatrix(float fov, float aspect, float nearPlane, float farPlane) {
	float tanValue = tan(CSMathUtil::DegToArc(0.5*fov));
	CSMatrix m;
	m.value[0][0] = 1.0f / (tanValue * aspect);
	m.value[1][1] = 1.0f / (tanValue);
	m.value[2][2] = farPlane / (farPlane - nearPlane);
	m.value[3][2] = -nearPlane * farPlane / (farPlane - nearPlane);
	m.value[2][3] = 1;
	return m;
}