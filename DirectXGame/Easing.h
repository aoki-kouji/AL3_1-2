#pragma once
#include <cmath>
#include <numbers>

class Easing {
public:

	//===============線形補間====================//

	static float Liner(float startPos, float endPos, float easedT) {
		return (1.0f - easedT) * startPos + easedT * endPos;
	}

	static float EaseOut(float x) {
		return sinf((x * std::numbers::pi_v<float>) / 2.0f);
	}

	static float EaseIn(float x) {
		return 1.0f - cosf((x * std::numbers::pi_v<float>) / 2.0f);
	}

	static float EaseInOut(float x) {
		return -(cosf(std::numbers::pi_v<float> * x) - 1.0f) / 2.0f;
	}

	//================角度補間===================//



};