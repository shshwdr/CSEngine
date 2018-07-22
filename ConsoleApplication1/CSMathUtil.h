#pragma once
class CSMathUtil
{
public:

	CSMathUtil();
	~CSMathUtil();
	static constexpr float  PI_F = 3.14159265358979f;
	inline static float DegToArc(float degree) {
		return degree * PI_F / 180;
	}
	inline static float ArcToDeg(float degree) {
		return degree * 180 / PI_F;
	}
};

