#pragma once
#include "stdafx.h"
#include <windows.h>

#include "CSColor.h"
#include "CSMatrix.h"
#include "CSVector3.h"
#include "Texture.h"
#include "Vertext.h"

//https://blog.csdn.net/puppet_master/article/details/80317178
class CSDevice
{
private:
	int deviceWidth;
	int deviceHeight;
	HDC screenHDC;
	Texture *tex;

#pragma region outdated draw
	void DrawBottomFlatTriangle(int x0, int y0, int x1, int y1, int x2, int y2, CSColor c = CSColor::red());
	void DrawTopFlatTriangle(int x0, int y0, int x1, int y1, int x2, int y2, CSColor c = CSColor::red());
	void DrawLine(int x0, int y0, int x1, int y1, CSColor c);
	void DrawTriangle(int x0, int y0, int x1, int y1, int x2, int y2, CSColor c = CSColor::red());
	void DrawTrangle3D(const CSVector3& v1, const CSVector3& v2, const CSVector3& v3, const CSMatrix& mvp);
#pragma endregion

	void DrawLine(Vertex v0, Vertex v1);

	void DrawTopFlatTriangle(Vertex v0, Vertex v1, Vertex v2);

	void DrawBottomFlatTriangle(Vertex v0, Vertex v1, Vertex v2);

	void RasterizeTriangle(Vertex v0, Vertex v1, Vertex v2);

	CSMatrix GenRotateMatrixMatrixOnOneAxis(float angle, int i1, int i2);

public:
	CSDevice();
	~CSDevice();
	void InitDevice(HDC hdc, int screenWidtch, int screenHeight);
	void Clear();
	void DrawPixel(int x0, int y0, CSColor c);

	//mvp
	CSMatrix GenScaleMatrix(const CSVector3& v);
	CSMatrix GenRotateMatrix(const CSVector3& v);
	CSMatrix GenTranslateMatrix(const CSVector3& v);
	CSMatrix GenCameraMatrix(const CSVector3& eyePos, const CSVector3& lookPos, const CSVector3& upAxis = CSVector3(0, 1, 0));
	CSMatrix GenProjectionMatrix(float fov, float aspect, float nearPlane, float farPlane);
	CSVector3 GetScreenCoord(const CSVector3& v);
	CSMatrix GetMVPMatrix();
	void DrawPrimitive(Vertex v1, Vertex v2, Vertex v3, const CSMatrix & mvp);
	void PrepareRasterization(Vertex & vertex);
	//inline bool SimpleCVVCullCheck(const Vertex& vertex) { return true; }
};