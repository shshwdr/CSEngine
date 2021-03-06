// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <windows.h>


#include "Device.h"
#include "Matrix.h"
#include "Vector3.h"
#include "Mesh.h"
#include "Model.h"


static const int windowWidth = 600;
static const int windowHeight = 450;
static const LPCTSTR title = (LPCTSTR)"CS's playground";
HDC hdc = NULL;
HDC screenHDC = NULL;
Device* device = NULL;

Mesh* currentMesh = NULL;
Model* model = NULL;

void Update();
void DoRender();
void InitWindow();
void InitDevice();
void InitRes();
void ShowFPS();


static LRESULT OnEvent(HWND, UINT, WPARAM, LPARAM);

int main()
{
	//FreeConsole();
	InitWindow();
	InitDevice();
	InitRes();
	Update();
	return 0;
}
LRESULT OnEvent(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	}
	return DefWindowProc(hwnd, msg, wParam, lParam);
}

void InitDevice() {
	device = new Device();
	device->InitDevice(screenHDC, windowWidth, windowHeight);
}

void InitWindow() {
	WNDCLASS windowClass = { CS_BYTEALIGNCLIENT, (WNDPROC)OnEvent, 0, 0, 0, NULL, NULL, NULL, NULL, title };
	if (!RegisterClass(&windowClass))
		MessageBox(NULL, (LPCTSTR)"Could not register class", (LPCTSTR)"Error", MB_OK);
	HWND windowHandle = CreateWindow(title,
		title,
		WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX,
		0,
		0,
		GetSystemMetrics(SM_CXSCREEN),
		GetSystemMetrics(SM_CYSCREEN),
		NULL,
		NULL,
		NULL,
		NULL);
	SetWindowPos(windowHandle, NULL, 0, 0, windowWidth, windowHeight, (SWP_NOCOPYBITS | SWP_NOZORDER | SWP_SHOWWINDOW));
	ShowWindow(windowHandle, SW_NORMAL);
	hdc = GetDC((windowHandle));
	screenHDC = CreateCompatibleDC(hdc);
	BITMAPINFO bitmapInfo = { { sizeof(BITMAPINFOHEADER),windowWidth, windowHeight, 1, 32, BI_RGB, windowWidth * windowHeight * 4, 0, 0, 0, 0 } };
	LPVOID ptr;
	//创建设备无关的位图
	HBITMAP bitmapHandler = CreateDIBSection(screenHDC, &bitmapInfo, DIB_RGB_COLORS, &ptr, 0, 0);
	if (bitmapHandler == NULL)
		return;

	HBITMAP screenObject = (HBITMAP)SelectObject(screenHDC, bitmapHandler);
	ShowWindow(windowHandle, SW_NORMAL);
	UpdateWindow(windowHandle);
}

void Update()
{
	MSG msg = { 0 };
	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			if ((GetKeyState(VK_LBUTTON) & 0x100) != 0) {
				device->changeRotation(true);
			}
			else if ((GetKeyState(VK_RBUTTON) & 0x100)!=0) {
				device->changeRotation(false);
			}
			DoRender();
			ShowFPS();
		}
	}
}
using namespace std;
void DoRender()
{
	device->Clear();
	//device->DrawLine(0, 0, windowWidth, windowHeight, CSColor(1, 0, 0, 1));
	//device->DrawLine(windowWidth, 0, 0, windowHeight, CSColor(0, 1, 0, 1));
	//device->DrawBottomFlatTriangle(100, 0, 0, 100, 200, 100);
	//device->DrawTriangle(0,0,200,0,100,100);
	//device->DrawTriangle(100, 0, 0, 100, 200, 200);
	//device->DrawTriangle(300, 0, 400, 100, 500, 50);
	//CSMatrix m = CSMatrix::Identity();
	//CSMatrix n = CSMatrix::Identity();
	//cout << m << m + n << m - n << endl;

	//CSVector3 v(1, 2, 3);
	//CSVector3 u(2, 4, 6);
	//cout << v << u << u - v << endl;


	//CSVector3 v1(0, 1, 0);
	//CSVector3 v2(-1, -1, 0);
	//CSVector3 v3(1, -1, 0);
	//CSMatrix mvp = device->GetMVPMatrix();
	//device->DrawTrangle3D(v1, v2, v3, mvp);
	//todo: some below comments are not work, clean them
	currentMesh->DrawMesh(device);

	BitBlt(hdc, 0, 0, windowWidth, windowHeight, screenHDC, 0, 0, SRCCOPY);
}

void ShowFPS() {
	static float fps = 0;
	static int frameCount = 0;
	static float currentTime = 0.0f;
	static float lastTime = 0.0f;
	frameCount++;
	currentTime = timeGetTime()*0.001f;
	if (currentTime - lastTime > 1.0f) {
		fps = (float)frameCount / (currentTime - lastTime);
		lastTime = currentTime;
		frameCount = 0;
	}
	char strBuffer[20];
	sprintf_s(strBuffer, 20, "fps: %0.3f", fps);
	TextOut(hdc, 0, 0, strBuffer, 10);
}

void InitRes() {
	currentMesh = Mesh::CreateModel("african_head.obj");
	//currentMesh = Mesh::CreatePlane();
	//will crash now
}