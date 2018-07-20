// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<windows.h>

#include "CSDevice.h"

static const int windowWidth = 600;
static const int windowHeight = 450;
static const LPCTSTR title = (LPCTSTR)"CS's playground";
HDC hdc = NULL;
HDC screenHDC = NULL;
CSDevice* device = NULL;

void Update();
void DoRender();
void InitWindow();
void InitDevice();


static LRESULT OnEvent(HWND, UINT, WPARAM, LPARAM);

int main()
{
	FreeConsole();
	InitWindow();
	InitDevice();
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
	device = new CSDevice();
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
	SetWindowPos(windowHandle, NULL, 300, 200, windowWidth, windowHeight, (SWP_NOCOPYBITS | SWP_NOZORDER | SWP_SHOWWINDOW));
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

	SetWindowPos(windowHandle, NULL, 300, 200, windowWidth, windowHeight, (SWP_NOCOPYBITS | SWP_NOZORDER | SWP_SHOWWINDOW));
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
			DoRender();
			//ShowFPS();
		}
	}
}

void DoRender()
{
	device->DrawLine(0, 0, 100, 100);
	BitBlt(hdc, 0, 0, windowWidth, windowHeight, screenHDC, 0, 0, SRCCOPY);
}
