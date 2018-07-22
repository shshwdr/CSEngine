#include "stdafx.h"
#include "Texture.h"
#include <windows.h>


Texture::Texture()
{
	width = 512;
	height = 512;
}


Texture::~Texture()
{
}

void Texture::LoadTexture(const char* path) {
	HBITMAP bitmap;
	bitmap = (HBITMAP)LoadImage(NULL, path, IMAGE_BITMAP, width, height, LR_LOADFROMFILE);

	if (bitmap == NULL) {
		throw "load image error";
	}

	HDC hdc = CreateCompatibleDC(NULL);
	SelectObject(hdc, bitmap);
	for (int i = 0;i < width;i++) {
		for (int j = 0;j < height;j++) {
			COLORREF color = GetPixel(hdc, i, j);
			int r = color % 256;
			int g = (color >> 8) % 256;
			int b = (color >> 16) % 256;
			CSColor c((float)r / 255, (float)g / 255, (float)b / 255);
			textureData[i][j] = c;
		}
	}
}
CSColor Texture::Sample(float u, float v) {
	u = Clamp(0, 1, u);
	v = Clamp(0, 1, v);
	int intu = width * u;
	int intv = height * v;
	return textureData[intu][intv];
}
float Texture::Clamp(float min, float max, float value) {
	return max(min, min(value, max));
}