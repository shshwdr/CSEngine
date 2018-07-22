#pragma once
#include "CSColor.h"
class Texture
{
private:
	int width;
	int height;
	CSColor textureData[1024][1024];
public:
	Texture();
	~Texture();

	void LoadTexture(const char* path);
	CSColor Sample(float u, float v);
	float Clamp(float min, float max, float value);
};

