#pragma once
#include "stdafx.h"
#include <windows.h>

#include "Color.h"
#include "Matrix.h"
#include "Vector3.h"
#include "Texture.h"
#include "Vertext.h"
#include "Model.h"

//https://blog.csdn.net/puppet_master/article/details/80317178
class Device
{
private:
	int deviceWidth;
	int deviceHeight;
	HDC screenHDC;
	Texture *tex;
	float** zBuffer;
#pragma region outdated draw
	void DrawBottomFlatTriangle(int x0, int y0, int x1, int y1, int x2, int y2, Color c = Color::red());
	void DrawTopFlatTriangle(int x0, int y0, int x1, int y1, int x2, int y2, Color c = Color::red());
	void DrawLine(int x0, int y0, int x1, int y1, Color c);
	void DrawTriangle(int x0, int y0, int x1, int y1, int x2, int y2, Color c = Color::red());
	void DrawTrangle3D(const Vector3& v1, const Vector3& v2, const Vector3& v3, const Matrix& mvp);
#pragma endregion

	void DrawLine(Vertex v0, Vertex v1);

	bool ZTestAndWrite(int x, int y, float depth);

	void DrawTopFlatTriangle(Vertex v0, Vertex v1, Vertex v2);

	void DrawBottomFlatTriangle(Vertex v0, Vertex v1, Vertex v2);

	void RasterizeTriangle(Vertex v0, Vertex v1, Vertex v2);

	Matrix GenRotateMatrixMatrixOnOneAxis(float angle, int i1, int i2);

public:
	Device();
	~Device();

	//temp
	Model *model;
	void InitDevice(HDC hdc, int screenWidtch, int screenHeight);
	void Clear();
	void DrawPixel(int x0, int y0, Color c);

	//mvp
	Matrix GenScaleMatrix(const Vector3& v);
	Matrix GenRotateMatrix(const Vector3& v);
	Matrix GenTranslateMatrix(const Vector3& v);
	Matrix GenCameraMatrix(const Vector3& eyePos, const Vector3& lookPos, const Vector3& upAxis = Vector3(0, 1, 0));
	Matrix GenProjectionMatrix(float fov, float aspect, float nearPlane, float farPlane);
	void changeRotation(bool isAdding);
	Vector3 GetScreenCoord(const Vector3& v);
	Matrix GetMVPMatrix();
	void DrawPrimitive(Vertex v1, Vertex v2, Vertex v3, const Matrix & mvp);
	void PrepareRasterization(Vertex & vertex);
	//inline bool SimpleCVVCullCheck(const Vertex& vertex) { return true; }
};